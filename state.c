#include "state.h"
#include <stdio.h>
#define READ_INTERVAL 60;  //Time between sensor readings

typedef enum    {
    INIT,
    IDLE,
    JOIN,
    JOIN_ACCEPT,        
    GET_DATA,
    TRANSMIT,
    RECEIVE,
    SLEEP,
    RESET
} STATE;

static STATE currState = INIT;
static STATE nextState = IDLE;


char* state_str[] = {"INIT", "IDLE", "JOIN", "JOIN_ACCEPT", "GET_DATA", "TRANSMIT", "RECEIVE", "SLEEP", "RESET"};
bool nextStateFlag = false;

volatile uint16_t secs = 0;
uint8_t numTx = 0;

//LR2 payload for TTN - String of hex characters representing sensor data
char payload[13];

//Data structure: measurements from Weather Click and moisture sensor
static sensor_data_t data;  


ISR(TCB0_INT_vect)
{
    if (PORTC.IN & PIN4_bm)
    {
        BUTTON_releaseCallback();
    }
    else
    {
        BUTTON_pressCallback();
    }

    TCB0.INTFLAGS = TCB_CAPT_bm;
}

ISR(RTC_PIT_vect)   {
    secs++;
    
    RTC.PITINTFLAGS |= RTC_PI_bm;
}


void BUTTON_releaseCallback(void)
{
    //PORTB.OUTSET |= PIN7_bm;
    
    //Set the Next State Flag
    setNextStateFlag();
}

void BUTTON_pressCallback(void)
{
    //PORTB.OUTCLR |= PIN7_bm;   
}



void setNextStateFlag(void)
{
    nextStateFlag = true;
}

void clearNextStateFlag(void)
{
    nextStateFlag = false;
}

bool getNextStateFlag(void)
{
    return nextStateFlag;
}

STATE getState()
{
    return currState;
}

void setState(STATE newState)
{
    currState = newState;
}

void advanceState()
{
    currState++;
}

void stateRESET()
{
    currState = INIT;
}

void stateInfo()   
{
    //Print Current State
    printf("\n\rEntering %s state\n\r", state_str[currState]);
}

void stateINIT() 
{
    //Initialize the Weather Click
    WeatherClick_initialize();
    
    setNextStateFlag();
}

void stateJOIN()
{
    //Initialize the LR2
    LR2_reset();
    
    //Configure the LR2
    LR2_config();
    
    //Send Join Request
    LR2_join();
    
    //TODO: Check if Join Accepted
    setNextStateFlag();
}

void stateGET_DATA()
{
    //Gather and format sensor data for transmission
    getSensorData(&data);
    formatPayload(payload, &data);
    setNextStateFlag();
}

void stateTRANSMIT()
{
    //Transmit the Sensor Data to the Server as a Confirmed Uplink
    if(numTx == 0) {
        printf("numTx: %d\n", numTx);
        LR2_tx(payload);
        numTx++;
        setNextStateFlag();
    }
    else {
        printf("numTx: %d\n", numTx);
        LR2_tx_uncnf(payload);
        numTx++;
        if(numTx == 10) {
            numTx = 0;
        }
        setNextStateFlag();
    }
    

}

void stateRECEIVE()
{
    if(secs == 180) {
        setNextStateFlag();
        //Stop the timer
        RTC.CTRLA &= ~RTC_RTCEN_bm;
    }
    //Debugging: Provide Terminal Access to RN2903
    sendAndReceiveBuffers();
}

void stateMachine()
{    
        //Advance to Next State
        if(nextStateFlag)  {
            clearNextStateFlag();
            currState = nextState;
            //stateInfo();          //Print state for debugging
            if(currState == RECEIVE)   {
                USB_sendStringRaw("\rRx: ");
                //Restart the Timer
                secs = 0;
                RTC.CTRLA |= RTC_RTCEN_bm;
            }
        }
        
        //State Machine Routines
        switch(currState)  {
            case INIT:
                stateINIT();
                nextState = IDLE;
                break;
            case IDLE:
                nextState = JOIN;
                
            case JOIN:
                stateJOIN();
                nextState = JOIN_ACCEPT;
                break;
            case JOIN_ACCEPT:
                nextState = GET_DATA;
                secs = 0;
                break;
            case GET_DATA:
                //TODO: Store data every minute, enlarge payload array for 3 mins worth of data
                stateGET_DATA();
                nextState = TRANSMIT;
                break;
            case TRANSMIT:
                nextState = RECEIVE;
                stateTRANSMIT();
                break;
            case RECEIVE:
                nextState = GET_DATA;
                stateRECEIVE();
                break;
            case SLEEP:
                break;
            default:
                break;
        }
}







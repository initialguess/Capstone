 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "state.h"

#define TOP_VALUE 0xFFFF
#define SECSLEEP   60       // Length of time between measurements
/*
    Main application
*/

//LR2 payload for TTN - String of hex characters representing sensor data
char payload[13];

//Data structure: measurements from Weather Click and moisture sensor
static sensor_data_t data;   

void PORT_init(void);
void EVSYS_init(void);
void TCB0_init(void);
void Init_PIT(void);
    
int main(void)
{
    
    //Initialize the ATtiny1627
    SYSTEM_Initialize();
    
    //Baremetal Setup for State Machine
    PORT_init();
    EVSYS_init();
    TCB0_init();
    Init_PIT();
    
    sei();
    
    //Enable the Rx and Tx for Print Utility
    PrintUtility_enable();

    //Initialize TWI Host Driver
    TWI_initHost();

    while(1)
    {
        
        stateMachine();
        //
        //sendAndReceiveBuffers();
        
        //Go to Sleep
        asm ("SLEEP");
        asm ("NOP");
    }
}

void PORT_init(void)
{
    //Set Up LED
    PORTB.DIR |= PIN7_bm;
    PORTB.OUT |= PIN7_bm;
    
    //Set Up Switch 0
    PORTC.DIR &= ~(PIN4_bm);
    PORTC.PIN4CTRL |= PORT_PULLUPEN_bm;
}

void EVSYS_init(void)
{
    EVSYS.CHANNEL3 = EVSYS_CHANNEL3_PORTC_PIN4_gc;
    EVSYS.USERTCB0CAPT = EVSYS_USER_CHANNEL3_gc;
}

void TCB0_init(void)
{
    TCB0.CCMP = TOP_VALUE;              //In single shot so CCMP stores TOP 
    TCB0.CTRLB = TCB_CNTMODE_SINGLE_gc;
    TCB0.EVCTRL = TCB_CAPTEI_bm | TCB_EDGE_bm;  // Input capture event, 
    TCB0.CTRLA = TCB_CLKSEL_0_bm | TCB_ENABLE_bm;   // CLK_PER and TCB Enable
    TCB0.CNT = TOP_VALUE;
    TCB0.INTCTRL = TCB_CAPT_bm; //Capture Interrupt Enable
}

void Init_PIT(void) {
/*  1. Configure the RTC clock CLK_RTC as described in section 23.4.1.1. Configure the Clock CLK_RTC.
    2. Enable the interrupt by writing a ?1? to the Periodic Interrupt (PI) bit in the PIT Interrupt Control
    (RTC.PITINTCTRL) register.
    3. Select the period for the interrupt by writing the desired value to the Period (PERIOD) bit field in the Periodic
    Interrupt Timer Control A (RTC.PITCTRLA) register.
    4. Enable the PIT by writing a ?1? to the Periodic Interrupt Timer Enable (PITEN) bit in the RTC.PITCTRLA
    register.
 * */
    RTC.CLKSEL = RTC_CLKSEL_INT1K_gc;//RTC_CLKSEL_INT32K_gc;
    RTC.PITINTCTRL = RTC_PI_bm;
    while(RTC.PITSTATUS & RTC_CTRLBUSY_bm); //wait until not busy to write
    RTC.PITCTRLA = RTC_PERIOD_CYC1024_gc | RTC_PITEN_bm; //RTC_PERIOD_CYC32768_gc | RTC_PITEN_bm;
    
}
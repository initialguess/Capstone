/*
 * File:   weather_application.c
 * Author: C16783
 *
 * Created on May 18, 2020, 2:39 PM
 */

#include "mcc_generated_files/system/system.h"
#include <util/delay.h>
#include "application.h"

/**
  Section: Variable Definitions
 */

#define DEFAULT_STANDBY_TIME    BME280_STANDBY_HALFMS
#define DEFAULT_FILTER_COEFF    BME280_FILTER_COEFF_OFF
#define DEFAULT_TEMP_OSRS       BME280_OVERSAMP_X1
#define DEFAULT_PRESS_OSRS      BME280_OVERSAMP_X1
#define DEFAULT_HUM_OSRS        BME280_OVERSAMP_X1
#define DEFAULT_SENSOR_MODE     BME280_FORCED_MODE

bool weather_initialized = 0;
bool label_initial = false;

/**
  Section: Driver APIs
 */

void WeatherClick_initialize(void) {
    BME280_reset();
    _delay_ms(50);
    BME280_readFactoryCalibrationParams();
    BME280_config(BME280_STANDBY_HALFMS, BME280_FILTER_COEFF_OFF);
    BME280_ctrl_meas(BME280_OVERSAMP_X1, BME280_OVERSAMP_X1, BME280_FORCED_MODE);
    BME280_ctrl_hum(BME280_OVERSAMP_X1);
    BME280_initializeSensor();
    weather_initialized = 1;
}

void PrintUtility_enable(void) {
    TERM_ReceiveEnable();
    TERM_TransmitEnable();
}

void LR2_reset(void) {
#ifdef DEBUG
    USB_sendStringRaw("\rResetting LR2 Click\n");
    USB_sendStringRaw("----------------------------------------------------\n");
    USB_sendStringRaw("Firmware: ");
#endif
    
    /* Reset the RN2903 */
    LR2_RST_SetHigh();
    _delay_ms(100);         
    LR2_RST_SetLow();
    _delay_ms(300);
    LR2_RST_SetHigh();
    _delay_ms(100);         
    LR2_RTS_SetHigh();
    
    uint8_t done = 0;
    char data;
    
    while(!done)
    {   
        if(LR2__IsRxReady()) {
            TERM_tx_buff_Push(LR2_Read());
        }
        //if(TERM_tx_buff_Count() && TERM_IsTxReady()) {
        if(TERM_IsTxReady()) {
            data = TERM_tx_buff_Pop();
            TERM_sendByte(data);
            if(data== '\n') {
                done = 1;
            }
        } 
    }
    _delay_ms(1000);
}

void LR2_sendStringCmd(char *str)
{
    //Print Command to the Terminal for Debug Purposes
    USB_sendStringRaw("\r\nTx: ");
    USB_sendStringRaw(str);
    
    //Add the string to the LR2 Buffer
    LR2_tx_buff_Push_Str(str);
    
    //Transmit over the LR2 UART
    for (uint8_t i = 0; str[i] != '\0'; )
    {
        if (LR2_IsTxReady())
        {
            LR2_Write(LR2_tx_buff_Pop());
            i++;
        }
    }
    //while(!TERM_IsTxReady());
    _delay_ms(100);
}

void LR2_sendAppSKey(char *str) 
{
    //Print Command to the Terminal for Debug Purposes
    //USB_sendStringRaw("\r\n");
    USB_sendStringRaw("\r\nTx: mac set appskey\r\n");
    
    LR2_tx_buff_Push_Str(str);
    
    _delay_ms(100);
    
    //Transmit over the LR2 UART
    for (uint8_t i = 0; str[i] != '\0'; )
    {
        if (LR2_IsTxReady())
        {
            LR2_Write(LR2_tx_buff_Pop());
            i++;
        }
    }
    _delay_ms(100);
}

void LR2_sendNwkSKey(char *str) 
{
    //Print Command to the Terminal for Debug Purposes
    USB_sendStringRaw("\r\nTx: mac set nwkskey\r\n");
    
    LR2_tx_buff_Push_Str(str);
    
    _delay_ms(100);
    
    //Transmit over the LR2 UART
    for (uint8_t i = 0; str[i] != '\0'; )
    {
        if (LR2_IsTxReady())
        {
            LR2_Write(LR2_tx_buff_Pop());
            i++;
        }
    }
}

void LR2_recvRsp()
{
    uint8_t done = 0;

    USB_sendStringRaw("\rRx: ");
    LR2_RTS_SetHigh();
    while(!done)
    {   
        if(LR2__IsRxReady()) {
            TERM_tx_buff_Push(LR2_Read());
        }
        if(TERM_tx_buff_Count() && TERM_IsTxReady()) {
            char data = TERM_tx_buff_Pop();
           TERM_Write(data);
            if(data== '\n') {
                done = 1;
            }
        }   
    }
    LR2_RTS_SetLow();
    //_delay_ms(100);
}
// Receive 2 responses for mac join and mac tx
void LR2_recvRsp2()
{
    uint8_t done = 0;

    USB_sendStringRaw("Rx: ");
    
    while(!done)
    {   
        if(LR2__IsRxReady()) {
            TERM_tx_buff_Push(LR2_Read());
        }
        if(TERM_tx_buff_Count() && TERM_IsTxReady()) {
            char data = TERM_tx_buff_Pop();
            TERM_Write(data);
            if(data== '\n') {
                done = 1;
            }
        }   
    }
}

void LR2_config_abp()
{
    USB_sendStringRaw("\n\nConfiguring LR2 Click For ABP\n");
    USB_sendStringRaw("-----------------------------------------------------------------------\n");
    LR2_sendStringCmd("mac set deveui " DEVEUI "\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac set devaddr " DEVADDR "\r\n");
    LR2_recvRsp();
    LR2_sendAppSKey("mac set appskey " APPSKEY "\r\n");
    LR2_recvRsp();
    LR2_sendNwkSKey("mac set nwkskey " NWKSKEY "\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac set ar on\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac set rxdelay1 5000\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac set adr on\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac save\r\n");
    LR2_recvRsp();
    USB_sendStringRaw("\n\n");
    _delay_ms(100);
}
void LR2_config_otaa()
{
    USB_sendStringRaw("\n\nConfiguring LR2 Click for OTAA\n");
    USB_sendStringRaw("-----------------------------------------------------------------------\n");
    LR2_sendStringCmd("mac set deveui " DEVEUI "\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac set appkey " APPKEY "\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac set appeui " APPEUI "\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac set ar on\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac set rxdelay1 5000\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac set adr on\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac save\r\n");
    LR2_recvRsp();
    LR2_sendStringCmd("mac pause\r\n");
    LR2_recvRsp();
    _delay_ms(100);
    LR2_sendStringCmd("mac resume\r\n");
    LR2_recvRsp();
    USB_sendStringRaw("\n\n");
    _delay_ms(100);
}

void LR2_join_abp() 
{
#ifdef DEBUG
    USB_sendStringRaw("\n\nJoining TTN\n");
    USB_sendStringRaw("-----------------------------------------------------------------------\n");
#endif
    LR2_sendStringCmd("mac join abp\r\n");
    LR2_recvRsp();
    
}

void LR2_join_otaa() 
{
#ifdef DEBUG
    USB_sendStringRaw("\n\nJoining TTN\n");
    USB_sendStringRaw("-----------------------------------------------------------------------\n");
#endif
    LR2_sendStringCmd("mac join otaa\r\n");
    LR2_recvRsp2();
    
    _delay_ms(1000);
}

void LR2_config() 
{
    //Prepare LR2 for Tx/Rx according to activation procedure (ABP or OTAA))
#ifdef ABP
    //Set DEVEUI, DEVADDR, Session Keys, Auto Reply and Receive Window
    LR2_config_abp();
#endif

#ifdef OTAA
    //Set DEVEUI,DEVADDR, APPKEY, APPEUI, Auto Reply and Receive Window (5 sec)
    LR2_config_otaa();
#endif
}

void LR2_join()
{
#ifdef ABP
    //Join TTN using Activation By Personalization
    LR2_join_abp();
#endif

#ifdef OTAA
    //Join TTN using Over the Air Activation
    LR2_join_otaa();
#endif
}

void WeatherClick_readSensors(void) {
    if (DEFAULT_SENSOR_MODE == BME280_FORCED_MODE) {
        BME280_startForcedSensing();
    }
    BME280_readMeasurements();
}

//Get 100 raw values from soil moisture sensor for calibration
void printRawValues() {
    uint8_t count = 0;
    uint16_t val;
    uint16_t min = ADC0_GetConversion(7);
    uint16_t max = min;
    
    printf("\nAfter 100 Moisture Readings\n");
    printf("-----------------------------------------------------------------------\n");
    while(count < 100) {
        val = ADC0_GetConversion(7);
        if(val < min && val != 0){
            min = val;
        }
        if(val > max) {
            max = val;
        }    
        //printf("%d\n",val);
        count++;
    }
    printf("The MAX reading was %d\n", max);
    printf("The MIN reading was %d\n\n", min);
    
    printf("The MAX maps to %d\n", map(max));
    printf("The MIN maps to %d\n", map(min));
}

uint8_t map(uint16_t raw) {    
    float val;
    
    // Account for random sporadic outlier values well out of range
    if(raw > IN_MAX) {
        raw = IN_MAX;
    }
    if(raw < IN_MIN) {
        raw = IN_MIN;
    }
    
    val = (raw - IN_MIN) * CONVERSION_PERCENT;

    return 100 - (uint8_t) val;
}

uint8_t getMoistureMeasurement() {
    uint16_t val = ADC0_GetConversion(7);
    return map(val);    
}

//Gets Data from the Weather Click and Soil Moisture Sensor
void getSensorData(sensor_data_t *data)
{
    WeatherClick_readSensors();

    data->temp = (int8_t) BME280_getTemperature();
    data->press = BME280_getPressure();
    data->humid = (uint8_t) BME280_getHumidity();
    data->moist = getMoistureMeasurement(); 
    
#ifdef DEBUG
    printSensorData(data); //To compare and demonstrate successful transmission
#endif
    
}
/*
 * For Debug Purposes, prints retrieved data
 */
void printSensorData(sensor_data_t *data)
{
    USB_sendStringRaw("\n\nCurrent Sensor Data\n");
    USB_sendStringRaw("-----------------------------------------------------------------------\n");
    
    printf("Relative Humidity: %u%% \r\n", data->humid);
    printf("Moisture: %u%% \r\n", data->moist);
    printf("Pressure: %u hPa\r\n", data->press);
    printf("Temperature: %i C \r\n\n", data->temp);
    
    printf("\nJSON Format\r\n");
    printf("-----------------------------------------------------------------------\n");
    printf("Payload: { humidity: %u, moisture: %u, pressure: %u, temperature: %i }\r\n\n", data->humid, data->moist, data->press, data->temp);
    
}

/**
 * Converts Measurements to a Hex String for LoRa Transmission
 * Temperature, Humidity and Moisture only require 2 hex chars, pressure 
 * requires 4 chars, RN2903 payload string is terminated with "\r\n\0"
 */ 
void formatPayload(char *str, sensor_data_t *data) {
        
    char hex[]= "0123456789ABCDEF";
    
    str[0] = hex[((data->temp >> 4) & 0x0F)];
    str[1] = hex[data->temp & 0x0F];
    str[2] = hex[((data->humid >> 4) & 0x0F)];
    str[3] = hex[data->humid & 0x0F];
    str[4] = hex[((data->moist >> 4) & 0x0F)];
    str[5] = hex[data->moist & 0x0F];
    str[6] = hex[((data->press >> 12) & 0x0F)];
    str[7] = hex[((data->press >> 8) & 0x0F)];
    str[8] = hex[((data->press >> 4) & 0x0F)];
    str[9] = hex[data->press & 0x0F];
    str[10] = '\r';
    str[11] = '\n';
    str[12] = '\0';
}
//Transmits a formatted payload string on port 1 using confirmed uplink
void LR2_tx(char *str) {
#ifdef DEBUG
    USB_sendStringRaw("\n\nTransmitting Data\n");
    USB_sendStringRaw("----------------------------------------------------\n");
    //Prints Command and Payload on Terminal for debugging
    USB_sendStringRaw("\nTx: mac tx cnf 42 ");
    USB_sendStringRaw(str);
#endif
    
    //Send Transmission to LR2 UART Tx
    LR2_tx_buff_Push_Str("mac tx cnf 42 ");
    LR2_tx_buff_Push_Str(str);
}

//Transmits a formatted payload string on port 1 using unconfirmed uplink
void LR2_tx_uncnf(char *str) {
#ifdef DEBUG
    USB_sendStringRaw("\n\nTransmitting Data\n");
    USB_sendStringRaw("----------------------------------------------------\n");
    //Prints Command and Payload on Terminal for debugging
    USB_sendStringRaw("\nTx: mac tx uncnf 43 ");
    USB_sendStringRaw(str);
#endif
    
    //Send Transmission to LR2 UART Tx
    LR2_tx_buff_Push_Str("mac tx uncnf 43 ");
    LR2_tx_buff_Push_Str(str);
}
void sendAndReceiveBuffers() {
        if(TERM__IsRxReady()) {
            LR2_tx_buff_Push(TERM_Read());
        }    
        if(LR2__IsRxReady()) {
            TERM_tx_buff_Push(LR2_Read());
        }
        if(TERM_tx_buff_Count() && TERM_IsTxReady()) {
            TERM_Write(TERM_tx_buff_Pop());
        }
        if(LR2_tx_buff_Count() && LR2_IsTxReady()) {
            LR2_Write(LR2_tx_buff_Pop());
        }
}



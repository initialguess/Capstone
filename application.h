/* 
 * File:   application.h
 * Author: C16783
 *
 * Created on May 18, 2020, 2:40 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "mcc_generated_files/system/system.h"
#include "bme280.h"
#include "TWI.h"    
#include "lr2.h"
#include "LR2_tx_buff.h"
#include "TERM_tx_buff.h"
#include "printUtility.h"

#define CONVERSION_PERCENT 0.0625
#define IN_MAX 2791 //3064          
#define IN_MIN 1191 //1190
    
//Enable print statements for Rx and Tx
#define DEBUG
    
//Enable Activation by Personalization
#define ABP

//Enable Over the Air Activation
//#define OTAA
    
    typedef struct
    {
        int8_t temp;         // Temperature        Weather Click
        uint16_t press;      // Pressure           Weather Click 
        uint8_t humid;       // Humidity           Weather Click 
        uint8_t moist;       // Soil Moisture      ADCC 
    } sensor_data_t;
    
    void WeatherClick_initialize(void);
    void PrintUtility_enable(void);
    void LR2_reset(void);
    void LR2_sendStringCmd(char *);
    void LR2_sendAppSKey(char *);
    void LR2_sendNwkSKey(char *);
    void LR2_recvRsp(void);
    void LR2_recvRsp2(void);
    void LR2_config_abp(void);
    void LR2_config_otaa(void);
    void LR2_join_abp(void);
    void LR2_join_otaa(void);
    void LR2_config(void);
    void LR2_join(void);
    void WeatherClick_readSensors(void);
    void printRawValues(void);
    uint8_t map(uint16_t raw);
    uint8_t getMoistureMeasurement();
    void getSensorData(sensor_data_t *);
    void printSensorData(sensor_data_t *);
    void formatPayload(char *, sensor_data_t *);
    void LR2_tx(char *);
    void LR2_tx_uncnf(char *);
    void sendAndReceiveBuffers();
    

#ifdef	__cplusplus
}
#endif

#endif	/* APPLICATION_H */


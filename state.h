/* 
 * File:   state.h
 *
 * Created on July 17, 2022, 2:41 PM
 */

#ifndef STATE_H
#define	STATE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <xc.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "application.h"
    

void BUTTON_releaseCallback(void);
void BUTTON_pressCallback(void);  
void setNextStateFlag(void);
void clearNextStateFlag(void);
bool getNextStateFlag(void);
uint8_t getState();
void setState(uint8_t newState);
void advanceState();
void stateRESET();
void stateInfo();
void stateJOIN();
void stateGET_DATA();
void stateTRANSMIT();
void stateMachine();

#ifdef	__cplusplus
}
#endif

#endif	/* STATE_H */
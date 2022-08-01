/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  1.0.1
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

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "./port.h"

//get/set IO_PA7 aliases
#define IO_PA7_SetHigh() do { PORTA_OUTSET = 0x80; } while(0)
#define IO_PA7_SetLow() do { PORTA_OUTCLR = 0x80; } while(0)
#define IO_PA7_Toggle() do { PORTA_OUTTGL = 0x80; } while(0)
#define IO_PA7_GetValue() (VPORTA.IN & (0x1 << 7))
#define IO_PA7_SetDigitalInput() do { PORTA_DIRCLR = 0x80; } while(0)
#define IO_PA7_SetDigitalOutput() do { PORTA_DIRSET = 0x80; } while(0)
#define IO_PA7_SetPullUp() do { PORTA_PIN7CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PA7_ResetPullUp() do { PORTA_PIN7CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PA7_SetInverted() do { PORTA_PIN7CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PA7_ResetInverted() do { PORTA_PIN7CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PA7_DisableInterruptOnChange() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PA7_EnableInterruptForBothEdges() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PA7_EnableInterruptForRisingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PA7_EnableInterruptForFallingEdge() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PA7_DisableDigitalInputBuffer() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PA7_EnableInterruptForLowLevelSensing() do { PORTA.PIN7CTRL = (PORTA.PIN7CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PA2 aliases
#define IO_PA2_SetHigh() do { PORTA_OUTSET = 0x4; } while(0)
#define IO_PA2_SetLow() do { PORTA_OUTCLR = 0x4; } while(0)
#define IO_PA2_Toggle() do { PORTA_OUTTGL = 0x4; } while(0)
#define IO_PA2_GetValue() (VPORTA.IN & (0x1 << 2))
#define IO_PA2_SetDigitalInput() do { PORTA_DIRCLR = 0x4; } while(0)
#define IO_PA2_SetDigitalOutput() do { PORTA_DIRSET = 0x4; } while(0)
#define IO_PA2_SetPullUp() do { PORTA_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PA2_ResetPullUp() do { PORTA_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PA2_SetInverted() do { PORTA_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PA2_ResetInverted() do { PORTA_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PA2_DisableInterruptOnChange() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PA2_EnableInterruptForBothEdges() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PA2_EnableInterruptForRisingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PA2_EnableInterruptForFallingEdge() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PA2_DisableDigitalInputBuffer() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PA2_EnableInterruptForLowLevelSensing() do { PORTA.PIN2CTRL = (PORTA.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PA1 aliases
#define IO_PA1_SetHigh() do { PORTA_OUTSET = 0x2; } while(0)
#define IO_PA1_SetLow() do { PORTA_OUTCLR = 0x2; } while(0)
#define IO_PA1_Toggle() do { PORTA_OUTTGL = 0x2; } while(0)
#define IO_PA1_GetValue() (VPORTA.IN & (0x1 << 1))
#define IO_PA1_SetDigitalInput() do { PORTA_DIRCLR = 0x2; } while(0)
#define IO_PA1_SetDigitalOutput() do { PORTA_DIRSET = 0x2; } while(0)
#define IO_PA1_SetPullUp() do { PORTA_PIN1CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PA1_ResetPullUp() do { PORTA_PIN1CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PA1_SetInverted() do { PORTA_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PA1_ResetInverted() do { PORTA_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PA1_DisableInterruptOnChange() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PA1_EnableInterruptForBothEdges() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PA1_EnableInterruptForRisingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PA1_EnableInterruptForFallingEdge() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PA1_DisableDigitalInputBuffer() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PA1_EnableInterruptForLowLevelSensing() do { PORTA.PIN1CTRL = (PORTA.PIN1CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PB3 aliases
#define IO_PB3_SetHigh() do { PORTB_OUTSET = 0x8; } while(0)
#define IO_PB3_SetLow() do { PORTB_OUTCLR = 0x8; } while(0)
#define IO_PB3_Toggle() do { PORTB_OUTTGL = 0x8; } while(0)
#define IO_PB3_GetValue() (VPORTB.IN & (0x1 << 3))
#define IO_PB3_SetDigitalInput() do { PORTB_DIRCLR = 0x8; } while(0)
#define IO_PB3_SetDigitalOutput() do { PORTB_DIRSET = 0x8; } while(0)
#define IO_PB3_SetPullUp() do { PORTB_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PB3_ResetPullUp() do { PORTB_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PB3_SetInverted() do { PORTB_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PB3_ResetInverted() do { PORTB_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PB3_DisableInterruptOnChange() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PB3_EnableInterruptForBothEdges() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PB3_EnableInterruptForRisingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PB3_EnableInterruptForFallingEdge() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PB3_DisableDigitalInputBuffer() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PB3_EnableInterruptForLowLevelSensing() do { PORTB.PIN3CTRL = (PORTB.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set IO_PB2 aliases
#define IO_PB2_SetHigh() do { PORTB_OUTSET = 0x4; } while(0)
#define IO_PB2_SetLow() do { PORTB_OUTCLR = 0x4; } while(0)
#define IO_PB2_Toggle() do { PORTB_OUTTGL = 0x4; } while(0)
#define IO_PB2_GetValue() (VPORTB.IN & (0x1 << 2))
#define IO_PB2_SetDigitalInput() do { PORTB_DIRCLR = 0x4; } while(0)
#define IO_PB2_SetDigitalOutput() do { PORTB_DIRSET = 0x4; } while(0)
#define IO_PB2_SetPullUp() do { PORTB_PIN2CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define IO_PB2_ResetPullUp() do { PORTB_PIN2CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define IO_PB2_SetInverted() do { PORTB_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PB2_ResetInverted() do { PORTB_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)
#define IO_PB2_DisableInterruptOnChange() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define IO_PB2_EnableInterruptForBothEdges() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define IO_PB2_EnableInterruptForRisingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define IO_PB2_EnableInterruptForFallingEdge() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define IO_PB2_DisableDigitalInputBuffer() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define IO_PB2_EnableInterruptForLowLevelSensing() do { PORTB.PIN2CTRL = (PORTB.PIN2CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set LR2_CTS aliases
#define LR2_CTS_SetHigh() do { PORTB_OUTSET = 0x20; } while(0)
#define LR2_CTS_SetLow() do { PORTB_OUTCLR = 0x20; } while(0)
#define LR2_CTS_Toggle() do { PORTB_OUTTGL = 0x20; } while(0)
#define LR2_CTS_GetValue() (VPORTB.IN & (0x1 << 5))
#define LR2_CTS_SetDigitalInput() do { PORTB_DIRCLR = 0x20; } while(0)
#define LR2_CTS_SetDigitalOutput() do { PORTB_DIRSET = 0x20; } while(0)
#define LR2_CTS_SetPullUp() do { PORTB_PIN5CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LR2_CTS_ResetPullUp() do { PORTB_PIN5CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LR2_CTS_SetInverted() do { PORTB_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define LR2_CTS_ResetInverted() do { PORTB_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LR2_CTS_DisableInterruptOnChange() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LR2_CTS_EnableInterruptForBothEdges() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LR2_CTS_EnableInterruptForRisingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LR2_CTS_EnableInterruptForFallingEdge() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LR2_CTS_DisableDigitalInputBuffer() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LR2_CTS_EnableInterruptForLowLevelSensing() do { PORTB.PIN5CTRL = (PORTB.PIN5CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set LR2_RST aliases
#define LR2_RST_SetHigh() do { PORTB_OUTSET = 0x40; } while(0)
#define LR2_RST_SetLow() do { PORTB_OUTCLR = 0x40; } while(0)
#define LR2_RST_Toggle() do { PORTB_OUTTGL = 0x40; } while(0)
#define LR2_RST_GetValue() (VPORTB.IN & (0x1 << 6))
#define LR2_RST_SetDigitalInput() do { PORTB_DIRCLR = 0x40; } while(0)
#define LR2_RST_SetDigitalOutput() do { PORTB_DIRSET = 0x40; } while(0)
#define LR2_RST_SetPullUp() do { PORTB_PIN6CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LR2_RST_ResetPullUp() do { PORTB_PIN6CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LR2_RST_SetInverted() do { PORTB_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define LR2_RST_ResetInverted() do { PORTB_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LR2_RST_DisableInterruptOnChange() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LR2_RST_EnableInterruptForBothEdges() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LR2_RST_EnableInterruptForRisingEdge() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LR2_RST_EnableInterruptForFallingEdge() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LR2_RST_DisableDigitalInputBuffer() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LR2_RST_EnableInterruptForLowLevelSensing() do { PORTB.PIN6CTRL = (PORTB.PIN6CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

//get/set LR2_RTS aliases
#define LR2_RTS_SetHigh() do { PORTC_OUTSET = 0x8; } while(0)
#define LR2_RTS_SetLow() do { PORTC_OUTCLR = 0x8; } while(0)
#define LR2_RTS_Toggle() do { PORTC_OUTTGL = 0x8; } while(0)
#define LR2_RTS_GetValue() (VPORTC.IN & (0x1 << 3))
#define LR2_RTS_SetDigitalInput() do { PORTC_DIRCLR = 0x8; } while(0)
#define LR2_RTS_SetDigitalOutput() do { PORTC_DIRSET = 0x8; } while(0)
#define LR2_RTS_SetPullUp() do { PORTC_PIN3CTRL  |= PORT_PULLUPEN_bm; } while(0)
#define LR2_RTS_ResetPullUp() do { PORTC_PIN3CTRL  &= ~PORT_PULLUPEN_bm; } while(0)
#define LR2_RTS_SetInverted() do { PORTC_PIN3CTRL  |= PORT_INVEN_bm; } while(0)
#define LR2_RTS_ResetInverted() do { PORTC_PIN3CTRL  &= ~PORT_INVEN_bm; } while(0)
#define LR2_RTS_DisableInterruptOnChange() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x0 ; } while(0)
#define LR2_RTS_EnableInterruptForBothEdges() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x1 ; } while(0)
#define LR2_RTS_EnableInterruptForRisingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x2 ; } while(0)
#define LR2_RTS_EnableInterruptForFallingEdge() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x3 ; } while(0)
#define LR2_RTS_DisableDigitalInputBuffer() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x4 ; } while(0)
#define LR2_RTS_EnableInterruptForLowLevelSensing() do { PORTC.PIN3CTRL = (PORTC.PIN3CTRL & ~PORT_ISC_gm) | 0x5 ; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize();

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PA7 pin. 
 *        This is a predefined interrupt handler to be used together with the PA7_SetInterruptHandler() method.
 *        This handler is called every time the PA7 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PA7_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PA7 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PA7 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PA7_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PA2 pin. 
 *        This is a predefined interrupt handler to be used together with the PA2_SetInterruptHandler() method.
 *        This handler is called every time the PA2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PA2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PA2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PA2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PA2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PA1 pin. 
 *        This is a predefined interrupt handler to be used together with the PA1_SetInterruptHandler() method.
 *        This handler is called every time the PA1 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PA1_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PA1 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PA1 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PA1_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PB3 pin. 
 *        This is a predefined interrupt handler to be used together with the PB3_SetInterruptHandler() method.
 *        This handler is called every time the PB3 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PB3_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PB3 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PB3 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PB3_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PB2 pin. 
 *        This is a predefined interrupt handler to be used together with the PB2_SetInterruptHandler() method.
 *        This handler is called every time the PB2 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PB2_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PB2 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PB2 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PB2_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PB5 pin. 
 *        This is a predefined interrupt handler to be used together with the PB5_SetInterruptHandler() method.
 *        This handler is called every time the PB5 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PB5_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PB5 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PB5 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PB5_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PB6 pin. 
 *        This is a predefined interrupt handler to be used together with the PB6_SetInterruptHandler() method.
 *        This handler is called every time the PB6 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PB6_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PB6 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PB6 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PB6_SetInterruptHandler(void (* interruptHandler)(void)) ; 

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for PC3 pin. 
 *        This is a predefined interrupt handler to be used together with the PC3_SetInterruptHandler() method.
 *        This handler is called every time the PC3 ISR is executed. 
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param none
 * @return none
 */
void PC3_DefaultInterruptHandler(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for PC3 pin input-sense-config functionality.
 *        Allows selecting an interrupt handler for PC3 at application runtime
 * @pre PIN_MANAGER_Initialize() has been called at least once
 * @param InterruptHandler function pointer.
 * @return none
 */
void PC3_SetInterruptHandler(void (* interruptHandler)(void)) ; 
#endif /* PINS_H_INCLUDED */

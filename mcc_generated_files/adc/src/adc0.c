																								/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
� [2022] Microchip Technology Inc. and its subsidiaries.

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


#include "../adc0.h"

adc_irq_cb_t ADC0_window_cb = NULL;

/**
 * \brief Initialize ADC interface
 */
int8_t ADC0_Initialize(void)
{
     
    //PRESC System clock divided by 2; 
    ADC0.CTRLB = 0x0;

    //FREERUN enabled; LEFTADJ disabled; SAMPNUM No accumulation; 
    ADC0.CTRLF = 0x20;

    //REFSEL VDD; TIMEBASE 4; 
    ADC0.CTRLC = 0x20;

    //WINCM No Window Comparison; WINSRC RESULT; 
    ADC0.CTRLD = 0x0;

    //SAMPDUR 255; 
    ADC0.CTRLE = 0xFF;

    //ADCPGASAMPDUR 6 ADC cycles; GAIN 1X Gain; PGABIASSEL 1x BIAS current; PGAEN disabled; 
    ADC0.PGACTRL = 0x0;

    //DBGRUN disabled; 
    ADC0.DBGCTRL = 0x0;

    //DIFF disabled; MODE SINGLE_12BIT; START Stop an ongoing conversion; 
    ADC0.COMMAND = 0x10;

    //RESOVR disabled; RESRDY disabled; SAMPOVR disabled; SAMPRDY disabled; TRIGOVR disabled; WCMP disabled; 
    ADC0.INTCTRL = 0x0;

    //MUXPOS ADC input pin 7; VIA Via ADC; 
    ADC0.MUXPOS = 0x7;

    //MUXNEG Ground; VIA Via ADC; 
    ADC0.MUXNEG = 0x30;

    // Window comparator high threshold 
    ADC0.WINHT = 0x0;

    // Window comparator low threshold 
    ADC0.WINLT = 0x0;

    //ENABLE enabled; LOWLAT disabled; RUNSTDBY disabled; 
    ADC0.CTRLA = 0x1;


    return 0;
}

void ADC0_Enable(void)
{
    ADC0.CTRLA |= ADC_ENABLE_bm;
}

void ADC0_Disable(void)
{
    ADC0.CTRLA &= ~ADC_ENABLE_bm;
}

void ADC0_SetWindowHigh(adc_result_t high)
{
    ADC0.WINHT = high;
}

void ADC0_SetWindowLow(adc_result_t low)
{
    ADC0.WINLT = low;
}

void ADC0_SetWindowMode(ADC0_window_mode_t mode)
{
    ADC0.CTRLD = mode;
}

void ADC0_SetWindowChannel(adc_0_channel_t channel)
{
    ADC0.MUXPOS &= ADC_VIA_gm;
    ADC0.MUXPOS |= channel;
}

void ADC0_StartConversion(adc_0_channel_t channel)
{
    ADC0.MUXPOS &= ADC_VIA_gm;
    ADC0.MUXPOS |= channel;
    ADC0.COMMAND &= ~ADC_DIFF_bm;
    ADC0.COMMAND |= ADC_START_IMMEDIATE_gc;
}

void ADC0_StartDiffConversion(adc_0_channel_t channel, adc_0_muxneg_channel_t channel1)
{
    ADC0.MUXPOS &= ADC_VIA_gm;
    ADC0.MUXPOS |= channel;

    ADC0.MUXNEG &= ADC_VIA_gm;
    ADC0.MUXNEG |= channel1;
    
    ADC0.COMMAND |= (ADC_START_IMMEDIATE_gc | ADC_DIFF_bm);
}

void ADC0_StopConversion(void)
{
    ADC0.COMMAND |= ADC_START_STOP_gc;
}

bool ADC0_IsConversionDone(void)
{
    return (ADC0.INTFLAGS & ADC_RESRDY_bm);
}

adc_result_t ADC0_GetConversionResult(void)
{
    return (ADC0.RESULT);
}

bool ADC0_GetWindowResult(void)
{
    bool temp = (ADC0.INTFLAGS & ADC_WCMP_bm);
    ADC0.INTFLAGS = ADC_WCMP_bm; // Clear intflag if set
    return temp;
}

adc_result_t ADC0_GetConversion(adc_0_channel_t channel)
{
    adc_result_t res;

    ADC0_StartConversion(channel);
    while (!ADC0_IsConversionDone());
    res = ADC0_GetConversionResult();
    ADC0.INTFLAGS = ADC_RESRDY_bm;
    return res;
}

diff_adc_result_t ADC0_GetDiffConversion(bool enablePGA, adc_0_channel_t channel, adc_0_muxneg_channel_t channel1)
{
    diff_adc_result_t res;

    ADC0_StartDiffConversion(channel, channel1|(enablePGA<<6));
    while (!ADC0_IsConversionDone());
    res = ADC0_GetConversionResult();
    ADC0.INTFLAGS |= ADC_RESRDY_bm;
    return res;
}

uint8_t ADC0_GetResolution(void)
{
    return (ADC0.COMMAND & ADC_MODE_SINGLE_8BIT_gc) ? 8 : 12;
}

void ADC0_RegisterWindowCallback(adc_irq_cb_t f)
{
    ADC0_window_cb = f;
}

ISR(ADC0_SAMPRDY_vect)
{
    /* Insert your ADC Sample ready interrupt handling code here */

    // Clear the interrupt flag
    ADC0.INTFLAGS = ADC_SAMPRDY_bm;
}

ISR(ADC0_RESRDY_vect)
{
    /* Insert your ADC result ready interrupt handling code here */

    /* The interrupt flag has to be cleared manually */
    ADC0.INTFLAGS = ADC_RESRDY_bm;
}

ISR(ADC0_ERROR_vect)
{
    /* Insert your ADC Error interrupt handling code here */

    /* The interrupt flag has to be cleared manually */
    ADC0.INTFLAGS = ADC_TRIGOVR_bm;

    /* The interrupt flag has to be cleared manually */
    ADC0.INTFLAGS = ADC_SAMPOVR_bm;

    /* The interrupt flag has to be cleared manually */
    ADC0.INTFLAGS = ADC_RESOVR_bm;
}

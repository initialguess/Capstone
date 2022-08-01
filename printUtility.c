#include "printUtility.h"
#include "mcc_generated_files/uart/usart0.h"
#include "mcc_generated_files/uart/usart1.h"
#include "TERM_tx_buff.h"

#define BUFFER_USB buffer
#define BUFFER_BLE buffer

static char buffer[PRINT_BUFFER_SIZE];

//Returns the Address of the character buffer
char* USB_getCharBuffer(void)
{
    return &BUFFER_USB[0];
}

////Prints the string on the UART
//void USB_sendBufferedString(void)
//{   
//    if (BUFFER_USB[0] == '\0')
//        return;
//    
//    uint8_t index = 0;
//    
//    //Clear USART Done Flag
//    USART0.STATUS |= USART_TXCIF_bm;
//    
//    while ((BUFFER_USB[index] != '\0') && (index < PRINT_BUFFER_SIZE))
//    {
//        while (!TERM_IsTxReady());
//        
//        TERM_sendByte(BUFFER_USB[index]);
//        index++;
//    }
//    
//    //Wait for completion of UART
//    while (TERM_IsTxBusy());
//}

//Prints a constant string to the UART
void USB_sendStringRaw(const char* text)
{  
    if (text[0] == '\0')
        return;
    
    uint8_t index = 0;
    
    //Clear USART Done Flag
    USART0.STATUS |= USART_TXCIF_bm;
    
    while ((text[index] != '\0') && (index < 255))
    {
        while (!TERM_IsTxReady());
        
        TERM_sendByte(text[index]);
        index++;
    }
    
    //Wait for completion of UART
    while (TERM_IsTxDone());
}

//Prints a constant string to the UART
void USB_sendStringWithEndline(const char* text)
{
#ifdef DISABLE_STRING_MESSAGES
    return;
#else    
    if (text[0] == '\0')
        return;

    USB_sendStringRaw(text);
    USB_sendStringRaw("\r\n");
    
#endif
}



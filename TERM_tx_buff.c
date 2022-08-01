#include "TERM_tx_buff.h"
#include "lr2.h"
#include <stdbool.h>

static char Buffer[LR2_MAX_DATA_SIZE];
static uint8_t Head = 0;
static uint8_t Tail = 0;


/* Adds a char to the buffer */
void TERM_tx_buff_Push(char c) {
    if (Tail + 1 != Head) {
        Buffer[Tail] = c;
        Tail++;        
    }
}

/* Adds a string to the buffer */
void TERM_tx_buff_Push_Str(char *str) {
    uint8_t pos = 0;
    char c = str[pos];
    while(Tail + 1 != Head && c) {
        Buffer[Tail] = c;
    	Tail++;
    	pos++;
    	c = str[pos];
    }
}

/* Gets the first char in the queue, and removes it from the buffer */
char TERM_tx_buff_Pop() {
    char ret = Buffer[Head];
	Head++;
	return ret;
}

/* Returns the number of items in the buffer */
uint8_t TERM_tx_buff_Count() {
	return Head - Tail;
}

void TERM_buffer_reset(void) 
{
    Tail = 0;
    Head = 0;
    for(int i = 0; i < LR2_MAX_DATA_SIZE; i++) 
    {
        Buffer[i] = '\0';
    }
}

//Sends a byte of data
bool TERM_sendByte(char c)
{
    if (TERM_IsTxReady())
    {
        //Clear done bit
        USART0.STATUS |= USART_TXCIF_bm;

        //Load Byte of Data
        USART0.TXDATAL = c;
        return true;  
    }
    return false;
}

//Prints the string on the UART
void TERM_sendBufferedString(void)
{   
    if (Buffer[0] == '\0')
        return;
    
    uint8_t index = 0;
    
    //Clear USART Done Flag
    USART0.STATUS |= USART_TXCIF_bm;
    
    while ((Buffer[index] != '\0') && (index < LR2_MAX_DATA_SIZE))
    {
        while (!TERM_IsTxReady());
        
        TERM_sendByte(Buffer[index]);
        index++;
    }
    
    //Wait for completion of UART
    while (TERM_IsTxDone());
}
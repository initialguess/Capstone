#include "LR2_tx_buff.h"
#include <util/delay.h>

static char Buffer[256];
static uint8_t Head = 0;
static uint8_t Tail = 0;

/* Adds a char to the buffer */
void LR2_tx_buff_Push(char c) {
    if(Tail + 1 != Head) {
        Buffer[Tail] = c;
        Tail++;
    }
}

/* Adds a string to the buffer */
void LR2_tx_buff_Push_Str(char *str) {
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
char LR2_tx_buff_Pop() {
    char ret = Buffer[Head];
	Head++;
	return ret;
}

/* Returns the number of items in the buffer */
uint8_t LR2_tx_buff_Count() {
	return Head - Tail;
}

void LR2_buffer_reset(void) {
    Tail = 0;
    Head = 0;
    for(int i = 0; i < 256; i++) 
    {
        Buffer[i] = '\0';
    }
}

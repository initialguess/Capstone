#ifndef LR2_tx_buff_H
	#define LR2_tx_buff_H

    #include "mcc_generated_files/system/system.h"
	
	/*Function prototypes*/
    void LR2_tx_buff_Push(char c);
    void LR2_tx_buff_Push_Str(char *str);
    char LR2_tx_buff_Pop();
    uint8_t LR2_tx_buff_Count();
    void LR2_buffer_reset();
#endif

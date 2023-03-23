/* 
	startup.c for Cortex-M3
	Eng. Ahmed Essam
*/

#include <stdint.h>

int main(void);
void Reset_Handler();
void Default_Handler(){
	Reset_Handler();
}

void NMI_Handler() 			__attribute__ ((weak, alias("Default_Handler")));
void H_Fault_Handler() 		__attribute__ ((weak, alias("Default_Handler")));
void MM_Fault_Handler() 	__attribute__ ((weak, alias("Default_Handler")));
void Bus_Fault() 			__attribute__ ((weak, alias("Default_Handler")));
void Usage_Fault_Handler() 	__attribute__ ((weak, alias("Default_Handler")));

extern uint32_t _STACK_top;

uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t) &_STACK_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_Fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault,
	(uint32_t) &Usage_Fault_Handler
};

extern unsigned int _E_text_;
extern unsigned int _S_data_;
extern unsigned int _E_data_;
extern unsigned int _S_bss_;
extern unsigned int _E_bss_;

void Reset_Handler(){
	//Copy .data from FLASH to SRAM
	unsigned int data_SIZE = 
		(unsigned char*)(&_E_data_) - (unsigned char*)(&_S_data_);

	unsigned char * P_src = (unsigned char*)_E_text_;
	unsigned char * P_dest = (unsigned char*)_S_data_;

	for(int i = 0; i < data_SIZE; i++){
		*((unsigned char *)P_dest++) = *((unsigned char *)P_src++);
	}

	//Initialize .bss in SRAM by zeros
	unsigned int bss_SIZE = 
		(unsigned char*)(&_E_bss_) - (unsigned char*)(&_S_bss_);

	P_dest = (unsigned char*)_S_bss_;

	for(int i = 0; i < bss_SIZE; i++){
		*((unsigned char *)P_dest++) = (unsigned char) 0;
	}

	//Proceed to main function
	main();
}


/*
	main.c for LIFO Driver
	Eng. Ahmed Essam
*/

#include "lifo.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int buffer1[5];

void main(){

	int i, temp = 0;

	//Static Allocation
	LIFO_Buffer_t UART_LIFO;
	LIFO_init(&UART_LIFO, buffer1, 5);

	//Dynamic Allocation
	LIFO_Buffer_t I2C_LIFO;
	unsigned int* buffer2 = (unsigned int*)malloc(5 * sizeof(unsigned int));
	LIFO_init(&I2C_LIFO, buffer2, 5);

	//Push item
	for(i = 0; i < 5; i++){
		if(LIFO_push(&UART_LIFO, i) == LIFO_No_Error)
			printf("LIFO PUSH : %d \n", i);
	}

	printf("\n");

	//Pop item
	for(i = 0; i < 5; i++){
		if(LIFO_pop(&UART_LIFO, &temp) == LIFO_No_Error)
			printf("LIFO POP : %d \n", temp);
	}
}
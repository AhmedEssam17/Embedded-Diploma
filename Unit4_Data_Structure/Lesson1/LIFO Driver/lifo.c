/*
	lifo.c for LIFO Driver
	Eng. Ahmed Essam
*/

#include "lifo.h"
#include <stdio.h>
#include <stdlib.h>

/* APIS */
LIFO_Status LIFO_init(LIFO_Buffer_t* LIFO_Buffer, unsigned int* buffer, unsigned int length){

	//Check Buffer availability
	if(buffer == NULL)
		return LIFO_Null;

	//Initialize LIFO_Buffer
	LIFO_Buffer->base = buffer;
	LIFO_Buffer->head = buffer;
	LIFO_Buffer->length = length;
	LIFO_Buffer->count = 0;

	return LIFO_No_Error;
}

LIFO_Status LIFO_push(LIFO_Buffer_t* LIFO_Buffer, unsigned int item){

	//Check LIFO validity
	if(!(LIFO_Buffer->base) || !(LIFO_Buffer->head))
		return LIFO_Null;

	//Check if LIFO is full
	if(LIFO_Buffer->count == LIFO_Buffer->length)
		return LIFO_Full;

	//PUSH item
	*(LIFO_Buffer->head) = item;
	LIFO_Buffer->head++;
	LIFO_Buffer->count++;

	return LIFO_No_Error;
}

LIFO_Status LIFO_pop(LIFO_Buffer_t* LIFO_Buffer, unsigned int* item){

	//Check LIFO validity
	if(!(LIFO_Buffer->base) || !(LIFO_Buffer->head))
		return LIFO_Null;

	//Check if LIFO is empty
	if(LIFO_Buffer->count == 0)
		return LIFO_Empty;

	//POP item
	LIFO_Buffer->head--;
	*item = *(LIFO_Buffer->head);
	LIFO_Buffer->count--;

	return LIFO_No_Error;
}

LIFO_Status LIFO_top(LIFO_Buffer_t* LIFO_Buffer, unsigned int* item){

	//Check LIFO validity
	if(!(LIFO_Buffer->base) || !(LIFO_Buffer->head))
		return LIFO_Null;

	//Check if LIFO is empty
	if(LIFO_Buffer->count == 0)
		return LIFO_Empty;

	//TOP item
	LIFO_Buffer->head--;
	*item = *(LIFO_Buffer->head);
	LIFO_Buffer->head++;

	return LIFO_No_Error;
}


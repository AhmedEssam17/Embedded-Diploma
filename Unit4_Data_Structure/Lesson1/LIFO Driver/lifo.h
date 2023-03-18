/*
	lifo.h for LIFO Driver
	Eng. Ahmed Essam
 */

#ifndef LIFO_H_
#define LIFO_H_

/* typedefs */
typedef struct{
	unsigned int length;
	unsigned int count;
	unsigned int *base;
	unsigned int *head;
} LIFO_Buffer_t;

typedef enum{
	LIFO_No_Error,
	LIFO_Full,
	LIFO_Empty,
	LIFO_Null
} LIFO_Status;

/* APIS */
LIFO_Status LIFO_init(LIFO_Buffer_t* LIFO_Buffer, unsigned int* buffer, unsigned int length);
LIFO_Status LIFO_push(LIFO_Buffer_t* LIFO_Buffer, unsigned int item);
LIFO_Status LIFO_pop(LIFO_Buffer_t* LIFO_Buffer, unsigned int* item);
LIFO_Status LIFO_top(LIFO_Buffer_t* LIFO_Buffer, unsigned int* item);

#endif

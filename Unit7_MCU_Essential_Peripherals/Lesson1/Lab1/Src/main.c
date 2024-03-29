/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>

//RCC Registers
#define RCC_BASE 	0x40021000
#define RCC_APB2ENR *(volatile uint32_t *) (RCC_BASE + 0x18)
#define RCC_IOPAEN 	(1<<2)
#define RCC_IOPBEN 	(1<<3)

//GPIOA Registers
#define GPIOA_BASE 	0x40010800
#define GPIOA_CRL 	*(volatile uint32_t *) (GPIOA_BASE + 0x00)
#define GPIOA_CRH 	*(volatile uint32_t *) (GPIOA_BASE + 0x04)
#define GPIOA_IDR 	*(volatile uint32_t *) (GPIOA_BASE + 0x08)
#define GPIOA_ODR 	*(volatile uint32_t *) (GPIOA_BASE + 0x0C)

//GPIOB Registers
#define GPIOB_BASE 	0x40010C00
#define GPIOB_CRL 	*(volatile uint32_t *) (GPIOB_BASE + 0x00)
#define GPIOB_CRH 	*(volatile uint32_t *) (GPIOB_BASE + 0x04)
#define GPIOB_IDR 	*(volatile uint32_t *) (GPIOB_BASE + 0x08)
#define GPIOB_ODR 	*(volatile uint32_t *) (GPIOB_BASE + 0x0C)



void clock_init(){

	//Enable clock for GPIO PortA
	RCC_APB2ENR |= RCC_IOPAEN;

	//Enable clock for GPIO PortB
	RCC_APB2ENR |= RCC_IOPBEN;
}

void GPIO_init(){

	//Reset GPIOx_CRL and GPIOx_CRH
	GPIOA_CRL = 0x0;
	GPIOB_CRL = 0x0;
	GPIOA_CRH = 0x0;
	GPIOB_CRH = 0x0;

	//PA1 (Input Floating "HI-Z")
	//Floating Input + Output Push/Pull (0100)
	GPIOA_CRL |= (0b0100<<4);

	//PB1 (Output Push/Pull Mode)
	//Push/Pull Output + Max Speed 10MHz (0001)
	GPIOB_CRL |= (0b0001<<4);

	//PA13 (Input Floating "HI-Z")
	//Floating Input + Output Push/Pull (0100)
	GPIOA_CRH |= (0b0100<<20);

	//PB13 (Output Push/Pull Mode)
	//Push/Pull Output + Max Speed 10MHz (0001)
	GPIOB_CRH |= (0b0001<<20);
}

void delay(int n){
	uint32_t i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < 255; j++);
}

int main(void)
{
	clock_init();
	GPIO_init();

	while(1){

		if(((GPIOA_IDR & 1<<1) >> 1) == 0){ //PUR
			//Switch is Pressed
			GPIOB_ODR ^= 1<<1;
			while(((GPIOA_IDR & 1<<1) >> 1) == 0); //Single Pressed
		}

		if(((GPIOA_IDR & 1<<13) >> 13) == 1){ //PDR
			//Switch is Pressed
			GPIOB_ODR ^= 1<<13;
		}

		delay(1);
	}
}



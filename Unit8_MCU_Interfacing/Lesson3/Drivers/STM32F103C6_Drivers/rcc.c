/*
 * rcc.c
 *
 *  Created on: Jul 10, 2023
 *      Author: Lenovo
 */

#include "rcc.h"

/*
	Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
	Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
	0xx: HCLK not divided
	100: HCLK divided by 2
	101: HCLK divided by 4
	110: HCLK divided by 8
	111: HCLK divided by 16
*/
const uint8_t APBPrescTable[8U] = {0, 0, 0, 0, 1, 2, 3, 4};

/*
 	Bits 7:4 HPRE: AHB prescaler
	Set and cleared by software to control the division factor of the AHB clock.
	0xxx: SYSCLK not divided
	1000: SYSCLK divided by 2
	1001: SYSCLK divided by 4
	1010: SYSCLK divided by 8
	1011: SYSCLK divided by 16
	1100: SYSCLK divided by 64
	1101: SYSCLK divided by 128
	1110: SYSCLK divided by 256
	1111: SYSCLK divided by 512
*/
const uint8_t AHBPrescTable[16U] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};

uint32_t MCAL_RCC_getPCLK1(void){
	//Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
	return MCAL_RCC_getHCLK() >> APBPrescTable[(RCC->CFGR >> 8 & 0b111)];
}

uint32_t MCAL_RCC_getPCLK2(void){
	//Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
	return MCAL_RCC_getHCLK() >> APBPrescTable[(RCC->CFGR >> 11 & 0b111)];
}

uint32_t MCAL_RCC_getHCLK(void){
	return MCAL_RCC_getSYSCLK() >> AHBPrescTable[(RCC->CFGR >> 4 & 0xF)];
}

uint32_t MCAL_RCC_getSYSCLK(void){
	/*
		Bits 3:2 SWS: System clock switch status
		Set and cleared by hardware to indicate which clock source is used as system clock.
		00: HSI oscillator used as system clock
		01: HSE oscillator used as system clock
		10: PLL used as system clock
		11: not applicable
	 */
	switch ((RCC->CFGR >> 2) & 0b11){
	case 0:
		return HSI_RC_CLK;
		break;
	case 1:
		return HSE_CLK;
		break;
	case 2:
		return 16000000;
		break;
	}
	return HSI_RC_CLK;
}


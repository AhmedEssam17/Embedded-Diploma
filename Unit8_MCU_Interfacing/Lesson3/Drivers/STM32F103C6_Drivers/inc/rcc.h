/*
 * rcc.h
 *
 *  Created on: Jul 10, 2023
 *      Author: Lenovo
 */

#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "STM32F103x6.h"

#define HSI_RC_CLK 	(uint32_t)16000000
#define HSE_CLK 	(uint32_t)8000000

uint32_t MCAL_RCC_getPCLK1(void);
uint32_t MCAL_RCC_getPCLK2(void);
uint32_t MCAL_RCC_getHCLK(void);
uint32_t MCAL_RCC_getSYSCLK(void);

#endif /* INC_RCC_H_ */

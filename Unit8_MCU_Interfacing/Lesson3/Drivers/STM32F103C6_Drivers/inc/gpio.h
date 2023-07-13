/*
 * gpio.h
 *
 *  Created on: May 3, 2023
 *      Author: AhmedEssam
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "STM32F103x6.h"

//====================================================================
//						Configuration Structure
//====================================================================

typedef struct{
	uint16_t GPIO_PinNumber;		//Specifies Pin Number to be Configured >> @ref GPIO_PIN_def
	uint16_t GPIO_MODE;				//Specifies Pin Number to be Configured >> @ref GPIO_MODE_def
	uint16_t GPIO_OUTPUT_SPEED;		//Specifies Pin Number to be Configured >> @ref GPIO_OUTPUT_SPEED_def
}GPIO_PinConfig_t;


//====================================================================
//						Configuration Reference
//====================================================================

//-----------------------------
//@ref GPIO_PIN_def
//-----------------------------

#define GPIO_PIN_0					((uint16_t)0x0001)	//Selected PIN0
#define GPIO_PIN_1					((uint16_t)0x0002)	//Selected PIN1
#define GPIO_PIN_2					((uint16_t)0x0004)	//Selected PIN2
#define GPIO_PIN_3					((uint16_t)0x0008)	//Selected PIN3
#define GPIO_PIN_4					((uint16_t)0x0010)	//Selected PIN4
#define GPIO_PIN_5					((uint16_t)0x0020)	//Selected PIN5
#define GPIO_PIN_6					((uint16_t)0x0040)	//Selected PIN6
#define GPIO_PIN_7					((uint16_t)0x0080)	//Selected PIN7
#define GPIO_PIN_8					((uint16_t)0x0100)	//Selected PIN8
#define GPIO_PIN_9					((uint16_t)0x0200)	//Selected PIN9
#define GPIO_PIN_10					((uint16_t)0x0400)	//Selected PIN10
#define GPIO_PIN_11					((uint16_t)0x0800)	//Selected PIN11
#define GPIO_PIN_12					((uint16_t)0x1000)	//Selected PIN12
#define GPIO_PIN_13					((uint16_t)0x2000)	//Selected PIN13
#define GPIO_PIN_14					((uint16_t)0x4000)	//Selected PIN14
#define GPIO_PIN_15					((uint16_t)0x8000)	//Selected PIN15
#define GPIO_PIN_ALL				((uint16_t)0xFFFF)	//Selected ALL PINS
#define GPIO_PIN_MASK				(0x0000FFFFu)			//PINS Mask

//-----------------------------
//@ref GPIO_MODE_def
//-----------------------------

#define GPIO_MODE_ANALOG				0x00000000u //Analog Mode
#define GPIO_MODE_INPUT_FLOAT			0x00000001u //Floating Input
#define GPIO_MODE_INPUT_PU				0x00000002u //Input with Pull-Up
#define GPIO_MODE_INPUT_PD				0x00000003u //Input with Pull-Down
#define GPIO_MODE_OUTPUT_PP				0x00000004u //General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD				0x00000005u //General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP			0x00000006u //Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD			0x00000007u //Alternate function output Open-drain
#define GPIO_MODE_INPUT_AF				0x00000008u //Alternate function Input

//-----------------------------
//@ref GPIO_OUTPUT_SPEED_def
//-----------------------------

#define GPIO_OUTPUT_SPEED_10M			0x00000001u //Output mode, max speed 10 MHz
#define GPIO_OUTPUT_SPEED_2M			0x00000002u //Output mode, max speed 2 MHz
#define GPIO_OUTPUT_SPEED_50M			0x00000003u //Output mode, max speed 50 MHz

//-----------------------------
//@ref GPIO_PIN_STATUS_def
//-----------------------------

#define GPIO_PIN_SET 			1
#define GPIO_PIN_RESET 			0

//-----------------------------
//@ref GPIO_PIN_LOCK_STATUS_def
//-----------------------------

#define GPIO_PIN_LOCK_SUCCESS 	1
#define GPIO_PIN_LOCK_FAILED	0

//====================================================================
//					APIs Supported by MCAL GPIO Driver
//====================================================================

void MCAL_GPIO_init(GPIO_t *GPIOx, GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_deinit(GPIO_t *GPIOx);

uint8_t MCAL_GPIO_ReadPin(GPIO_t *GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort(GPIO_t *GPIOx);

void MCAL_GPIO_WritePin(GPIO_t *GPIOx, uint16_t PinNumber, uint8_t data);
void MCAL_GPIO_WritePort(GPIO_t *GPIOx, uint16_t data);

void MCAL_GPIO_TogglePin(GPIO_t *GPIOx, uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin(GPIO_t *GPIOx, uint16_t PinNumber);

#endif /* INC_GPIO_H_ */

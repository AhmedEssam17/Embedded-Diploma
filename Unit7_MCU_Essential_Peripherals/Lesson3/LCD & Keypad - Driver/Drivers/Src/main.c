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

#include "STM32F103x6.h"
#include "gpio.h"
#include "lcd.h"
#include "keypad.h"

#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10

void clock_init(){
	//Enable clock for GPIO PortA
	RCC_GPIOA_CLK_ENABLE();

	//Enable clock for GPIO PortB
	RCC_GPIOB_CLK_ENABLE();
}

void GPIO_init() {

	GPIO_PinConfig_t PinCfg;

	PinCfg.GPIO_PinNumber = GPIO_PIN_9;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_10;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_11;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_12;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_13;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	//============================

	//PA13 input HighZ Floating input (reset state)
	PinCfg.GPIO_PinNumber = GPIO_PIN_14;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(GPIOB, &PinCfg);

	//PB13 (output PUSH pull Mode)
	PinCfg.GPIO_PinNumber = GPIO_PIN_15;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(GPIOB, &PinCfg);

}

int main(void)
{
	clock_init();
	LCD_INIT();
	GPIO_init();

	unsigned char LCD_DISPLAY [11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
	unsigned char DISPLAY [11] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	for (unsigned char i = 0; i < 11; i++) {
		LCD_WriteChar(LCD_DISPLAY[i]);
		MCAL_GPIO_WritePort(GPIOB, DISPLAY[i] << 9); /* write data on to the LED port */
		delay(100);
		/* wait for 1 second */
	}

	LCD_ClearScreen();
	LCD_WriteString("Keypad is ready");
	Keypad_init();
	delay(30);
	LCD_ClearScreen();

	unsigned char key_pressed;
	while(1){
		key_pressed = Keypad_getkey();
		switch(key_pressed){
		case 'A':
			break;
		case '?':
			LCD_ClearScreen();
			break;
		default:
			LCD_WriteChar(key_pressed);
			break;
		}
	}
}
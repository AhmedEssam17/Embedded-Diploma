/*
 * lcd.c
 *
 * Created: 5/2/2023 7:48:37 PM
 *  Author: AhmedEssam
 */ 

#include "lcd.h"

void delay(uint32_t n){
	uint32_t i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < 255; j++);
}

void LCD_INIT(){
	delay(20);

	PinConfig.GPIO_PinNumber = RS_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = RW_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_CTRL, &PinConfig);

	PinConfig.GPIO_PinNumber = EN_SWITCH;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_CTRL, &PinConfig);

	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);

	PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_2;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_3;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	delay(15);
	LCD_ClearScreen();
	LCD_WriteCommand(LCD_FUNCTION_8BIT_2LINES);

	LCD_WriteCommand(LCD_ENTRY_MODE);
	LCD_WriteCommand(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WriteCommand(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_WriteCommand(unsigned char command){
	/*
		LCD_check_lcd_isbusy();
		LCD_PORT = command;
		LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));
		_delay_ms(1);
		LCD_lcd_kick();
	 */
	LCD_isBusy();
	MCAL_GPIO_WritePort(LCD_PORT, command);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	delay(1);
	LCD_Kick();
}

void LCD_WriteChar(unsigned char data){
	/*
	 	 LCD_check_lcd_isbusy();
		LCD_PORT = character;
		LCD_CTRL &= ~(1 << RW_SWITCH);
		LCD_CTRL |= (1 << RS_SWITCH);
		_delay_ms(1);
		LCD_lcd_kick();
	 */
	LCD_isBusy();
	MCAL_GPIO_WritePort(LCD_PORT, data);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);
	delay(1);
	LCD_Kick();
}

void LCD_WriteString(char* string){
	int count = 0;
	while (*string > 0){
		count++;
		LCD_WriteChar(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_ClearScreen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}

void LCD_isBusy(void){
	/*
	DataDir_LCD_PORT &= ~(0xFF<<DATA_shift);
	LCD_CTRL |= (1 << RW_SWITCH);
	LCD_CTRL &= ~(1 << RS_SWITCH);
	LCD_lcd_kick();
	DataDir_LCD_PORT |= (0xFF<<DATA_shift);
	LCD_CTRL &= ~(1 << RW_SWITCH);
	 */
	PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLOAT;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLOAT;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_2;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLOAT;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_3;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLOAT;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLOAT;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLOAT;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLOAT;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLOAT;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);


	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);

	LCD_Kick();

	PinConfig.GPIO_PinNumber = GPIO_PIN_0;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_1;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_2;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_3;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_4;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_6;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	PinConfig.GPIO_PinNumber = GPIO_PIN_7;
	PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
	MCAL_GPIO_init(LCD_PORT, &PinConfig);

	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
}

void LCD_Kick(void){
	/*
	 LCD_CTRL |= (1 << EN_SWITCH);
	_delay_ms(50);
	LCD_CTRL &= ~(1 << EN_SWITCH);
	 */
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_SET);
	delay(50);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
}

void LCD_ClearScreen(){
	LCD_WriteCommand(LCD_CLEAR_SCREEN);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WriteCommand(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WriteCommand(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}


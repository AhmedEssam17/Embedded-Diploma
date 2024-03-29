/*
 * usart.h
 *
 *  Created on: Jul 10, 2023
 *      Author: Lenovo
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#include "STM32F103x6.h"
#include "gpio.h"
#include "rcc.h"

//====================================================================
//						Configuration Structure
//====================================================================

typedef struct {
	uint8_t 	USART_MODE;					//Specifies TX/RX Enable/Disable 			>> @ref USART_MODE_def
	uint32_t 	USART_BaudRate;				//Configures USART Communication BaudRate 	>> @ref USART_BaudRate_def
	uint8_t 	USART_PayLoad;				//Specifies number of Data Bits 			>> @ref USART_Payload_def
	uint8_t		USART_Parity;				//Specifies Parity Mode 					>> @ref USART_Parity_def
	uint8_t		USART_StopBit;				//Specifies number of Stop Bits 			>> @ref USART_StopBit_def
	uint8_t		USART_HwFlowCtrl;			//Specifies HwFlowCtrl Enable/Disable 		>> @ref USART_HwFlowCtrl_def
	uint8_t		USART_IRQ_EN;				//Specifies IRQ Enable/Disable 				>> @ref USART_IRQ_EN_def
	void		(*P_IRQ_CallBack)(void);	//Set CallBack function when IRQ occurs
}USART_Config_t;

//====================================================================
//						Configuration Reference
//====================================================================

//-----------------------------
//@ref USART_MODE_def
//-----------------------------

#define USART_MODE_RX					(uint32_t)(1<<2)
#define USART_MODE_TX					(uint32_t)(1<<3)
#define USART_MODE_TX_RX				(uint32_t)(1<<3 | 1<<2)

//-----------------------------
//@ref USART_BaudRate_def
//-----------------------------

#define USART_BaudRate_2400				2400
#define USART_BaudRate_9600				9600
#define USART_BaudRate_19200			19200
#define USART_BaudRate_57600			57600
#define USART_BaudRate_115200			115200
#define USART_BaudRate_230400			230400
#define USART_BaudRate_460800			460800
#define USART_BaudRate_921600			921600
#define USART_BaudRate_2250000			2250000
#define USART_BaudRate_4500000			4500000

//-----------------------------
//@ref USART_Payload_def
//-----------------------------

#define USART_Payload_8B				(uint32_t)(0)
#define USART_Payload_9B				(uint32_t)(1<<12)

//-----------------------------
//@ref USART_Parity_def
//-----------------------------

#define USART_Parity_NONE				(uint32_t)(0)
#define USART_Parity_EVEN				(uint32_t)(1<<10)
#define USART_Parity_ODD				((uint32_t)(1<<10 | 1<<9))

//-----------------------------
//@ref USART_StopBit_def
//-----------------------------

#define USART_StopBit_half				(uint32_t)(1<<12)
#define USART_StopBit_1					(uint32_t)(0)
#define USART_StopBit_1_half			(uint32_t)(3<<12)
#define USART_StopBit_2					(uint32_t)(2<<12)

//-----------------------------
//@ref USART_HwFlowCtrl_def
//-----------------------------

#define USART_HwFlowCtrl_NONE			(uint32_t)(0)
#define USART_HwFlowCtrl_RTS			(uint32_t)(1<<8)
#define USART_HwFlowCtrl_CTS			(uint32_t)(1<<9)
#define USART_HwFlowCtrl_RTS_CTS		((uint32_t)(1<<8 | 1<<9))

//-----------------------------
//@ref USART_IRQ_EN_def
//-----------------------------

#define USART_IRQ_EN_NONE				(uint32_t)(0)
#define USART_IRQ_EN_TXE				(uint32_t)(1<<7)
#define USART_IRQ_EN_TC					(uint32_t)(1<<6)
#define USART_IRQ_EN_RXNEIE				(uint32_t)(1<<5)
#define USART_IRQ_EN_PE					(uint32_t)(1<<8)

enum PollingMechanism{enable, disable};

//====================================================================
//						BaudRate Calculations
//====================================================================

#define USARTDIV(_PCLK_, _BAUD_)			(uint32_t)(_PCLK_ / (16 * _BAUD_))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)		(uint32_t)((25 * _PCLK_) / (4 * _BAUD_))
#define Mantissa_MUL100(_PCLK_, _BAUD_)		(uint32_t)(USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)			(uint32_t)(USARTDIV(_PCLK_, _BAUD_))
#define DIV_FRACTION(_PCLK_, _BAUD_)		(uint32_t)(((USARTDIV_MUL100(_PCLK_, _BAUD_) - Mantissa_MUL100(_PCLK_, _BAUD_)) * 16) / 100)
#define UART_BRR_Register(_PCLK_, _BAUD_)	(((Mantissa(_PCLK_, _BAUD_)) << 4) | ((DIV_FRACTION(_PCLK_, _BAUD_)) & 0xF))

//====================================================================
//					APIs Supported by MCAL GPIO Driver
//====================================================================

void MCAL_UART_init(USART_t* UARTx, USART_Config_t* UART_Config);
void MCAL_UART_deinit(USART_t* UARTx);
void MCAL_UART_GPIO_SetPin(USART_t* UARTx);
void MCAL_UART_SendData(USART_t* UARTx, uint16_t* pTxBuffer, enum PollingMechanism PollingEn);
void MCAL_UART_ReceiveData(USART_t* UARTx, uint16_t* pRxBuffer, enum PollingMechanism PollingEn);
void MCAL_UART_WAIT_TC(USART_t* UARTx);

#endif /* INC_USART_H_ */

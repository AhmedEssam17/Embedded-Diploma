/*
 * usart.c
 *
 *  Created on: Jul 10, 2023
 *      Author: Lenovo
 */

#include "usart.h"

//====================================================================
//						Generic Variables
//====================================================================

USART_Config_t* GP_UART_Config = NULL;

//====================================================================
//						APIs Functions Definitions
//====================================================================

/**================================================================
 * @Fn				-MCAL_UART_init
 * @brief 			-Initializes UART (Asynchronous Only)
 * @param [in]	 	-UARTx: where x = (1,2,3)
 * @param [in] 		-UART_Config: Contains specified parameters for USART
 * @retval 			-NONE
 * Note				-Supports ASYNC Mode and 8MHZ Clock
 */
void MCAL_UART_init(USART_t* UARTx, USART_Config_t* UART_Config){

	GP_UART_Config = UART_Config;

	//-----------------------------
	//1) Enable Clock for given USART Peripheral
	//-----------------------------
	if(UARTx == USART1)
		RCC_USART1_CLK_ENABLE();
	else if(UARTx == USART2)
		RCC_USART2_CLK_ENABLE();
	else if(UARTx == USART3)
		RCC_USART3_CLK_ENABLE();

	//-----------------------------
	//2) Enable USART Module
	//-----------------------------
	UARTx->CR1 |= 1<<13;

	//-----------------------------
	//3) Enable TX/RX
	//-----------------------------
	UARTx->CR1 |= UART_Config->USART_MODE;

	//-----------------------------
	//4) Configure PayLoad Length
	//-----------------------------
	UARTx->CR1 |= UART_Config->USART_PayLoad;

	//-----------------------------
	//5) Configure Parity Mode
	//-----------------------------
	UARTx->CR1 |= UART_Config->USART_Parity;

	//-----------------------------
	//6) Configure number of Stop Bits
	//-----------------------------
	UARTx->CR2 |= UART_Config->USART_StopBit;

	//-----------------------------
	//7) Configure Hardware Flow Control
	//-----------------------------
	UARTx->CR3 |= UART_Config->USART_HwFlowCtrl;

	//-----------------------------
	//8) Configure BaudRate Register
	//-----------------------------
	uint32_t PCLK, BRR;
	if(UARTx == USART1)
		PCLK = MCAL_RCC_getPCLK2();
	else
		PCLK = MCAL_RCC_getPCLK1();

	BRR = UART_BRR_Register(PCLK, UART_Config->USART_BaudRate);
	UARTx->BRR = BRR;

	//-----------------------------
	//9) Configure IRQ
	//-----------------------------
	if(UART_Config->USART_IRQ_EN != USART_IRQ_EN_NONE){
		UARTx->CR1 |= UART_Config->USART_IRQ_EN;
		//Enable UARTx NVIC IRQ Mask
		if(UARTx == USART1)
			NVIC_IRQ37_USART1_Enable;
		else if(UARTx == USART2)
			NVIC_IRQ38_USART2_Enable;
		else if(UARTx == USART3)
			NVIC_IRQ39_USART3_Enable;
	}
}

/**================================================================
 * @Fn				-MCAL_UART_deinit
 * @brief 			-DeInitializes UART
 * @param [in]	 	-UARTx: where x = (1,2,3)
 * @retval 			-NONE
 * Note				-Resets by RCC
 */
void MCAL_UART_deinit(USART_t* UARTx){

	if(UARTx == USART1){
		RCC_USART1_CLK_RESET();
		NVIC_IRQ37_USART1_Disable;
	}
	else if(UARTx == USART2){
		RCC_USART2_CLK_RESET();
		NVIC_IRQ38_USART2_Disable;
	}
	else if(UARTx == USART3){
		RCC_USART3_CLK_RESET();
		NVIC_IRQ39_USART3_Disable;
	}
}

/**================================================================
 * @Fn				-MCAL_UART_GPIO_SetPin
 * @brief 			-Initializes GPIO Pins for UART
 * @param [in]	 	-UARTx: where x = (1,2,3)
 * @retval 			-NONE
 * Note				-Enables corresponding AFIO & GPIO in RCC Clock
 */
void MCAL_UART_GPIO_SetPin(USART_t* UARTx){

	GPIO_PinConfig_t PinConfig;

	if(UARTx == USART1){
		//PA9 TX
		PinConfig.GPIO_PinNumber = GPIO_PIN_9;
		PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
		MCAL_GPIO_init(GPIOA, &PinConfig);

		//PA10 RX
		PinConfig.GPIO_PinNumber = GPIO_PIN_10;
		PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
		MCAL_GPIO_init(GPIOA, &PinConfig);

		if(GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_CTS || GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_RTS_CTS){
			//PA11 CTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_11;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLOAT;
			MCAL_GPIO_init(GPIOA, &PinConfig);
		}

		if(GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_RTS || GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_RTS_CTS){
			//PA12 RTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_12;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
			MCAL_GPIO_init(GPIOA, &PinConfig);
		}
	}
	else if(UARTx == USART2){
		//PA2 TX
		PinConfig.GPIO_PinNumber = GPIO_PIN_2;
		PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
		MCAL_GPIO_init(GPIOA, &PinConfig);

		//PA3 RX
		PinConfig.GPIO_PinNumber = GPIO_PIN_3;
		PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
		MCAL_GPIO_init(GPIOA, &PinConfig);

		if(GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_CTS || GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_RTS_CTS){
			//PA0 CTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_0;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLOAT;
			MCAL_GPIO_init(GPIOA, &PinConfig);
		}

		if(GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_RTS || GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_RTS_CTS){
			//PA1 RTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_1;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
			MCAL_GPIO_init(GPIOA, &PinConfig);
		}
	}
	else if(UARTx == USART3){
		//PB10 TX
		PinConfig.GPIO_PinNumber = GPIO_PIN_10;
		PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
		PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
		MCAL_GPIO_init(GPIOB, &PinConfig);

		//PB11 RX
		PinConfig.GPIO_PinNumber = GPIO_PIN_11;
		PinConfig.GPIO_MODE = GPIO_MODE_INPUT_AF;
		MCAL_GPIO_init(GPIOB, &PinConfig);

		if(GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_CTS || GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_RTS_CTS){
			//PB13 CTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_13;
			PinConfig.GPIO_MODE = GPIO_MODE_INPUT_FLOAT;
			MCAL_GPIO_init(GPIOB, &PinConfig);
		}

		if(GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_RTS || GP_UART_Config->USART_HwFlowCtrl == USART_HwFlowCtrl_RTS_CTS){
			//PA14 RTS
			PinConfig.GPIO_PinNumber = GPIO_PIN_14;
			PinConfig.GPIO_MODE = GPIO_MODE_OUTPUT_AF_PP;
			PinConfig.GPIO_OUTPUT_SPEED = GPIO_OUTPUT_SPEED_10M;
			MCAL_GPIO_init(GPIOA, &PinConfig);
		}
	}
}

/**================================================================
 * @Fn				-MCAL_UART_SendData
 * @brief 			-Send Buffer on UART
 * @param [in]	 	-UARTx: where x = (1,2,3)
 * @param [in]	 	-pTxBuffer: Transmit Buffer
 * @param [in]	 	-PollingEn: Enable/Disable Polling
 * @retval 			-NONE
 * Note				-Should initialize UART first
 */
void MCAL_UART_SendData(USART_t* UARTx, uint16_t* pTxBuffer, enum PollingMechanism PollingEn){

	//-----------------------------
	//1) Wait until TXE Flag is set in SR
	//-----------------------------
	if(PollingEn == enable)
		while(!(UARTx->SR & 1<<7));

	//-----------------------------
	//2) Check PayLoad Length
	//-----------------------------
	if(GP_UART_Config->USART_PayLoad == USART_Payload_9B){
		UARTx->DR = (*pTxBuffer & (uint16_t)0x01FF);
	}
	else{
		UARTx->DR = (*pTxBuffer & (uint8_t)0xFF);
	}
}

/**================================================================
 * @Fn				-MCAL_UART_ReceiveData
 * @brief 			-Receive Buffer on UART
 * @param [in]	 	-UARTx: where x = (1,2,3)
 * @param [in]	 	-pRxBuffer: Receive Buffer
 * @param [in]	 	-PollingEn: Enable/Disable Polling
 * @retval 			-NONE
 * Note				-Should initialize UART first
 */
void MCAL_UART_ReceiveData(USART_t* UARTx, uint16_t* pRxBuffer, enum PollingMechanism PollingEn){

	//-----------------------------
	//1) Wait until RXNE Flag is set in SR
	//-----------------------------
	if(PollingEn == enable)
		while(!(UARTx->SR & 1<<5));

	//-----------------------------
	//2) Check PayLoad Length
	//-----------------------------
	if(GP_UART_Config->USART_PayLoad == USART_Payload_9B){
		//For 9 Bits
		if(GP_UART_Config->USART_Parity == USART_Parity_NONE){
			//No Parity == All 9 bits are Data
			*((uint16_t*)pRxBuffer) = UARTx->DR;
		}
		else{
			//Parity == Only 8 bits are Data
			*((uint16_t*)pRxBuffer) = (UARTx->DR & (uint8_t)0xFF);
		}
	}
	else{
		//For 8 Bits
		if(GP_UART_Config->USART_Parity == USART_Parity_NONE){
			//No Parity == All 8 bits are Data
			*((uint16_t*)pRxBuffer) = (UARTx->DR & (uint8_t)0xFF);
		}
		else{
			//Parity == Only 7 bits are Data
			*((uint16_t*)pRxBuffer) = (UARTx->DR & (uint8_t)0x7F);
		}
	}
}

/**================================================================
 * @Fn				-MCAL_UART_WAIT_TC
 * @brief 			-Check for TC Flag
 * @param [in]	 	-UARTx: where x = (1,2,3)
 * @retval 			-NONE
 * Note				-Wait until TC Flag to be set in SR
 */
void MCAL_UART_WAIT_TC(USART_t* UARTx){

	//Wait until TC Flag is set in SR
	while(!(UARTx->SR & 1<<6));
}

//====================================================================
//							ISR Functions
//====================================================================

void USART1_IRQHandler(void){
	GP_UART_Config->P_IRQ_CallBack();
}

void USART2_IRQHandler(void){
	GP_UART_Config->P_IRQ_CallBack();
}

void USART3_IRQHandler(void){
	GP_UART_Config->P_IRQ_CallBack();
}



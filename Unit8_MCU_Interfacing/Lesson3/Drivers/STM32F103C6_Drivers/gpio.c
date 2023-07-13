/*
 * gpio.c
 *
 *  Created on: May 3, 2023
 *      Author: AhmedEssam
 */

#include "gpio.h"


uint8_t Get_CRLH_Position(uint16_t PinNumber){
	switch(PinNumber){
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
}

/**================================================================
 * @Fn				-MCAL_GPIO_init
 * @brief 			-Initializes GPIOx PINy according to PinConfig specified parameters
 * @param [in]	 	-GPIOx: where x = (A,B,C,D,E)
 * @param [in] 		-PinConfig: Contains specified parameters for GPIO Pin
 * @retval 			-NONE
 * Note				-STM32F103C6 MCU has GPIO A..E but LQFP48 only has the following:
 * 					 GPIOA & GPIOB Fully included
 * 					 GPIOC & GPIOD Partially included
 * 					 GPIOE not included
 */
void MCAL_GPIO_init(GPIO_t *GPIOx, GPIO_PinConfig_t *PinConfig){
	volatile uint32_t *configRegister = NULL;
	uint8_t PIN_CONFIG = 0;

	configRegister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)? &GPIOx->CRL: &GPIOx->CRH;

	//Clear CNF & MODE
	(*configRegister) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber));

	//If PIN is OUTPUT
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) ||
			(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD))
	{
		PIN_CONFIG = ((((PinConfig->GPIO_MODE - 4) << 2) | PinConfig->GPIO_OUTPUT_SPEED) & 0x0F);
	}
	else //PIN is INPUT
	{
		if((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLOAT) || (PinConfig->GPIO_MODE == GPIO_MODE_ANALOG)){
			PIN_CONFIG = ((((PinConfig->GPIO_MODE - 4) << 2) | 0x0) & 0x0F);
		}
		else if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_AF){
			PIN_CONFIG = ((((GPIO_MODE_INPUT_FLOAT) << 2) | 0x0) & 0x0F);
		}
		else{
			PIN_CONFIG = ((((GPIO_MODE_INPUT_PU) << 2) | 0x0) & 0x0F);
			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU){
				//Input Pull-Up >> GPIOx->ODR = 1, Table 20: Port bit configuration table.
				GPIOx->ODR |= (PinConfig->GPIO_PinNumber);
			}
			else{
				//Input Pull-Down >> GPIOx->ODR = 0, Table 20: Port bit configuration table.
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}
	(*configRegister) |= (PIN_CONFIG  << Get_CRLH_Position(PinConfig->GPIO_PinNumber));
}


/**================================================================
 * @Fn				-MCAL_GPIO_deinit
 * @brief 			-Resets GPIOx registers
 * @param [in]	 	-GPIOx: where x = (A,B,C,D,E)
 * @retval 			-NONE
 * Note				-NONE
 */
void MCAL_GPIO_deinit(GPIO_t *GPIOx){
	//Use RCC Reset Registers
	//Set then cleared by software.
	if(GPIOx == GPIOA){
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB){
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC){
			RCC->APB2RSTR |= (1<<4);
			RCC->APB2RSTR &= ~(1<<4);
		}
	else if(GPIOx == GPIOD){
			RCC->APB2RSTR |= (1<<5);
			RCC->APB2RSTR &= ~(1<<5);
		}
	else if(GPIOx == GPIOE){
			RCC->APB2RSTR |= (1<<6);
			RCC->APB2RSTR &= ~(1<<6);
		}
}


/**================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief 			-Reads specific PIN value
 * @param [in]	 	-GPIOx: where x = (A,B,C,D,E)
 * @param [in]	 	-PinNumber: Set PinNumber based on @ref GPIO_PIN_def
 * @retval 			-PinValue: Input PIN value based on @ref GPIO_PIN_STATUS_def
 * Note				-NONE
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_t *GPIOx, uint16_t PinNumber){
	uint8_t bitValue;
	if((GPIOx->IDR & PinNumber) != (uint32_t)GPIO_PIN_RESET){
		bitValue = GPIO_PIN_SET;
	}
	else{
		bitValue = GPIO_PIN_RESET;
	}
	return bitValue;
}


/**================================================================
 * @Fn				-MCAL_GPIO_ReadPort
 * @brief 			-Reads PORT value
 * @param [in]	 	-GPIOx: where x = (A,B,C,D,E)
 * @retval 			-PortValue: Input PORT value
 * Note				-NONE
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_t *GPIOx){
	uint16_t portValue;
	portValue = (uint16_t)(GPIOx->IDR);
	return portValue;
}


/**================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief 			-Writes data on specific PIN
 * @param [in]	 	-GPIOx: where x = (A,B,C,D,E)
 * @param [in]	 	-PinNumber: Set PinNumber based on @ref GPIO_PIN_def
 * @param [in]	 	-data: value to be written on PIN
 * @retval 			-NONE
 * Note				-NONE
 */
void MCAL_GPIO_WritePin(GPIO_t *GPIOx, uint16_t PinNumber, uint8_t data){
	if(data != GPIO_PIN_RESET){
		GPIOx->ODR |= PinNumber;
	}
	else{
		GPIOx->ODR &= ~(PinNumber);
	}
}


/**================================================================
 * @Fn				-MCAL_GPIO_WritePort
 * @brief 			-Writes data on PORT
 * @param [in]	 	-GPIOx: where x = (A,B,C,D,E)
 * @param [in]	 	-data: value to be written on PORT
 * @retval 			-NONE
 * Note				-NONE
 */
void MCAL_GPIO_WritePort(GPIO_t *GPIOx, uint16_t data){
	GPIOx->ODR = (uint32_t)data;
}


/**================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief 			-Toggles specific PIN value
 * @param [in]	 	-GPIOx: where x = (A,B,C,D,E)
 * @param [in]	 	-PinNumber: Set PinNumber based on @ref GPIO_PIN_def
 * @retval 			-NONE
 * Note				-NONE
 */
void MCAL_GPIO_TogglePin(GPIO_t *GPIOx, uint16_t PinNumber){
	GPIOx->ODR ^= (PinNumber);
}

/**================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief 			-Locks specific PIN
 * @param [in]	 	-GPIOx: where x = (A,B,C,D,E)
 * @param [in]	 	-PinNumber: Set PinNumber based on @ref GPIO_PIN_def
 * @retval 			-LockStatus: Status of Lock based on @ref GPIO_PIN_LOCK_STATUS_def
 * Note				-NONE
 */
uint8_t MCAL_GPIO_LockPin(GPIO_t *GPIOx, uint16_t PinNumber){
	//Set LCKK
	volatile uint32_t temp = 1<<16;
	//Set LCKy
	temp |= PinNumber;
	//Write 1
	GPIOx->LCKR = temp;
	//Write 0
	GPIOx->LCKR = PinNumber;
	//Write 1
	GPIOx->LCKR = temp;
	//Read 0
	temp = GPIOx->LCKR;
	//Read 1 (this read is optional but confirms that the lock is active)
	if((uint32_t)GPIOx->LCKR & (1<<16)){
		return GPIO_PIN_LOCK_SUCCESS;
	}
	else{
		return GPIO_PIN_LOCK_FAILED;
	}
}



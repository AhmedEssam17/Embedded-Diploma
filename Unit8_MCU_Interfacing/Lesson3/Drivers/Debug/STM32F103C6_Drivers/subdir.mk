################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/exti.c \
../STM32F103C6_Drivers/gpio.c \
../STM32F103C6_Drivers/rcc.c \
../STM32F103C6_Drivers/usart.c 

OBJS += \
./STM32F103C6_Drivers/exti.o \
./STM32F103C6_Drivers/gpio.o \
./STM32F103C6_Drivers/rcc.o \
./STM32F103C6_Drivers/usart.o 

C_DEPS += \
./STM32F103C6_Drivers/exti.d \
./STM32F103C6_Drivers/gpio.d \
./STM32F103C6_Drivers/rcc.d \
./STM32F103C6_Drivers/usart.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/exti.o: ../STM32F103C6_Drivers/exti.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/HAL_Drivers/inc" -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/exti.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/gpio.o: ../STM32F103C6_Drivers/gpio.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/HAL_Drivers/inc" -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/rcc.o: ../STM32F103C6_Drivers/rcc.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/HAL_Drivers/inc" -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/rcc.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/usart.o: ../STM32F103C6_Drivers/usart.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/HAL_Drivers/inc" -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/usart.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


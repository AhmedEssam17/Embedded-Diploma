################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_Drivers/keypad.c \
../HAL_Drivers/lcd.c 

OBJS += \
./HAL_Drivers/keypad.o \
./HAL_Drivers/lcd.o 

C_DEPS += \
./HAL_Drivers/keypad.d \
./HAL_Drivers/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_Drivers/keypad.o: ../HAL_Drivers/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/HAL_Drivers/inc" -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL_Drivers/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL_Drivers/lcd.o: ../HAL_Drivers/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/HAL_Drivers/inc" -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson4/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL_Drivers/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


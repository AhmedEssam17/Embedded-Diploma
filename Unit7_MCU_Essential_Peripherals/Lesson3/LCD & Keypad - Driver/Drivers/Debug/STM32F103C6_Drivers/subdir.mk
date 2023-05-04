################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_Drivers/gpio.c \
../STM32F103C6_Drivers/keypad.c \
../STM32F103C6_Drivers/lcd.c 

OBJS += \
./STM32F103C6_Drivers/gpio.o \
./STM32F103C6_Drivers/keypad.o \
./STM32F103C6_Drivers/lcd.o 

C_DEPS += \
./STM32F103C6_Drivers/gpio.d \
./STM32F103C6_Drivers/keypad.d \
./STM32F103C6_Drivers/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_Drivers/gpio.o: ../STM32F103C6_Drivers/gpio.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson3/LCD & Keypad - Driver/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/gpio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/keypad.o: ../STM32F103C6_Drivers/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson3/LCD & Keypad - Driver/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_Drivers/lcd.o: ../STM32F103C6_Drivers/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Embedded Systems Diploma/Embedded Diploma/Unit7_MCU_Essential_Peripherals/Lesson3/LCD & Keypad - Driver/Drivers/STM32F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_Drivers/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


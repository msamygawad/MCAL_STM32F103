################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/github/MCAL_STM32F103/_src/usart/usart.c 

OBJS += \
./_src/usart/usart.o 

C_DEPS += \
./_src/usart/usart.d 


# Each subdirectory must supply rules for building sources it contributes
_src/usart/usart.o: C:/github/MCAL_STM32F103/_src/usart/usart.c _src/usart/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Werror -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F103x6 -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



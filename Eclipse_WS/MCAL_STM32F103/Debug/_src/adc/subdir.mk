################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/github/MCAL_STM32F103/_src/adc/adc.c 

OBJS += \
./_src/adc/adc.o 

C_DEPS += \
./_src/adc/adc.d 


# Each subdirectory must supply rules for building sources it contributes
_src/adc/adc.o: C:/github/MCAL_STM32F103/_src/adc/adc.c _src/adc/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-move-loop-invariants -Werror -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F103x6 -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



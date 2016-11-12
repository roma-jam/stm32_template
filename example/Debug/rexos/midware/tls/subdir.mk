################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projects/template/rexos/midware/tls/tls_cipher.c \
D:/Projects/template/rexos/midware/tls/tlss.c 

OBJS += \
./rexos/midware/tls/tls_cipher.o \
./rexos/midware/tls/tlss.o 

C_DEPS += \
./rexos/midware/tls/tls_cipher.d \
./rexos/midware/tls/tlss.d 


# Each subdirectory must supply rules for building sources it contributes
rexos/midware/tls/tls_cipher.o: D:/Projects/template/rexos/midware/tls/tls_cipher.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/midware/tls/tlss.o: D:/Projects/template/rexos/midware/tls/tlss.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



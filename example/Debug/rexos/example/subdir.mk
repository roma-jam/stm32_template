################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projects/template/rexos/example/app.c \
D:/Projects/template/rexos/example/comm.c \
D:/Projects/template/rexos/example/net.c 

OBJS += \
./rexos/example/app.o \
./rexos/example/comm.o \
./rexos/example/net.o 

C_DEPS += \
./rexos/example/app.d \
./rexos/example/comm.d \
./rexos/example/net.d 


# Each subdirectory must supply rules for building sources it contributes
rexos/example/app.o: D:/Projects/template/rexos/example/app.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/example/comm.o: D:/Projects/template/rexos/example/comm.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/example/net.o: D:/Projects/template/rexos/example/net.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



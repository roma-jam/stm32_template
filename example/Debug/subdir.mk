################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../app.c \
../comm.c \
../net.c 

OBJS += \
./app.o \
./comm.o \
./net.o 

C_DEPS += \
./app.d \
./comm.d \
./net.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



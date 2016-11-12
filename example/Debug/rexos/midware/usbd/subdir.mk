################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projects/template/rexos/midware/usbd/ccidd.c \
D:/Projects/template/rexos/midware/usbd/cdc_acmd.c \
D:/Projects/template/rexos/midware/usbd/hidd_kbd.c \
D:/Projects/template/rexos/midware/usbd/mscd.c \
D:/Projects/template/rexos/midware/usbd/rndisd.c \
D:/Projects/template/rexos/midware/usbd/usbd.c 

OBJS += \
./rexos/midware/usbd/ccidd.o \
./rexos/midware/usbd/cdc_acmd.o \
./rexos/midware/usbd/hidd_kbd.o \
./rexos/midware/usbd/mscd.o \
./rexos/midware/usbd/rndisd.o \
./rexos/midware/usbd/usbd.o 

C_DEPS += \
./rexos/midware/usbd/ccidd.d \
./rexos/midware/usbd/cdc_acmd.d \
./rexos/midware/usbd/hidd_kbd.d \
./rexos/midware/usbd/mscd.d \
./rexos/midware/usbd/rndisd.d \
./rexos/midware/usbd/usbd.d 


# Each subdirectory must supply rules for building sources it contributes
rexos/midware/usbd/ccidd.o: D:/Projects/template/rexos/midware/usbd/ccidd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/midware/usbd/cdc_acmd.o: D:/Projects/template/rexos/midware/usbd/cdc_acmd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/midware/usbd/hidd_kbd.o: D:/Projects/template/rexos/midware/usbd/hidd_kbd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/midware/usbd/mscd.o: D:/Projects/template/rexos/midware/usbd/mscd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/midware/usbd/rndisd.o: D:/Projects/template/rexos/midware/usbd/rndisd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/midware/usbd/usbd.o: D:/Projects/template/rexos/midware/usbd/usbd.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



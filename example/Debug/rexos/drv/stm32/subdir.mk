################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projects/template/rexos/drv/stm32/stm32_adc.c \
D:/Projects/template/rexos/drv/stm32/stm32_core.c \
D:/Projects/template/rexos/drv/stm32/stm32_dac.c \
D:/Projects/template/rexos/drv/stm32/stm32_eep.c \
D:/Projects/template/rexos/drv/stm32/stm32_eth.c \
D:/Projects/template/rexos/drv/stm32/stm32_i2c.c \
D:/Projects/template/rexos/drv/stm32/stm32_otg.c \
D:/Projects/template/rexos/drv/stm32/stm32_pin.c \
D:/Projects/template/rexos/drv/stm32/stm32_power.c \
D:/Projects/template/rexos/drv/stm32/stm32_rtc.c \
D:/Projects/template/rexos/drv/stm32/stm32_timer.c \
D:/Projects/template/rexos/drv/stm32/stm32_uart.c \
D:/Projects/template/rexos/drv/stm32/stm32_usb.c \
D:/Projects/template/rexos/drv/stm32/stm32_usb_f103xx.c \
D:/Projects/template/rexos/drv/stm32/stm32_wdt.c 

OBJS += \
./rexos/drv/stm32/stm32_adc.o \
./rexos/drv/stm32/stm32_core.o \
./rexos/drv/stm32/stm32_dac.o \
./rexos/drv/stm32/stm32_eep.o \
./rexos/drv/stm32/stm32_eth.o \
./rexos/drv/stm32/stm32_i2c.o \
./rexos/drv/stm32/stm32_otg.o \
./rexos/drv/stm32/stm32_pin.o \
./rexos/drv/stm32/stm32_power.o \
./rexos/drv/stm32/stm32_rtc.o \
./rexos/drv/stm32/stm32_timer.o \
./rexos/drv/stm32/stm32_uart.o \
./rexos/drv/stm32/stm32_usb.o \
./rexos/drv/stm32/stm32_usb_f103xx.o \
./rexos/drv/stm32/stm32_wdt.o 

C_DEPS += \
./rexos/drv/stm32/stm32_adc.d \
./rexos/drv/stm32/stm32_core.d \
./rexos/drv/stm32/stm32_dac.d \
./rexos/drv/stm32/stm32_eep.d \
./rexos/drv/stm32/stm32_eth.d \
./rexos/drv/stm32/stm32_i2c.d \
./rexos/drv/stm32/stm32_otg.d \
./rexos/drv/stm32/stm32_pin.d \
./rexos/drv/stm32/stm32_power.d \
./rexos/drv/stm32/stm32_rtc.d \
./rexos/drv/stm32/stm32_timer.d \
./rexos/drv/stm32/stm32_uart.d \
./rexos/drv/stm32/stm32_usb.d \
./rexos/drv/stm32/stm32_usb_f103xx.d \
./rexos/drv/stm32/stm32_wdt.d 


# Each subdirectory must supply rules for building sources it contributes
rexos/drv/stm32/stm32_adc.o: D:/Projects/template/rexos/drv/stm32/stm32_adc.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_core.o: D:/Projects/template/rexos/drv/stm32/stm32_core.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_dac.o: D:/Projects/template/rexos/drv/stm32/stm32_dac.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_eep.o: D:/Projects/template/rexos/drv/stm32/stm32_eep.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_eth.o: D:/Projects/template/rexos/drv/stm32/stm32_eth.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_i2c.o: D:/Projects/template/rexos/drv/stm32/stm32_i2c.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_otg.o: D:/Projects/template/rexos/drv/stm32/stm32_otg.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_pin.o: D:/Projects/template/rexos/drv/stm32/stm32_pin.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_power.o: D:/Projects/template/rexos/drv/stm32/stm32_power.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_rtc.o: D:/Projects/template/rexos/drv/stm32/stm32_rtc.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_timer.o: D:/Projects/template/rexos/drv/stm32/stm32_timer.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_uart.o: D:/Projects/template/rexos/drv/stm32/stm32_uart.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_usb.o: D:/Projects/template/rexos/drv/stm32/stm32_usb.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_usb_f103xx.o: D:/Projects/template/rexos/drv/stm32/stm32_usb_f103xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/drv/stm32/stm32_wdt.o: D:/Projects/template/rexos/drv/stm32/stm32_wdt.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



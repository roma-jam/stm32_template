################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projects/template/rexos/kernel/core/karm7.c \
D:/Projects/template/rexos/kernel/core/kcortexm.c 

S_UPPER_SRCS += \
D:/Projects/template/rexos/kernel/core/startup_arm7.S \
D:/Projects/template/rexos/kernel/core/startup_cortexm.S 

OBJS += \
./rexos/kernel/core/karm7.o \
./rexos/kernel/core/kcortexm.o \
./rexos/kernel/core/startup_arm7.o \
./rexos/kernel/core/startup_cortexm.o 

S_UPPER_DEPS += \
./rexos/kernel/core/startup_arm7.d \
./rexos/kernel/core/startup_cortexm.d 

C_DEPS += \
./rexos/kernel/core/karm7.d \
./rexos/kernel/core/kcortexm.d 


# Each subdirectory must supply rules for building sources it contributes
rexos/kernel/core/karm7.o: D:/Projects/template/rexos/kernel/core/karm7.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/kernel/core/kcortexm.o: D:/Projects/template/rexos/kernel/core/kcortexm.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F103C8 -I../ -I../../ -I../../rexos -I../../rexos/kernel/core -I../../rexos/drv/stm32 -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/kernel/core/startup_arm7.o: D:/Projects/template/rexos/kernel/core/startup_arm7.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -I../../rexos/kernel/core -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/kernel/core/startup_cortexm.o: D:/Projects/template/rexos/kernel/core/startup_cortexm.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -I../../rexos/kernel/core -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
D:/Projects/template/rexos/userspace/core/arm7.S \
D:/Projects/template/rexos/userspace/core/cortexm.S 

OBJS += \
./rexos/userspace/core/arm7.o \
./rexos/userspace/core/cortexm.o 

S_UPPER_DEPS += \
./rexos/userspace/core/arm7.d \
./rexos/userspace/core/cortexm.d 


# Each subdirectory must supply rules for building sources it contributes
rexos/userspace/core/arm7.o: D:/Projects/template/rexos/userspace/core/arm7.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -I../../rexos/kernel/core -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

rexos/userspace/core/cortexm.o: D:/Projects/template/rexos/userspace/core/cortexm.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -I../../rexos/kernel/core -I../../rexos/3rdparty/CMSIS/Device/ST/STM32F10x/Include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



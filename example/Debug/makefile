################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include rexos/userspace/stm32/subdir.mk
-include rexos/userspace/lpc/subdir.mk
-include rexos/userspace/core/subdir.mk
-include rexos/userspace/subdir.mk
-include rexos/midware/usbd/subdir.mk
-include rexos/midware/tls/subdir.mk
-include rexos/midware/tcpips/subdir.mk
-include rexos/midware/scsis/subdir.mk
-include rexos/midware/http/subdir.mk
-include rexos/midware/fs/subdir.mk
-include rexos/midware/crypto/subdir.mk
-include rexos/midware/subdir.mk
-include rexos/lib/subdir.mk
-include rexos/kernel/core/subdir.mk
-include rexos/kernel/subdir.mk
-include rexos/example/subdir.mk
-include rexos/drv/stm32/subdir.mk
-include rexos/drv/lpc/subdir.mk
-include rexos/drv/subdir.mk
-include build/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
example.hex \

SECONDARY_SIZE += \
example.siz \


# All Target
all: example.elf secondary-outputs

# Tool invocations
example.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -Xlinker --gc-sections -Wl,-Map,"example.map" -o "example.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

example.hex: example.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O ihex "example.elf"  "example.hex"
	@echo 'Finished building: $@'
	@echo ' '

example.siz: example.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "example.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) example.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

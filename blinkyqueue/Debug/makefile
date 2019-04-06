################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: blinkyqueue.axf

# Tool invocations
blinkyqueue.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/dhruvita/work/ese_3025_2/lpc_board_nxp_lpcxpresso_1769/Debug" -L"/home/dhruvita/work/ese_3025_2/lpc_chip_175x_6x/Debug" -Xlinker -Map="blinkyqueue.map" -Xlinker --gc-sections -Xlinker -print-memory-usage -mcpu=cortex-m3 -mthumb -T "blinkyqueue_Debug.ld" -o "blinkyqueue.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) blinkyqueue.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "blinkyqueue.axf"; # arm-none-eabi-objcopy -v -O binary "blinkyqueue.axf" "blinkyqueue.bin" ; # checksum -p LPC1769 -d "blinkyqueue.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets

################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EHAL/TEMPERATURE_SENSOR/temperature_sensor.c 

OBJS += \
./src/EHAL/TEMPERATURE_SENSOR/temperature_sensor.o 

C_DEPS += \
./src/EHAL/TEMPERATURE_SENSOR/temperature_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
src/EHAL/TEMPERATURE_SENSOR/%.o: ../src/EHAL/TEMPERATURE_SENSOR/%.c src/EHAL/TEMPERATURE_SENSOR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



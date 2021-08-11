################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../entradasalida/entradaysalida.c 

OBJS += \
./entradasalida/entradaysalida.o 

C_DEPS += \
./entradasalida/entradaysalida.d 


# Each subdirectory must supply rules for building sources it contributes
entradasalida/%.o: ../entradasalida/%.c entradasalida/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



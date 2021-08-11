################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Guia\ 2/arreglos.c 

OBJS += \
./Guia\ 2/arreglos.o 

C_DEPS += \
./Guia\ 2/arreglos.d 


# Each subdirectory must supply rules for building sources it contributes
Guia\ 2/arreglos.o: ../Guia\ 2/arreglos.c Guia\ 2/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Guia 2/arreglos.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



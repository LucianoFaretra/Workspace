################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../accesso_dati.c \
../elaborazione.c \
../input.c \
../main.c \
../output.c 

OBJS += \
./accesso_dati.o \
./elaborazione.o \
./input.o \
./main.o \
./output.o 

C_DEPS += \
./accesso_dati.d \
./elaborazione.d \
./input.d \
./main.d \
./output.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



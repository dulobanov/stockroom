################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../kernel/c_logact.cpp \
../kernel/c_summary.cpp \
../kernel/ma_log.cpp 

OBJS += \
./kernel/c_logact.o \
./kernel/c_summary.o \
./kernel/ma_log.o 

CPP_DEPS += \
./kernel/c_logact.d \
./kernel/c_summary.d \
./kernel/ma_log.d 


# Each subdirectory must supply rules for building sources it contributes
kernel/%.o: ../kernel/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../dialogs/add_item/add_item.cpp 

OBJS += \
./dialogs/add_item/add_item.o 

CPP_DEPS += \
./dialogs/add_item/add_item.d 


# Each subdirectory must supply rules for building sources it contributes
dialogs/add_item/%.o: ../dialogs/add_item/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



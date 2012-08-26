################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/kernel.cpp \
../src/login.cpp \
../src/main.cpp \
../src/mainwindowimpl.cpp \
../src/registration.cpp \
../src/settings.cpp 

OBJS += \
./src/kernel.o \
./src/login.o \
./src/main.o \
./src/mainwindowimpl.o \
./src/registration.o \
./src/settings.o 

CPP_DEPS += \
./src/kernel.d \
./src/login.d \
./src/main.d \
./src/mainwindowimpl.d \
./src/registration.d \
./src/settings.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



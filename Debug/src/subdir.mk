################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/baseapp.cpp \
../src/functions.cpp 

C_SRCS += \
../src/sqlite3.c 

OBJS += \
./src/baseapp.o \
./src/functions.o \
./src/sqlite3.o 

CPP_DEPS += \
./src/baseapp.d \
./src/functions.d 

C_DEPS += \
./src/sqlite3.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



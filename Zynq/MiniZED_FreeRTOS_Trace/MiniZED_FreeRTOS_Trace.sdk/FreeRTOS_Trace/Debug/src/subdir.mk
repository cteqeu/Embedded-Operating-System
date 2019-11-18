################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/freertos_hello_world.c \
../src/trcKernelPort.c \
../src/trcSnapshotRecorder.c \
../src/trcStreamingRecorder.c 

OBJS += \
./src/freertos_hello_world.o \
./src/trcKernelPort.o \
./src/trcSnapshotRecorder.o \
./src/trcStreamingRecorder.o 

C_DEPS += \
./src/freertos_hello_world.d \
./src/trcKernelPort.d \
./src/trcSnapshotRecorder.d \
./src/trcStreamingRecorder.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -I"C:\Users\20002890\MiniZED_FreeRTOS_Trace\MiniZED_FreeRTOS_Trace.sdk\FreeRTOS_Trace\freertos10_xilinx_v1_3\src" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../FreeRTOS_Trace_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



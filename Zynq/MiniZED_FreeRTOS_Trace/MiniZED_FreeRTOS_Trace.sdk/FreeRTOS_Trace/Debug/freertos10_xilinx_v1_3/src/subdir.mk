################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos10_xilinx_v1_3/src/event_groups.c \
../freertos10_xilinx_v1_3/src/heap_4.c \
../freertos10_xilinx_v1_3/src/inbyte.c \
../freertos10_xilinx_v1_3/src/list.c \
../freertos10_xilinx_v1_3/src/outbyte.c \
../freertos10_xilinx_v1_3/src/port.c \
../freertos10_xilinx_v1_3/src/portZynq7000.c \
../freertos10_xilinx_v1_3/src/queue.c \
../freertos10_xilinx_v1_3/src/tasks.c \
../freertos10_xilinx_v1_3/src/timers.c 

S_UPPER_SRCS += \
../freertos10_xilinx_v1_3/src/portASM.S \
../freertos10_xilinx_v1_3/src/port_asm_vectors.S 

O_SRCS += \
../freertos10_xilinx_v1_3/src/portASM.o \
../freertos10_xilinx_v1_3/src/port_asm_vectors.o 

OBJS += \
./freertos10_xilinx_v1_3/src/event_groups.o \
./freertos10_xilinx_v1_3/src/heap_4.o \
./freertos10_xilinx_v1_3/src/inbyte.o \
./freertos10_xilinx_v1_3/src/list.o \
./freertos10_xilinx_v1_3/src/outbyte.o \
./freertos10_xilinx_v1_3/src/port.o \
./freertos10_xilinx_v1_3/src/portASM.o \
./freertos10_xilinx_v1_3/src/portZynq7000.o \
./freertos10_xilinx_v1_3/src/port_asm_vectors.o \
./freertos10_xilinx_v1_3/src/queue.o \
./freertos10_xilinx_v1_3/src/tasks.o \
./freertos10_xilinx_v1_3/src/timers.o 

S_UPPER_DEPS += \
./freertos10_xilinx_v1_3/src/portASM.d \
./freertos10_xilinx_v1_3/src/port_asm_vectors.d 

C_DEPS += \
./freertos10_xilinx_v1_3/src/event_groups.d \
./freertos10_xilinx_v1_3/src/heap_4.d \
./freertos10_xilinx_v1_3/src/inbyte.d \
./freertos10_xilinx_v1_3/src/list.d \
./freertos10_xilinx_v1_3/src/outbyte.d \
./freertos10_xilinx_v1_3/src/port.d \
./freertos10_xilinx_v1_3/src/portZynq7000.d \
./freertos10_xilinx_v1_3/src/queue.d \
./freertos10_xilinx_v1_3/src/tasks.d \
./freertos10_xilinx_v1_3/src/timers.d 


# Each subdirectory must supply rules for building sources it contributes
freertos10_xilinx_v1_3/src/%.o: ../freertos10_xilinx_v1_3/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -I"C:\Users\20002890\MiniZED_FreeRTOS_Trace\MiniZED_FreeRTOS_Trace.sdk\FreeRTOS_Trace\freertos10_xilinx_v1_3\src" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../FreeRTOS_Trace_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

freertos10_xilinx_v1_3/src/%.o: ../freertos10_xilinx_v1_3/src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -I"C:\Users\20002890\MiniZED_FreeRTOS_Trace\MiniZED_FreeRTOS_Trace.sdk\FreeRTOS_Trace\freertos10_xilinx_v1_3\src" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../FreeRTOS_Trace_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



cmake_minimum_required(VERSION 2.8)

# specify AVR specific parameters
set(AVR_MCU "atmega328p")

set(AVR_UPLOAD_BAUD 115200)
set(AVR_UPLOAD_PROGRAMMER "arduino")

if(NOT AVR_UPLOAD_PORT)
	set(AVR_UPLOAD_PORT "/dev/ttyACM0")
endif(NOT AVR_UPLOAD_PORT)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/avr-gcc.toolchain.cmake")

project(Test1)

add_definitions(-DF_CPU=16000000)

include_directories(
    src/include/
    thirdparty/FreeRTOS-Kernel/FreeRTOS/Source/include/
    thirdparty/FreeRTOS-Kernel/FreeRTOS/Source/portable/GCC/ATMega328p/
#	src/cpp/
#	src/
#	...
)

add_avr_executable(${PROJECT_NAME}
    src/main.c

    # FreeRTOS
    thirdparty/FreeRTOS-Kernel/FreeRTOS/Source/croutine.c
    thirdparty/FreeRTOS-Kernel/FreeRTOS/Source/event_groups.c
    thirdparty/FreeRTOS-Kernel/FreeRTOS/Source/list.c
    thirdparty/FreeRTOS-Kernel/FreeRTOS/Source/queue.c
    thirdparty/FreeRTOS-Kernel/FreeRTOS/Source/stream_buffer.c
    thirdparty/FreeRTOS-Kernel/FreeRTOS/Source/tasks.c
    thirdparty/FreeRTOS-Kernel/FreeRTOS/Source/timers.c
    thirdparty/FreeRTOS-Kernel/FreeRTOS/Source/portable/MemMang/heap_1.c
    thirdparty/FreeRTOS-Kernel/FreeRTOS/Source/portable/GCC/ATMega328p/port.c
    
    # avros
#    src/avros/scheduler.cpp
#    src/avros/schedulingstrategy.cpp
#    src/avros/thread.cpp
#    src/avros/message.cpp
)

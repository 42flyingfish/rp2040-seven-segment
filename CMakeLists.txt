cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(sevenSegment LANGUAGES C CXX ASM)


set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
pico_sdk_init()

add_executable(sevenSegment main.cpp)

pico_enable_stdio_usb(sevenSegment 1)
pico_enable_stdio_uart(sevenSegment 1)
pico_add_extra_outputs(sevenSegment)

target_link_libraries(sevenSegment pico_stdlib)

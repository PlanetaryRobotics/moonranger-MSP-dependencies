cmake_minimum_required(VERSION 3.5)

project(msp430fr5_driverlib LANGUAGES C)

set(DRIVERLIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/MSP430FR5xx_6xx)
set(DRIVERLIB_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/MSP430FR5xx_6xx)
file(GLOB DRIVERLIB_SOURCES ${DRIVERLIB_DIR}/*.c)

add_library(
    msp430fr5_driverlib
    ${DRIVERLIB_SOURCES})
target_include_directories(
    msp430fr5_driverlib
    PUBLIC
    ${DRIVERLIB_INCLUDE})
target_compile_options(
    msp430fr5_driverlib
    PRIVATE
    # Pointer-integer casting required when working with registers
    -Wno-int-to-pointer-cast)

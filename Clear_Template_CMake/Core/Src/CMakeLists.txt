cmake_minimum_required(VERSION 3.13)

target_sources(${FILE_ELF}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/syscalls.c
        ${CMAKE_CURRENT_LIST_DIR}/sysmem.c
)

target_include_directories(${FILE_ELF}
    PUBLIC
        ${PROJECT_SOURCE_DIR}/Core/Inc
        ${PROJECT_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32F4xx/Include
        ${PROJECT_SOURCE_DIR}/Drivers/CMSIS/Include
)
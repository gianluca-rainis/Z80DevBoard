cmake_minimum_required(VERSION 3.13)
set(PICO_SDK_PATH ${CMAKE_CURRENT_LIST_DIR}/pico-sdk)
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(Z80DevBoard C CXX ASM)
pico_sdk_init()

add_executable(Z80DevBoard
	main.c
	firmware.c
)
target_link_libraries(Z80DevBoard pico_stdlib)
pico_add_extra_outputs(Z80DevBoard)
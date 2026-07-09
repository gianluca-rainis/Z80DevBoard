cmake_minimum_required(VERSION 3.13)

if("${PICO_TOOLCHAIN_PATH}" STREQUAL "")
	if(DEFINED ENV{PICO_TOOLCHAIN_PATH} AND NOT "$ENV{PICO_TOOLCHAIN_PATH}" STREQUAL "")
		set(PICO_TOOLCHAIN_PATH "$ENV{PICO_TOOLCHAIN_PATH}")
	elseif(EXISTS "$ENV{USERPROFILE}/.pico-sdk/toolchain/13_2_Rel1/bin/arm-none-eabi-gcc.exe")
		set(PICO_TOOLCHAIN_PATH "$ENV{USERPROFILE}/.pico-sdk/toolchain/13_2_Rel1")
	endif()
endif()

if(DEFINED PICO_TOOLCHAIN_PATH AND NOT "${PICO_TOOLCHAIN_PATH}" STREQUAL "")
	set(PICO_TOOLCHAIN_PATH "${PICO_TOOLCHAIN_PATH}" CACHE PATH "Path to ARM GNU toolchain" FORCE)
	set(ENV{PICO_TOOLCHAIN_PATH} "${PICO_TOOLCHAIN_PATH}")
endif()

if(CMAKE_GENERATOR STREQUAL "MinGW Makefiles" AND "${CMAKE_MAKE_PROGRAM}" STREQUAL "")
	find_program(MINGW_MAKE_EXE
		NAMES mingw32-make.exe mingw32-make
		HINTS C:/msys64/ucrt64/bin C:/msys64/mingw64/bin
	)
	if(MINGW_MAKE_EXE)
		set(CMAKE_MAKE_PROGRAM "${MINGW_MAKE_EXE}" CACHE FILEPATH "MinGW make program" FORCE)
	endif()
endif()

set(PICO_SDK_PATH ${CMAKE_CURRENT_LIST_DIR}/pico-sdk)
include(${PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(Z80DevBoard C CXX ASM)
pico_sdk_init()

add_executable(Z80DevBoard
	main.c
	firmware.c
	flash.c
	uart.c
	mscDisk.c
	usb_descriptors.c
)

target_include_directories(Z80DevBoard PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(Z80DevBoard
	pico_stdlib
	hardware_flash
	tinyusb_device
	tinyusb_board
    pico_stdio_usb
)

pico_enable_stdio_usb(Z80DevBoard 1)
pico_enable_stdio_uart(Z80DevBoard 0)

set_source_files_properties(
    ${PICO_SDK_PATH}/src/rp2_common/pico_stdio_usb/stdio_usb_descriptors.c
    PROPERTIES HEADER_FILE_ONLY TRUE
)

pico_add_extra_outputs(Z80DevBoard)

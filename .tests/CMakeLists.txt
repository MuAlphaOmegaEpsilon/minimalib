cmake_minimum_required(VERSION 3.16.2)
project(minimalib-tests LANGUAGES CXX)

include(CTest)
include_directories(..)

set(BUILD_TESTING ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_LINK_WHAT_YOU_USE TRUE)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)

if(WIN32)
else()
	add_compile_options(
	-Wall
	-Warray-bounds
	-Wcast-align
	-Wcast-qual
	-Wchar-subscripts
	-Wcomment
	-Wconversion
	-Wdisabled-optimization
	-Wdouble-promotion
	-Weffc++
	-Wextra
	-Wfloat-equal
	-Wformat=2
	-Wformat-nonliteral
	-Wformat-overflow=2
	-Wformat-security
	-Wformat-signedness
	-Wformat-truncation=1
	-Wformat-y2k
	-Wimplicit-fallthrough
	-Wimport
	-Winit-self
	-Winvalid-pch
	-Wmisleading-indentation
	-Wmissing-braces
	-Wmissing-field-initializers
	-Wmissing-format-attribute
	-Wmissing-include-dirs
	-Wmissing-noreturn
	-Wno-unused-const-variable
	-Wno-unused-function
	-Wnull-dereference
	-Wpacked
	-Wparentheses
	-Wpedantic
	-Wpointer-arith
	-Wredundant-decls
	-Wreturn-type
	-Wsequence-point
	-Wshadow
	-Wshift-overflow
	-Wsign-compare
	-Wstack-protector
	-Wstrict-aliasing=1
	-Wstrict-aliasing
	-Wstrict-aliasing=2
	-Wstrict-overflow=5
	-Wstringop-overflow=4
	-Wswitch
	-Wswitch-default
	-Wswitch-enum
	-Wtautological-compare
	-Wtrigraphs
	-Wuninitialized
	-Wunknown-pragmas
	-Wunreachable-code
	-Wunsafe-loop-optimizations
	-Wunused
	-Wunused-function
	-Wunused-label
	-Wunused-parameter
	-Wunused-value
	-Wunused-variable
	-Wvariadic-macros
	-Wvolatile-register-var
	-Wwrite-strings
	)

	add_compile_options(-ggdb -fno-stack-protector -ffreestanding -ffunction-sections -fdata-sections -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-rtti -fno-exceptions)
	add_link_options(-nostdlib -s -no-pie -Wl,-n -Wl,--build-id=none)
	add_link_options(-Wl,-gc-sections)
endif()

add_executable(entrypoint_start entrypoint_start.cpp)
add_test("entrypoint\/start.hpp" entrypoint_start)


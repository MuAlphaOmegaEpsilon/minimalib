cmake_minimum_required(VERSION 3.16.2)
project(minimalib-tests LANGUAGES CXX ASM)

include(CTest)
include_directories(..)

set(BUILD_TESTING ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

# Add compilation flags
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
  -Wformat-security
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
  -Wswitch
  -Wswitch-default
  -Wswitch-enum
  -Wtautological-compare
  -Wtrigraphs
  -Wuninitialized
  -Wunknown-pragmas
  -Wunreachable-code
  -Wunused
  -Wunused-function
  -Wunused-label
  -Wunused-parameter
  -Wunused-value
  -Wunused-variable
  -Wvariadic-macros
  -Wvolatile-register-var
  -Wwrite-strings)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(
    -Wformat-overflow=2 -Wformat-signedness -Wformat-truncation=1
    -Wstringop-overflow=4 -Wunsafe-loop-optimizations)
endif()

# Allow compilation without glibc
add_compile_options(
  -fdata-sections
  -ffreestanding
  -ffunction-sections
  -fno-asynchronous-unwind-tables
  -fno-exceptions
  -fno-rtti
  -fno-stack-check
  -fno-stack-protector
  -fno-unwind-tables)
add_link_options(-nostdlib -static)
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
  add_compile_options(-fno-stack-clash-protection)
  add_link_options(-s -Wl,-n,--build-id=none,-gc-sections)
elseif(CMAKE_SYSTEM_NAME MATCHES "Darwin")
  add_link_options(-Wl,-no_pie)
endif()

add_executable(entrypoint_start entrypoint_start.cpp ../entrypoint/start.S)
add_test("entrypoint\/start.s" entrypoint_start)

add_executable(syscall_exit syscall_exit.cpp ../entrypoint/start.S)
add_test("syscall\/exit.hpp" syscall_exit)
target_compile_options(syscall_exit PRIVATE -Wno-unknown-warning-option -Wno-suggest-attribute=noreturn)

add_executable(syscall_write syscall_write.cpp ../entrypoint/start.S)
add_test("syscall\/write.hpp" syscall_write)

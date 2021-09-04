cmake_minimum_required(VERSION 3.16.2)
project(minimalib-tests LANGUAGES CXX)

include(CTest)
include_directories(..)

set(BUILD_TESTING ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)

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
  -ggdb
  -fno-stack-protector
  -ffreestanding
  -ffunction-sections
  -fdata-sections
  -fno-unwind-tables
  -fno-asynchronous-unwind-tables
  -fno-rtti
  -fno-exceptions)
add_link_options(-nostdlib -Wl,--build-id=none -Wl,-gc-sections)
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_link_options(-s -no-pie -Wl,-n)
endif()

add_executable(entrypoint_start entrypoint_start.cpp)
add_test("entrypoint\/start.hpp" entrypoint_start)

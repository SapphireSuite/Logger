# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)


# Project

project(SA_Logger)

message("SA_Logger Main directory: ${CMAKE_SOURCE_DIR}")



# Outputs

### Setup output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Bin)		# .exe
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Libs)	# .lib / .a
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Libs)	# .dll / .so



# Library

## Input.
file(GLOB_RECURSE SA_LOGGER_SOURCES "Source/*")

## Static library.
add_library(SA_Logger STATIC ${SA_LOGGER_SOURCES})

## Include directories

target_include_directories(SA_Logger PUBLIC Include)
target_include_directories(SA_Logger PRIVATE Include/SA)

## Compile features

### Standard
target_compile_features(SA_Logger PUBLIC c_std_11)
target_compile_features(SA_Logger PUBLIC cxx_std_20)

### SA_Logger module implementation preprocessor.
target_compile_definitions(SA_Logger PUBLIC SA_LOGGER_IMPL)



# Options

## Add SA_Logger's tests to build tree.
option(SA_LOGGER_BUILD_TESTS_OPT "Should build SA_Maths tests" OFF)



# Entrypoints

if(SA_LOGGER_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)
endif()

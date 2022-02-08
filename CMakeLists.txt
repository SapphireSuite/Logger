# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)


# Project

project(SA_Logger)

message("SA_Logger Main directory: ${CMAKE_CURRENT_SOURCE_DIR}")



# Outputs

### Setup output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)		# .exe
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)		# .lib / .a
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)		# .dll / .so



# Library

## Input.
file(GLOB_RECURSE SA_LOGGER_SOURCES "Source/*")

## Static library.
add_library(SA_Logger STATIC ${SA_LOGGER_SOURCES})

## Link dependencies.
target_link_libraries(SA_Logger PUBLIC SA_Support)

## Include directories

target_include_directories(SA_Logger PUBLIC Include)
target_include_directories(SA_Logger PRIVATE Include/SA)

## Compile features

### Standard
target_compile_features(SA_Logger PUBLIC c_std_11)
target_compile_features(SA_Logger PUBLIC cxx_std_20)

### SA_Logger module implementation preprocessor.
target_compile_definitions(SA_Logger PUBLIC SA_LOGGER_IMPL)

### Thread
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(SA_Logger PUBLIC Threads::Threads)

### Advanced MSVC preprocessor required for Core::Debug
### https://docs.microsoft.com/en-us/cpp/preprocessor/preprocessor-experimental-overview
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
	if(${MSVC_TOOLSET_VERSION} LESS 142)
		target_compile_options(SA_Logger PUBLIC /experimental:preprocessor)
	else()
		target_compile_options(SA_Logger PUBLIC /Zc:preprocessor)
	endif()
endif()


# Options

## Add SA_Logger's tests to build tree.
option(SA_LOGGER_BUILD_TESTS_OPT "Should build SA_Logger tests" OFF)


## SA_Logger should log even in release.
option(SA_LOG_RELEASE_OPT "Should log in release" ON)

if(SA_LOG_RELEASE_OPT)
	target_compile_definitions(SA_Logger PUBLIC SA_LOG_RELEASE_OPT)
endif()



# Entrypoints

add_subdirectory(ThirdParty)

if(SA_LOGGER_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)
endif()

# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_LoggerUT)



# Fetch Google Test.
if(NOT TARGET gtest)

	message("Fetching Google Test...")

	include(FetchContent)


	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG        release-1.11.0
	)

	FetchContent_MakeAvailable(googletest)

endif()



# Executable

## Inputs

file(GLOB_RECURSE SA_LOGGER_UT_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_LoggerUT ${SA_LOGGER_UT_SOURCES})



# Dependencies

### Add library dependencies.
target_link_libraries(SA_LoggerUT PRIVATE SA_Logger)

### Google test module dependency.
target_link_libraries(SA_LoggerUT PRIVATE gtest)



# Tests

add_test(NAME CSA_LoggerUT COMMAND SA_LoggerUT)

# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

# Options

## Add SA_Logger's tests to build tree.
option(SA_LOGGER_SANITIZER_OPT "Should add sanitizer for testing" OFF)


### Additionnal options for tests.
if(MSVC)

	if(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang") # ClangCl

		# Max warning level.
		target_compile_options(SA_Logger PUBLIC -W4)

	else()

		# Max warning level.
		target_compile_options(SA_Logger PUBLIC /W4)

	endif()

else()

	if(SA_LOGGER_SANITIZER_OPT)

		# Thread sanitizer: compile and link.
		target_link_options(SA_Logger PUBLIC -fsanitize=thread)
		target_compile_options(SA_Logger PUBLIC -fsanitize=thread -fno-omit-frame-pointer)

	endif()

	# Max warning level.
	target_compile_options(SA_Logger PUBLIC -Wall -Wextra)

endif()



# Entrypoints

add_subdirectory(Prototype)
add_subdirectory(UnitTests)

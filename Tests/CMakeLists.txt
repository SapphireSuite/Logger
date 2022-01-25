# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.


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

	# Thread sanitizer: compile and link.
	target_link_options(SA_Logger PUBLIC -fsanitize=thread)
	target_compile_options(SA_Logger PUBLIC -fsanitize=thread -fno-omit-frame-pointer)

	# Max warning level.
	target_compile_options(SA_Logger PUBLIC -Wall -Wextra)

endif()



# Entrypoints

add_subdirectory(Prototype)
add_subdirectory(UnitTests)

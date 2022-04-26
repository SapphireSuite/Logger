# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.


SA_SetMaxWarningLevel(TARGET SA_Support)



# Options

## Add SA_Logger's debug sanitizer option.
option(SA_LOGGER_SANITIZER_OPT "Should add sanitizer for testing" OFF)

if(SA_LOGGER_SANITIZER_OPT)

	if(MSVC)

		target_compile_options(SA_Logger PUBLIC /fsanitize=thread)
		
	else()

		# Thread sanitizer: compile and link.
		target_link_options(SA_Logger PUBLIC -fsanitize=thread)
		target_compile_options(SA_Logger PUBLIC -fsanitize=thread -fno-omit-frame-pointer)

	endif()

endif()



# Entrypoints

add_subdirectory(Prototype)
add_subdirectory(UnitTests)

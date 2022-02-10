// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_CLASS_NAME_GUARD
#define SAPPHIRE_LOGGER_CLASS_NAME_GUARD

#include <string>
#include <typeinfo>

#include <SA/Support/Compilers.hpp>
#include <SA/Support/Platforms.hpp>

#if SA_UNIX && (SA_GNU || SA_CLANG)

	#include <cxxabi.h>

#endif

namespace Sa
{
	/// \cond Internal

	namespace Intl
	{
		template <typename U>
		std::string GetClassName(U&& _in)
		{
			(void)_in;

			std::string result;

		#if SA_UNIX && (SA_GNU || SA_CLANG)

			// Query more precise name than typeid.

			int status;

			char* demangled = abi::__cxa_demangle(typeid(U).name(), 0, 0, &status);

			if (status == 0)
			{
				result = demangled;
				free(demangled);
			}
			else
		
		#else

			result = typeid(U).name();

		#endif

			return result;
		}
	}
}

#endif // GUARD

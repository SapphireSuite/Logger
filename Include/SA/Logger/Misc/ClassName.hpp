// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_CLASS_NAME_GUARD
#define SAPPHIRE_LOGGER_CLASS_NAME_GUARD

#include <string>
#include <typeinfo>

namespace Sa
{
	/// \cond Internal

	namespace Intl
	{
		template <typename U>
		std::string GetClassName(U&& _in)
		{
			(void)_in;

			return typeid(U).name();
		}
	}

	/// \endcond
}

#endif // GUARD

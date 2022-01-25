// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_NEARLY_EQUALS_GUARD
#define SAPPHIRE_LOGGER_NEARLY_EQUALS_GUARD

#include <limits>

namespace Sa
{
	/// \cond Internal

	namespace Intl
	{
		template <typename T>
		bool NearlyEquals(T _lhs, T _rhs) noexcept
		{
			return (_lhs < _rhs ? _rhs - _lhs : _lhs - _rhs) <= std::numeric_limits<T>::epsilon();
		}
	}

	/// \endcond
}

#endif // GUARD

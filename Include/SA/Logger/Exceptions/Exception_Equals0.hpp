// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_EQUALS_0_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_EQUALS_0_GUARD

#include <SA/Logger/Exceptions/Exception_Equals.hpp>

namespace Sa
{
	class Exception_Equals0 : public Exception_Equals
	{
	public:
		template <typename T>
		Exception_Equals0(
			BaseInfos&& _infos,
			const T& _lhs,
			std::wstring&& _predStr = L"pred"
		) noexcept :
			Exception_Equals(std::move(_infos), _lhs, T(), std::move(_predStr))
		{
		}
	};

	/// \cond Internal

	/// Define Equals0 Exception creation method.
	#define __SA_CREATE_EXCEPTION_Equals0(_baseInfos, _lhs) Sa::Exception_Equals0(\
		_baseInfos,\
		_lhs,\
		SA_WSTR(_lhs) L" == 0"\
	)

	/// \endcond
}

#endif // GUARD

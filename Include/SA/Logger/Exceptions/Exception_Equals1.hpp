// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_EQUALS_1_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_EQUALS_1_GUARD

#include <SA/Logger/Exceptions/Exception_Equals.hpp>

namespace Sa
{
	class Exception_Equals1 : public Exception_Equals
	{
	public:
		template <typename T>
		Exception_Equals1(
			BaseInfos&& _infos,
			const T& _lhs,
			std::wstring&& _predStr = L"pred"
		) noexcept :
			Exception_Equals(std::move(_infos), _lhs, T(1), std::move(_predStr))
		{
		}
	};

	/// \cond Internal

	/// Define Equals1 Exception creation method.
	#define __SA_CREATE_EXCEPTION_Equals1(_baseInfos, _lhs) Sa::Exception_Equals1(\
		_baseInfos,\
		_lhs,\
		SA_WSTR(_lhs) L" == 1"\
	)

	/// \endcond
}

#endif // GUARD

// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_1_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_1_GUARD

#include <SA/Logger/Exceptions/Exception_NotEquals.hpp>
#include <SA/Logger/Exceptions/Exception_Equals1.hpp>

namespace Sa
{
	class Exception_NotEquals1 : public Exception_NotEquals
	{
	public:
		Exception_NotEquals1(Exception_Equals1&& _exc) noexcept :
			Exception_NotEquals(std::move(_exc))
		{
		}
	};

	/// \cond Internal

	/// Define NotEquals1 Exception creation method.
	#define __SA_CREATE_EXCEPTION_NotEquals1(_baseInfos, _lhs) Sa::Exception_NotEquals1(\
		__SA_CREATE_EXCEPTION_Equals1(_baseInfos, _lhs)\
	)

	/// \endcond
}

#endif // GUARD

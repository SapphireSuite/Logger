// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_0_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_0_GUARD

#include <SA/Logger/Exceptions/Exception_NotEquals.hpp>
#include <SA/Logger/Exceptions/Exception_Equals0.hpp>

namespace Sa
{
	class Exception_NotEquals0 : public Exception_NotEquals
	{
	public:
		Exception_NotEquals0(Exception_Equals0&& _exc) noexcept :
			Exception_NotEquals(std::move(_exc))
		{
		}
	};

	/// \cond Internal

	/// Define NotEquals0 Exception creation method.
	#define __SA_CREATE_EXCEPTION_NotEquals0(_baseInfos, _lhs) Sa::Exception_NotEquals0(\
		__SA_CREATE_EXCEPTION_Equals0(_baseInfos, _lhs)\
	)

	/// \endcond
}

#endif // GUARD

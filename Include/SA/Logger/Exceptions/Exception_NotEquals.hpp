// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_GUARD

#include <SA/Logger/Exceptions/Exception_Equals.hpp>

namespace Sa
{
	class Exception_NotEquals : public Exception
	{
	public:
		Exception_NotEquals(Exception_Equals&& _exc) noexcept;
	};

	/// \cond Internal

	/// Define NotEquals Exception creation method.
	#define __SA_CREATE_EXCEPTION_NotEquals(_baseInfos, _lhs, _rhs) Sa::Exception_NotEquals(\
		__SA_CREATE_EXCEPTION_Equals(_baseInfos, _lhs, _rhs)\
	)

	/// \endcond
}

#endif // GUARD

// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/Exceptions/Exception_NotEquals.hpp>

namespace Sa
{
	Exception_NotEquals::Exception_NotEquals(Exception_Equals&& _exc) noexcept :
		Exception(std::move(_exc))
	{
		msg.replace(msg.find(L"=="), 2, L"!=");

		// Reverse predicate.
		if (level == LogLevel::AssertFailed)
			level = LogLevel::AssertSuccess;
		else if (level == LogLevel::AssertSuccess)
			level = LogLevel::AssertFailed;
	}
}

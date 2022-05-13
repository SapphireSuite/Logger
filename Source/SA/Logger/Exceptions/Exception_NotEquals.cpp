// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Exceptions/Exception_NotEquals.hpp>

namespace SA
{
	Exception_NotEquals::Exception_NotEquals(Exception_Equals&& _exc) noexcept :
		Exception(std::move(_exc))
	{
		// Replace "==" into "!="
		{
			size_t index = msg.find(L"==");

			while (index != std::wstring::npos)
			{
				msg.replace(msg.find(L"=="), 2, L"!=");
				index = msg.find(L"==");
			}
		}


		// Reverse predicate.
		if (level == LogLevel::AssertFailure)
			level = LogLevel::AssertSuccess;
		else if (level == LogLevel::AssertSuccess)
			level = LogLevel::AssertFailure;
	}
}

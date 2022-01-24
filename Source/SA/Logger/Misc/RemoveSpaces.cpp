// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/Misc/RemoveSpaces.hpp>

#include <algorithm>

namespace Sa::Intl
{
	std::wstring RemoveSpaces(std::wstring _str) noexcept
	{
		_str.erase(std::remove_if(_str.begin(), _str.end(), isspace), _str.end());

		return _str;
	}
}

// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/ToString.hpp>

namespace Sa
{
	namespace Intl
	{
		std::string ToStringBinary(const char* _data, uint64_t _size) noexcept
		{
			static constexpr char table[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

			std::string res;

			res.reserve(3 * _size + 1);

			res += '<';

			for (const char* it = _data + _size - 1; it >= _data; --it)
			{
				res += table[(*it & 0xF0) >> 4];
				res += table[*it & 0x0F];

				res += '-';
			}

			res.back() = '>';

			return res;
		}
	}
}

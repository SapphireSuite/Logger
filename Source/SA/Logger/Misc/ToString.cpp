// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/Misc/ToString.hpp>

namespace Sa
{
//{ ToString

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


	std::string ToString(const char& _char)
	{
		return std::string(1u, _char);
	}

	std::string ToString(const char* _cstr)
	{
		return std::string(_cstr);
	}

	std::string ToString(const std::string& _str) noexcept
	{
		return _str;
	}

//}


//{ ToWString

	std::wstring ToWString(const char& _char)
	{
		return std::wstring(1u, _char);
	}

	std::wstring ToWString(const char* _cstr)
	{
		const size_t length = strlen(_cstr);

		std::wstring res(length, L' ');

		std::mbstowcs(res.data(), _cstr, length);

		return res;
	}

	std::wstring ToWString(const wchar_t& _char)
	{
		return std::wstring(1u, _char);
	}

	std::wstring ToWString(const wchar_t* _cstr)
	{
		return std::wstring(_cstr);
	}

	std::wstring ToWString(const std::string& _str)
	{
		std::wstring res(_str.length(), L' ');

		std::mbstowcs(res.data(), _str.c_str(), _str.length());

		return res;
	}

	std::wstring ToWString(const std::wstring& _str) noexcept
	{
		return _str;
	}

//}
}

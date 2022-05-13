// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_STRING_STREAM_GUARD
#define SAPPHIRE_LOGGER_STRING_STREAM_GUARD

#include <SA/Logger/Misc/ToString.hpp>

namespace SA
{
//{ StringStream

	struct StringStream
	{
		std::string str;

		template <typename T>
		StringStream& operator<<(const T& _rhs) &;

		template <typename T>
		StringStream&& operator<<(const T& _rhs) &&;

		inline operator std::string&& () { return std::move(str); };
		inline operator const std::string& () const { return str; };
	};

	inline StringStream operator""_L(const char* _str, std::size_t _size)
	{
		return StringStream() << std::string(_str, _size);
	}

//}


//{ WStringStream

	struct WStringStream
	{
		std::wstring str;

		template <typename T>
		WStringStream& operator<<(const T& _rhs) &;

		template <typename T>
		WStringStream&& operator<<(const T& _rhs) &&;

		inline operator std::wstring&& () { return std::move(str); };
		inline operator const std::wstring& () const { return str; };
	};

	inline WStringStream operator""_L(const wchar_t* _wstr, std::size_t _size)
	{
		return WStringStream() << std::wstring(_wstr, _size);
	}

//}
}

#include <SA/Logger/Misc/StringStream.inl>

#endif // GUARD

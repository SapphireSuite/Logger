// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_STRING_STREAM_GUARD
#define SAPPHIRE_LOGGER_STRING_STREAM_GUARD

#include <SA/Logger/Misc/ToString.hpp>

namespace Sa
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

//}
}

#include <SA/Logger/Misc/StringStream.inl>

#endif // GUARD

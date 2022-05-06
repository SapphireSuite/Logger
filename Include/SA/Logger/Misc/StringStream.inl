// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

namespace Sa
{
//{ StringStream

	template <typename T>
	StringStream& StringStream::operator << (const T & _rhs) &
	{
		str += ToString(_rhs);

		return *this;
	}

	template <typename T>
	StringStream&& StringStream::operator<<(const T& _rhs) &&
	{
		str += ToString(_rhs);

		return std::move(*this);
	}

//}


//{ WStringStream

	template <typename T>
	WStringStream& WStringStream::operator<<(const T& _rhs) &
	{
		str += ToWString(_rhs);

		return *this;
	}

	template <typename T>
	WStringStream&& WStringStream::operator<<(const T& _rhs) &&
	{
		str += ToWString(_rhs);

		return std::move(*this);
	}

//}
}

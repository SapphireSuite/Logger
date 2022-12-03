// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

namespace SA
{
	template <typename T>
	Exception_Equals::Exception_Equals(
		BaseInfo&& _info,
		const T& _lhs,
		const T& _rhs,
		std::wstring&& _predStr,
		std::wstring&& _details
	) noexcept :
		Exception(std::move(_info),
			_lhs == _rhs,
			std::move(_predStr) + L"\t{ " + ToWString(_lhs) + L" == " + ToWString(_rhs) + L" }",
			std::move(_details))
	{
	}
}

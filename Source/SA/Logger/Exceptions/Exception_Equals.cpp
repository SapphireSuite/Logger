// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Exceptions/Exception_Equals.hpp>

#include <Misc/NearlyEquals.hpp>

namespace SA
{
	Exception_Equals::Exception_Equals(
		BaseInfos&& _infos,
		float _lhs,
		float _rhs,
		std::wstring&& _predStr,
		std::wstring&& _details
	) noexcept :
		Exception(std::move(_infos),
			Intl::NearlyEquals(_lhs, _rhs),
			std::move(_predStr) + L"\t{ " + ToWString(_lhs) + L"f == " + ToWString(_rhs) + L"f }",
			std::move(_details))
	{
	}

	Exception_Equals::Exception_Equals(
		BaseInfos&& _infos,
		double _lhs,
		double _rhs,
		std::wstring&& _predStr,
		std::wstring&& _details
	) noexcept :
		Exception(std::move(_infos),
			Intl::NearlyEquals(_lhs, _rhs),
			std::move(_predStr) + L"\t{ " + ToWString(_lhs) + L" == " + ToWString(_rhs) + L" }",
			std::move(_details))
	{
	}
}

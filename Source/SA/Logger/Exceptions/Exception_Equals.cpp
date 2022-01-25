// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/Exceptions/Exception_Equals.hpp>

#include <SA/Logger/Misc/NearlyEquals.hpp>

namespace Sa
{
	Exception_Equals::Exception_Equals(
		BaseInfos&& _infos,
		float _lhs,
		float _rhs,
		std::wstring&& _predStr
	) noexcept :
		Exception(std::move(_infos),
			Intl::NearlyEquals(_lhs, _rhs),
			std::move(_predStr),
			std::wstring() << _lhs << L"f == " << _rhs << L'f')
	{
	}

	Exception_Equals::Exception_Equals(
		BaseInfos&& _infos,
		double _lhs,
		double _rhs,
		std::wstring&& _predStr
	) noexcept :
		Exception(std::move(_infos),
			Intl::NearlyEquals(_lhs, _rhs),
			std::move(_predStr),
			std::wstring() << _lhs << L" == " << _rhs)
	{
	}
}

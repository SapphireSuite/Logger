// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

namespace Sa
{
	template <typename T>
	Exception_Equals::Exception_Equals(
		BaseInfos&& _infos,
		const T& _lhs,
		const T& _rhs,
		std::wstring&& _predStr,
		std::wstring&& _details
	) noexcept :
		Exception(std::move(_infos),
			_lhs == _rhs,
			std::move(_predStr) << L"\t{ " << _lhs << L" == " << _rhs << L" }",
			std::move(_details))
	{
	}
}

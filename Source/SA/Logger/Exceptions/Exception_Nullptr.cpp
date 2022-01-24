// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Logger/Exceptions/Exception_Nullptr.hpp>

namespace Sa
{
	Exception_Nullptr::Exception_Nullptr(
		BaseInfos&& _infos,
		bool _pred,
		std::wstring&& _predStr,
		std::wstring&& _details
	) noexcept :
		Exception(std::move(_infos), _pred, _predStr + L" is nullptr!", std::move(_details))
	{
	}
}

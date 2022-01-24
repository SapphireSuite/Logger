// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Logger/Exceptions/Exception_NonZero.hpp>

namespace Sa
{
	Exception_NonZero::Exception_NonZero(
		BaseInfos&& _infos,
		bool _pred,
		std::wstring&& _predStr,
		std::wstring&& _details
	) noexcept :
		Exception(std::move(_infos), _pred, _predStr + L" == 0", std::move(_details))
	{
	}
}

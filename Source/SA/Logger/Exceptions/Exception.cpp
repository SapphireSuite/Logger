// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Exceptions/Exception.hpp>

namespace Sa
{
	Exception::Exception(
		BaseInfos&& _infos,
		bool _pred,
		std::wstring&& _msg,
		std::wstring&& _details
	) noexcept :
		Log(
			std::move(_infos.file),
			_infos.line,
			std::move(_infos.function),
			std::move(_msg),
			_pred ? LogLevel::AssertSuccess : LogLevel::AssertFailure,
			std::move(_infos.chanName),
			std::move(_details))
	{
	}
}

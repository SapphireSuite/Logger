// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/Log.hpp>

#include <iostream>

#include <SA/Logger/ToString.hpp>

namespace Sa
{
	Log::Log(
		std::wstring&& _file,
		uint32_t _line,
		std::string&& _function,
		std::wstring&& _msg,
		LogLevel _level,
		std::wstring&& _chanName,
		std::wstring&& _details
	) noexcept :
		file{ std::move(_file) },
		line{ _line },
		function{ std::move(_function) },
		msg{ std::move(_msg) },
		level{_level },
		chanName{ std::move(_chanName) },
		details{ std::move(_details) }
		//date{ Time::Date() }
	{
	}

	std::wstring ToWString(const Log& _log)
	{
		std::wstring str;

		// Output date.
		//str += L'[' + Sa::ToWString(date.hour) + L':' + Sa::ToWString(date.minute) + L':' + Sa::ToWString(date.second) + L"] ";

		// Output level and channel.
		str += L'{' + Sa::ToWString(_log.level) + L" - " + _log.chanName + L'}';

		// Output location.
		str += L'\t' + _log.file + L':' + Sa::ToWString(_log.line) + L" - " + Sa::ToWString(_log.function) + L'\n';

		// Output message.
		str += L"Msg:\t" + _log.msg + L'\n';

		if (!_log.details.empty())
			str += L"Dets:\t" + _log.details + L'\n';

		return str;
	}
}

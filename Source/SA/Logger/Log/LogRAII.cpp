// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Log/LogRAII.hpp>

#include <Macro.hpp>

namespace SA
{
	LogRAII::LogRAII(Log&& _log) : mHandle{std::move(_log)}
	{
	}

	LogRAII::~LogRAII()
	{
		__SA_LOGGER->Push(std::move(mHandle));
	}
}

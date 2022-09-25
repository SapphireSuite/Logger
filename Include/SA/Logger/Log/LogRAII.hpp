// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOG_RAII_GUARD
#define SAPPHIRE_LOGGER_LOG_RAII_GUARD

#include "Log.hpp"

namespace SA
{
	class LogRAII
	{
		Log mHandle;

	public:
		LogRAII(Log&& _log);
		~LogRAII();
	};

	#define SA_LOG_RAII(_name, _str, _lvl, _chan, _dets) LogRAII _name(__SA_CREATE_LOG(_str, _lvl, _chan, _dets));
}

#endif // SAPPHIRE_LOGGER_LOG_RAII_GUARD

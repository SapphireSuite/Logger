// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/Streams/Console/ConsoleLogStream.hpp>

#include <iostream>

namespace Sa
{
	ALogStream& ConsoleLogStream::Output(const Log& _log)
	{
		theme.SetConsoleColorFromLevel(_log.level);

		std::wcout << ToWString(_log) << std::endl;

		Sa::SetConsoleColor(CslColor::Reset);

		return *this;
	}
}

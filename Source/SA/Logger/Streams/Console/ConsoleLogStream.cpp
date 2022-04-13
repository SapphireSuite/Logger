// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#include <Streams/Console/ConsoleLogStream.hpp>

namespace Sa
{
	void ConsoleLogStream::Flush()
	{
		std::wcout.flush();
	}

	void ConsoleLogStream::Output(const Log& _log)
	{
		theme.SetConsoleColorFromLevel(_log.level);

		std::wcout << ToWString(_log) << std::endl;

		Sa::SetConsoleColor(CslColor::Reset);
	}
}

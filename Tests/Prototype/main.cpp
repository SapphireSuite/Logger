// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#define LOG(_str) std::cout << _str << std::endl;

#include <SA/Logger/Logger.hpp>
#include <SA/Logger/Streams/Console/ConsoleLogStream.hpp>
#include <SA/Logger/Streams/File/FileLogStream.hpp>
using namespace Sa;

int main()
{
	Logger logger;

	ConsoleLogStream cslStream;
	logger.Register(cslStream);

	FileLogStream fileStream;
	logger.Register(fileStream);

	Log l{
		L"MyFile",
		16,
		"MyFunc",
		L"My Message!",
		LogLevel::Infos,
		L"MyChannel",
		L"My Details"
	};

	logger.Output(l);

	return 0;
}

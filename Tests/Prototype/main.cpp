// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#define LOG(_str) std::cout << _str << std::endl;

#include <SA/Logger/Macro.hpp>
#include <SA/Logger/Streams/Console/ConsoleLogStream.hpp>
#include <SA/Logger/Streams/File/FileLogStream.hpp>
using namespace Sa;

int main()
{
	Logger logger;
	Sa::Debug::logger = &logger;

	ConsoleLogStream cslStream;
	logger.Register(cslStream);

	FileLogStream fileStream;
	logger.Register(fileStream);

	SA_LOG("Hello, World!", Infos, Sa/TestChan, "Some Details!");

	return 0;
}

// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#define LOG(_str) std::cout << _str << std::endl;

#include <SA/Collections/Debug>
using namespace Sa;

int main()
{
	LoggerThread logger;
	Sa::Debug::logger = &logger;

	ConsoleLogStream cslStream;
	logger.Register(cslStream);

	FileLogStream fileStream;
	logger.Register(fileStream);

	for(int i = 0; i < 10; ++i)
		SA_LOG("Hello, World!", Infos, SA/TestChan, "Some Details!");

	try
	{
		SA_ASSERT(OutOfRange, SA/OtherChan, 4u, 1u, 3u);
	}
	catch (Exception& _exc)
	{
		(void)_exc;
		SA_LOG("CATCH");
	}

	logger.Flush();

	return 0;
}

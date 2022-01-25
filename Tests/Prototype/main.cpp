// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#define LOG(_str) std::cout << _str << std::endl;

#include <SA/Collections/Debug>
using namespace Sa;

int main()
{
//{ Init

	LoggerThread logger;
	Sa::Debug::logger = &logger;

	ConsoleLogStream cslStream;
	logger.Register(cslStream);

	FileLogStream fileStream;
	logger.Register(fileStream);

//}

//{ Test LogLevel Flags

	SA_LOG("This log level is enabled in console!", Warning, SA/TestChan);

	logger.Flush();

	cslStream.levelFlags.Remove(LogLevel::Warning);

	SA_LOG("This log level is NOT enabled in console!", Warning, SA / TestChan);

	logger.Flush();

	cslStream.levelFlags.Add(LogLevel::Warning);

	SA_LOG("This log level is enabled AGAIN in console!", Warning, SA / TestChan);

//}

//{ Test Data Race

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

//}

	/**
	*	Force flush before destroy because stream as been created after logger.
	*/
	logger.Flush();

	return 0;
}

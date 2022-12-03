// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Collections/Debug>
using namespace SA;

int main()
{
//{ Init

	ConsoleLogStream cslStream;
	FileLogStream fileStream;

	LoggerThread logger;
	SA::Debug::logger = &logger;

	logger.Register(cslStream);
	logger.Register(fileStream);

//}

//{ Test LogLevel Flags

	SA_LOG("This log level is enabled in console!", Warning, SA/TestChan);

	logger.Flush();

	cslStream.levelFlags &= ~LogLevel::Warning;

	SA_LOG("This log level is NOT enabled in console!", Warning, SA/TestChan);

	logger.Flush();

	cslStream.levelFlags |= LogLevel::Warning;

	SA_LOG("This log level is enabled AGAIN in console!", Warning, SA/TestChan);

//}

//{ Test Data Race

	for(int i = 0; i < 10; ++i)
		SA_LOG("Hello, World!", Info, SA/TestChan, "Some Details!");

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

	return 0;
}

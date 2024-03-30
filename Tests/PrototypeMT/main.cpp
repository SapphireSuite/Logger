// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <iostream>

#include <SA/Collections/Debug>

void LoggingThread()
{
	for (int i = 0; i < 100; ++i)
	{
		if(i == 99)
			SA_LOG(("HELLO %1", i), Warning)
		else
			SA_LOG(("HELLO %1", i));
	}
}

int main()
{
	SA::Debug::InitDefaultLoggerThread();

	std::thread t1(LoggingThread);
	std::thread t2(LoggingThread);
	std::thread t3(LoggingThread);
	std::thread t4(LoggingThread);

	if (t1.joinable())
		t1.join();

	if (t2.joinable())
		t2.join();

	if (t3.joinable())
		t3.join();

	if (t4.joinable())
		t4.join();

	return 0;
}

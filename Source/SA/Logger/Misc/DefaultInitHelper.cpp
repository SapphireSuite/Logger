// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Misc/DefaultInitHelper.hpp>

#include <Logger.hpp>
#include <LoggerThread.hpp>
#include <Streams/Console/ConsoleLogStream.hpp>
#include <Streams/File/FileLogStream.hpp>

namespace SA
{
	namespace Debug
	{
		static ConsoleLogStream defaultCslStream;
		static FileLogStream defaultFileStream;

		void InitDefaultLogger()
		{
			static Logger defaultLogger;

			defaultLogger.Register(defaultCslStream);
			defaultLogger.Register(defaultFileStream);

			SA::Debug::logger = &defaultLogger;
		}

		void InitDefaultLoggerThread()
		{
			static LoggerThread defaultLoggerThread;

			defaultLoggerThread.Register(defaultCslStream);
			defaultLoggerThread.Register(defaultFileStream);

			SA::Debug::logger = &defaultLoggerThread;
		}
	}
}

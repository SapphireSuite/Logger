// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOGGER_THREAD_GUARD
#define SAPPHIRE_LOGGER_LOGGER_THREAD_GUARD

#include <SA/Logger/Logger.hpp>

#include <queue>
#include <mutex>
#include <atomic>
#include <thread>
#include <condition_variable>

namespace Sa
{
	class LoggerThread : public Logger
	{
		/// Output stream mutex operations.
		std::mutex mStreamMutex;


		/// Logger thread.
		std::thread mThread;

		std::atomic<bool> mIsRunning = true;

		/// Log queue mutex operations.
		std::mutex mLogQueueMutex;
		
		/// Log queue condition variable.
		std::condition_variable mLogConditionVar;

		/// Log saved queue.
		std::queue<const Log*> mLogQueue;


		void Push_Internal(const Log* _log) override final;

		void Output(const Log& _log) override final;

		void ThreadLoop();

	public:
		/// Default Constructor.
		LoggerThread() noexcept;

		~LoggerThread();


		using Logger::Push;

		void Register(ALogStream& _stream) override final;
		bool Unregister(ALogStream& _stream) override final;

		void Flush() override final;
	};
}

#endif // GUARD

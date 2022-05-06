// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOGGER_THREAD_GUARD
#define SAPPHIRE_LOGGER_LOGGER_THREAD_GUARD

#include <SA/Logger/Logger.hpp>

#include <queue>
#include <mutex>
#include <atomic>
#include <thread>
#include <condition_variable>

/**
*	\file LoggerThread.hpp
*
*	\brief \e Multithread <b>Logger</b> class implementation.
*
*	\ingroup Logger
*	\{
*/


namespace Sa
{
	/**
	*	\brief Multithread logger class.
	* 
	*	Create one thread for log output.
	*	Push logs in thread-safe queue.
	*/
	class LoggerThread : public Logger
	{
		/// Output stream mutex operations.
		std::mutex mStreamMutex;


		/// Logger thread.
		std::thread mThread;

		/// Current running state.
		std::atomic<bool> mIsRunning = true;


		/// Log queue mutex operations.
		std::mutex mLogQueueMutex;
		
		/// Log queue condition variable.
		std::condition_variable mLogConditionVar;

		/// Log saved queue.
		std::queue<const Log*> mLogQueue;

		/// Atomic queue size.
		std::atomic<size_t> mQueueSize = 0;


		void Push_Internal(const Log* _log) override final;

		void ProcessLog(const Log* _log, bool _bForce = false) override final;

		void ThreadLoop();

	public:
		/// Default Constructor.
		LoggerThread() noexcept;

		/**
		*	Thread-safe destructor.
		*	Flush all remaining logs in streams before join.
		*/
		~LoggerThread();


		using Logger::Push;
		using Logger::Assert;

		void Register(ALogStream& _stream) override final;
		bool Unregister(ALogStream& _stream) override final;

		void Flush() override final;
	};
}


/** \}*/

#endif // GUARD

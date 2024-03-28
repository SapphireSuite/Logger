// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOGGER_THREAD_GUARD
#define SAPPHIRE_LOGGER_LOGGER_THREAD_GUARD

#include <SA/Logger/LoggerBase.hpp>

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

namespace SA
{
	/**
	*	\brief Multithread logger class.
	* 
	*	Create one thread for log output.
	*	Push logs in thread-safe queue.
	*/
	class LoggerThread : public LoggerBase
	{
		/**
		* \brief Current atomic registered frame number.
		* Use IncrementFrameNum() or SA_LOG_END_OF_FRAME() at the end of the frame to track frame number.
		*/
		std::atomic<uint32_t> mFrameNum = 0u;

	//{ Thread

		/// Logger thread.
		std::thread mThread;

		/// Current running state.
		std::atomic<bool> mIsRunning = true;

		/// Log queue mutex operations.
		std::mutex mLogQueueMutex;
		
		/// Log queue condition variable.
		std::condition_variable mLogConditionVar;

		/// Log saved queue.
		std::queue<SA::Log> mLogQueue;

		/// Atomic queue size.
		std::atomic<size_t> mQueueSize = 0;

		void ThreadLoop();

	//}

	//{ Streams
	
		/// Output stream mutex operations.
		std::mutex mStreamMutex;

		void ProcessLog(const SA::Log& _log, bool _bForce = false) override final;

		void RegisterStream(ALogStream* _stream) override final;
		bool UnregisterStream(ALogStream* _stream) override final;

	//}

	public:
		/// Default Constructor.
		LoggerThread() noexcept;

		/**
		*	Thread-safe destructor.
		*	Flush all remaining logs in streams before join.
		*/
		~LoggerThread();

		void Log(SA::Log _log) override final;

		void Flush() override final;


	//{ Frame Num

		/// Increment current registered frame number.
		void IncrementFrameNum() override final;

		/// Get current registered frame number.
		uint32_t GetFrameNum() const override final;
	//}
	};
}


/** \}*/

#endif // GUARD

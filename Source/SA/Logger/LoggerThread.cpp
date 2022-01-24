// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/LoggerThread.hpp>

namespace Sa
{
	LoggerThread::LoggerThread() noexcept : Logger(true)
	{
		mThread = std::thread(&LoggerThread::ThreadLoop, this);
	}

	LoggerThread::~LoggerThread()
	{
		// Flush all pending logs.
		Flush();

		// Stop running thread.
		mIsRunning = false;
		mLogConditionVar.notify_one();

		if(mThread.joinable())
			mThread.join();
	}


	void LoggerThread::Push_Internal(const Log* _log)
	{
		std::lock_guard lk(mLogQueueMutex);

		mLogQueue.push(_log);
		mLogConditionVar.notify_one();
	}

	void LoggerThread::Output(const Log& _log)
	{
		std::lock_guard lk(mStreamMutex);

		Logger::Output(_log);
	}

	void LoggerThread::ThreadLoop()
	{
		while (mIsRunning)
		{
			const Log* log = nullptr;

			{
				std::unique_lock lock(mLogQueueMutex);

				// Queue empty: wait for push.
				if (mLogQueue.empty())
				{
					mLogConditionVar.wait(lock);

					// Not running anymore after wait: stop thread.
					if (!mIsRunning)
						return;
				}

				// Pop Log.
				log = mLogQueue.front();
				mLogQueue.pop();

				// Destroy lock: Allow push operations while outputing in streams.
			}

			ProcessLog(log);
		}
	}


	void LoggerThread::Register(ALogStream& _stream)
	{
		std::lock_guard lk(mStreamMutex);

		Logger::Register(_stream);
	}

	bool LoggerThread::Unregister(ALogStream& _stream)
	{
		std::lock_guard lk(mStreamMutex);

		return Logger::Unregister(_stream);
	}

	void LoggerThread::Flush()
	{
		while (true)
		{
			std::this_thread::yield();

			std::lock_guard lkQueue(mLogQueueMutex);

			if (mLogQueue.empty())
				break;
		}

		std::lock_guard lkStreams(mStreamMutex);

		Logger::Flush();
	}
}

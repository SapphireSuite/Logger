// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <LoggerThread.hpp>

namespace SA
{
	LoggerThread::LoggerThread() noexcept
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

	void LoggerThread::Log(SA::Log _log)
	{
		mLogQueueMutex.lock();

		mLogQueue.push(std::move(_log));
		++mQueueSize;

		mLogQueueMutex.unlock();

		mLogConditionVar.notify_one();
	}

//{ Thread

	void LoggerThread::ThreadLoop()
	{
		std::unique_lock locker(mLogQueueMutex);

		// Wait for first push.
		if (mLogQueue.empty())
			mLogConditionVar.wait(locker);
		

		while (mIsRunning)
		{
			// Pop Log.
			SA::Log log = std::move(mLogQueue.front());
			mLogQueue.pop();

			// Allow queue.push() while outputing in streams.
			locker.unlock();


			ProcessLog(log);

			// Decrease queue size after process: ensure correct flush.
			--mQueueSize;


			// re-lock before accessing size.
			locker.lock();

			// Queue empty: wait for push.
			if (mLogQueue.empty())
				mLogConditionVar.wait(locker); // Wait and aquire locker for next loop.

			// Check running state after wait.
		}
	}

//}

//{ Streams

	void LoggerThread::ProcessLog(const SA::Log& _log, bool _bForce)
	{
		std::lock_guard lk(mStreamMutex);

		LoggerBase::ProcessLog(_log, _bForce);
	}

	void LoggerThread::RegisterStream(ALogStream* _stream)
	{
		std::lock_guard lk(mStreamMutex);

		LoggerBase::RegisterStream(_stream);
	}

	bool LoggerThread::UnregisterStream(ALogStream* _stream)
	{
		std::lock_guard lk(mStreamMutex);

		return LoggerBase::UnregisterStream(_stream);
	}

	void LoggerThread::Flush()
	{
		// Wait for empty queue.
		while(mQueueSize)
			std::this_thread::yield();

		// Flush all.
		std::lock_guard lkStreams(mStreamMutex);

		LoggerBase::Flush();
	}

//}

//{ Frame Num

	/// Increment current registered frame number.
	void LoggerThread::IncrementFrameNum()
	{
		mFrameNum = (mFrameNum + 1) % 1000;
	}

	/// Get current registered frame number.
	uint32_t LoggerThread::GetFrameNum() const
	{
		return mFrameNum;
	}
//}
}

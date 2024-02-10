// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Logger.hpp>

namespace SA
{
	Logger::~Logger()
	{
		ClearStreams();
	}

	void Logger::Log(SA::Log _log)
	{
		ProcessLog(_log);
	}

//{ Streams

	void Logger::ProcessLog(const SA::Log& _log, bool _bForce)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
			(*it)->ProcessLog(_log, _bForce);
	}

	void Logger::RegisterStream(ALogStream* _stream)
	{
		mStreams.push_back(_stream);
	}

	bool Logger::UnregisterStream(ALogStream* _stream)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
		{
			if (*it == _stream)
			{
				mStreams.erase(it);
				return true;
			}
		}

		return false;
	}

	void Logger::ClearStreams(bool _bFlush)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
		{
			if (_bFlush)
				(*it)->Flush();
			
			delete *it;
		}

		mStreams.clear();
	}

	void Logger::Flush()
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
			(*it)->Flush();
	}

//}

//{ Frame Num

	void Logger::IncrementFrameNum()
	{
		mFrameNum = (mFrameNum + 1) % 1000;
	}

	uint32_t Logger::GetFrameNum() const
	{
		return mFrameNum;
	}

//}
}

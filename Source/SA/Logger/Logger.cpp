// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Logger.hpp>

namespace SA
{
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

	void Logger::Flush()
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
			(*it)->Flush();
	}

//}
}

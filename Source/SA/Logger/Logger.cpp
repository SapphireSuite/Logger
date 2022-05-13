// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Logger.hpp>

namespace SA
{
	namespace Debug
	{
		Logger* logger = nullptr;
	}


	Logger::Logger(bool _bDuplicateLogs) noexcept :
		bDuplicateLogs{ _bDuplicateLogs }
	{
	}


	void Logger::Push_Internal(const Log* _log)
	{
		ProcessLog(_log);
	}

	void Logger::ProcessLog(const Log* _log, bool _bForce)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
			(*it)->ProcessLog(*_log, _bForce);

		if (bDuplicateLogs && !_bForce) // Forced logs are instant: no allocation.
			delete _log;
	}


	void Logger::Register(ALogStream& _stream)
	{
		mStreams.push_back(&_stream);
	}

	bool Logger::Unregister(ALogStream& _stream)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
		{
			if (*it == &_stream)
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
}

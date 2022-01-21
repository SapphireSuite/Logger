// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/Logger.hpp>

namespace Sa
{
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

	void Logger::Output(const Log& _log)
	{
		for (auto it = mStreams.begin(); it != mStreams.end(); ++it)
			(*it)->Output(_log);
	}
}

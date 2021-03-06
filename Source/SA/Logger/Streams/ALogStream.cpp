// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Streams/ALogStream.hpp>

namespace SA
{
	void ALogStream::ProcessLog(const Log& _log, bool _bForce)
	{
		if (_bForce)
		{
			Output(_log);
			return;
		}

		const bool bLevelEnabled = levelFlags & _log.level;
		const bool bChannelEnabled = channelFilter.IsChannelEnabled(_log.chanName);

		if (bLevelEnabled && bChannelEnabled)
			Output(_log);
	}

	void ALogStream::Flush()
	{
		/* Implementation in children */
	}


	ALogStream& ALogStream::operator<<(const Log& _log)
	{
		ProcessLog(_log);

		return *this;
	}
}

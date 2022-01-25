// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/Streams/ALogStream.hpp>

namespace Sa
{
	void ALogStream::ProcessLog(const Log& _log, bool _bForce)
	{
		(void)_bForce;
		Output(_log);
	}

	void ALogStream::Flush()
	{
	}


	ALogStream& ALogStream::operator<<(const Log& _log)
	{
		ProcessLog(_log);

		return *this;
	}
}

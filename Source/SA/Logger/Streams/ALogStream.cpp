// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/Streams/ALogStream.hpp>

namespace Sa
{
	void ALogStream::Flush()
	{
	}

	ALogStream& ALogStream::operator<<(const Log& _log)
	{
		return Output(_log);
	}
}
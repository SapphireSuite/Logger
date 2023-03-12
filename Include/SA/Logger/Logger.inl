// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

namespace SA
{
	template <typename ExcepT>
	void Logger::Assert(ExcepT _exc)
	{
		if(_exc.level == LogLevel::AssertFailure)
		{
			Flush();

			// Force instant process.
			ProcessLog(_exc, true);

			throw std::forward<ExcepT>(_exc);
		}
		else
		{
			// Simple log.
			Log(std::forward<ExcepT>(_exc));
		}
	}

//{ Streams

	template <typename StreamT, typename... Args>
	StreamT& Logger::CreateSteam(Args&&... _args)
	{
		StreamT* const stream = new StreamT(std::forward<Args>(_args)...);

		RegisterStream(stream);

		return *stream;
	}

	template <typename StreamT>
	bool Logger::DestroyStream(StreamT& _stream)
	{
		StreamT* const streamPtr = &_stream;

		const bool bUnregister = UnregisterSteam(streamPtr);

		if(bUnregister)
			delete streamPtr;

		return bUnregister;
	}

//}
}

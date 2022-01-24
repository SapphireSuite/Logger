// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

namespace Sa
{
	template <typename LogT>
	void Logger::Push(LogT&& _log)
	{
		const LogT* const log = bDuplicateLogs ? new LogT{ std::forward<LogT>(_log) } : &_log;

		Push_Internal(log);
	}
}

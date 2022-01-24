// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

namespace Sa
{
	template <typename LogT>
	void Logger::Push(LogT&& _log)
	{
		const LogT* const log = bDuplicateLogs ? new LogT{ std::forward<LogT>(_log) } : &_log;

		Push_Internal(log);
	}

	template <typename ExcepT>
	void Logger::Assert(ExcepT&& _exc)
	{
		if (_exc.level == LogLevel::AssertSuccess)
			Push(std::forward<ExcepT>(_exc)); // Simple log.
		else
		{
			Flush();

			// Force instant output (ignore process).
			Output(_exc);

			throw std::forward<ExcepT>(_exc);
		}
	}
}

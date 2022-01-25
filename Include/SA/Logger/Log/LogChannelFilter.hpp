// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOG_CHANNEL_FILTER_GUARD
#define SAPPHIRE_LOGGER_LOG_CHANNEL_FILTER_GUARD

#include <string>
#include <unordered_map>

namespace Sa
{
	class LogChannelFilter
	{
		/// Registered channels.
		std::unordered_map<std::wstring, bool> mChannels;

		bool IsSingleChannelEnabled(const std::wstring& _chanName) const;

	public:
		bool IsChannelEnabled(const std::wstring& _chanName, size_t _offset = 0u) const;
	};
}

#endif // GUARD

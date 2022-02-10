// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/Log/LogChannelFilter.hpp>

namespace Sa
{
	bool LogChannelFilter::IsSingleChannelEnabled(const std::wstring& _chanName) const
	{
		auto it = mChannels.find(_chanName);

		return it != mChannels.cend() ? it->second : true;
	}


	bool LogChannelFilter::IsChannelEnabled(const std::wstring& _chanName, size_t _offset) const
	{
		const size_t fIndex = _chanName.find('/', _offset);

		if (fIndex == std::wstring::npos)
			return IsSingleChannelEnabled(_chanName);

		return IsSingleChannelEnabled(_chanName.substr(0u, fIndex)) && IsChannelEnabled(_chanName, fIndex + 1);
	}
}
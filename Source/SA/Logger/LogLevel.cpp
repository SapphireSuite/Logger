// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <SA/Logger/LogLevel.hpp>

#include <SA/Support/Algorithms/BitScanForward.hpp>

namespace Sa
{
	const char* GetLogLevelName(LogLevel _lvl) noexcept
	{
		static constexpr const char* const names[]{ "Unknown", "Normal", "Infos", "Warning", "Error", "AssertSuccess", "AssertFailed" };

		return names[BitScanForward(static_cast<uint32_t>(_lvl)) + 1u];
	}
}

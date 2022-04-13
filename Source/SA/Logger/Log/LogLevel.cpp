// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Log/LogLevel.hpp>

#include <SA/Support/Algorithms/BitScanForward.hpp>

namespace Sa
{
	std::string ToString(LogLevel _lvl) noexcept
	{
		static constexpr const char* const names[]{ "Unknown", "Normal", "Infos", "Warning", "Error", "AssertSuccess", "AssertFailure" };

		return names[BitScanForward(static_cast<uint32_t>(_lvl)) + 1u];
	}

	std::wstring ToWString(LogLevel _lvl) noexcept
	{
		static constexpr const wchar_t* const names[]{ L"Unknown", L"Normal", L"Infos", L"Warning", L"Error", L"AssertSuccess", L"AssertFailure" };

		return names[BitScanForward(static_cast<uint32_t>(_lvl)) + 1u];
	}
}

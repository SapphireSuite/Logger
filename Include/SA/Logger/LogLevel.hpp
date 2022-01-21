// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOG_LEVEL_GUARD
#define SAPPHIRE_LOGGER_LOG_LEVEL_GUARD

#include <cstdint>

#include <string>

/**
*	\file LogLevel.hpp
*
*	\brief <b>Log level</b> enum implementation.
*
*	\ingroup Logger
*	\{
*/


namespace Sa
{
	/// \brief All levels of logging.
	enum class LogLevel : uint8_t
	{
		/// Normal level
		Normal = (1 << 0),

		/// Info level
		Infos = (1 << 1),

		/// Warning level
		Warning = (1 << 2),

		/// Error level
		Error = (1 << 3),

		/// Assert Success level
		AssertSuccess = (1 << 4),

		/// Assert  Failed level
		AssertFailed = (1 << 5),

		/// Default log level (no assert success).
		Default = Normal | Infos | Warning | Error | AssertFailed,

		Max = uint8_t(-1)
	};

	/// Shortcut alias.
	using LogLvl = LogLevel;


	/**
	*	\brief ToString implementation for LogLevel
	*
	*	\param[in] _lvl		Level to convert.
	*
	*	\return	LogLevel as a string.
	*/
	std::string ToString(LogLevel _lvl) noexcept;

	/**
	*	\brief ToWString implementation for LogLevel
	*
	*	\param[in] _lvl		Level to convert.
	*
	*	\return	LogLevel as a wstring.
	*/
	std::wstring ToWString(LogLevel _lvl) noexcept;
}

/** \} */

#endif // GUARD

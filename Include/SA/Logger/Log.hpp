// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOG_GUARD
#define SAPPHIRE_LOGGER_LOG_GUARD

#include <SA/Logger/LogLevel.hpp>
#include <SA/Logger/ToString.hpp>

#include <SA/Support/Algorithms/DateTime.hpp>

/**
*	\file Log.hpp
*
*	\brief \b Log type implementation.
*
*	\ingroup Logger
*	\{
*/

namespace Sa
{
	/// Log type implementation.
	class Log
	{
	public:
		/// File name.
		std::wstring file;

		/// Line number.
		uint32_t line = 0u;

		/// Function name.
		std::string function;

		/// User string message.
		std::wstring msg = L"Hello, World!";

		/// Output level.
		LogLevel level = LogLevel::Normal;

		/// Output channel name.
		std::wstring chanName = L"Default";

		/// Additional details string.
		std::wstring details;

		/// Date time.
		DateTime date;

		/**
		*	\brief \e Value Move Constructor.
		*
		*	\param[in] _file		File of the Log.
		*	\param[in] _line		Line of the Log.
		*	\param[in] _function	Function of the Log.
		*	\param[in] _msg			Message of the Log.
		*	\param[in] _level		Level of the Log.
		*	\param[in] _chanName	Channel's name of the Log.
		*	\param[in] _details		Additional details to display.
		*/
		Log(
			std::wstring&& _file,
			uint32_t _line,
			std::string&& _function,
			std::wstring&& _msg = L"Hello, World!",
			LogLevel _level = LogLevel::Normal,
			std::wstring&& _chanName = L"Default",
			std::wstring&& _details = L""
		) noexcept;

	};

	/**
	*	\brief ToWString implementation for log.
	*
	*	Convert log to wstring.
	*
	*	\return log as a wstring.
	*/
	std::wstring ToWString(const Log& _log);
}

/** \} */

#endif // GUARD

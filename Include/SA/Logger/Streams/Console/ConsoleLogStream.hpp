// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_CONSOLE_LOG_STREAM_GUARD
#define SAPPHIRE_LOGGER_CONSOLE_LOG_STREAM_GUARD

#include <SA/Logger/Streams/ALogStream.hpp>
#include <SA/Logger/Streams/Console/ConsoleColorTheme.hpp>

/**
*	\file ConsoleLogStream.hpp
*
*	\brief Log <b>console stream</b> type implementation.
*
*	\ingroup Logger_Console
*	\{
*/


namespace Sa
{
	/// Console log stream implementation.
	class ConsoleLogStream : public ALogStream
	{
	public:
		/// Color theme.
		ConsoleColorTheme theme;


		void Flush() override final;

		ALogStream& Output(const Log& _log) override final;
	};
}


/** \} */

#endif // GUARD

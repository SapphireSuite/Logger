// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_ALOG_STREAM_GUARD
#define SAPPHIRE_LOGGER_ALOG_STREAM_GUARD

#include <SA/Logger/Log.hpp>

namespace Sa
{
	/**
	*	\file ALogStream.hpp
	*
	*	\brief Log <b>base stream</b> implementation.
	*
	*	Stream used by Logger.
	*
	*	\ingroup Logger_Stream
	*	\{
	*/

	class ALogStream
	{
	public:
		/**
		*	\brief Output a log.
		*
		*	\param[in] _log		Log to output.
		*
		*	\return this.
		*/
		virtual ALogStream& Output(const Log& _log) = 0;

		/**
		*	\brief Output log operator.
		*
		*	\param[in] _log		Log to output.
		*
		*	\return this.
		*/
		ALogStream& operator<<(const Log& _log);
	};

	/** \} */
}

#endif // GUARD

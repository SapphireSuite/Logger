// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_ALOG_STREAM_GUARD
#define SAPPHIRE_LOGGER_ALOG_STREAM_GUARD

#include <SA/Logger/Log/Log.hpp>

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


namespace Sa
{
	/// Abstract log stream class.
	class ALogStream
	{
	protected:
		/**
		*	\brief Output a log in stream.
		*
		*	\param[in] _log		Log to output.
		*/
		virtual void Output(const Log& _log) = 0;

	public:
		/**
		*	\brief Process a log to output in stream.
		*
		*	\param[in] _log		Log to process.
		*	\param[in] _bForce	Should force log process. Default is false.
		*/
		void ProcessLog(const Log& _log, bool _bForce = false);

		/**
		*	\brief Force the stream to flush.
		*/
		virtual void Flush();

		/**
		*	\brief Output log operator.
		*
		*	\param[in] _log		Log to output.
		*
		*	\return this.
		*/
		ALogStream& operator<<(const Log& _log);
	};
}


/** \} */

#endif // GUARD

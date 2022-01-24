// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOGGER_GUARD
#define SAPPHIRE_LOGGER_LOGGER_GUARD

#include <vector>

#include <SA/Logger/Streams/ALogStream.hpp>

namespace Sa
{
	class Logger
	{
	protected:

		/// Registered output streams.
		std::vector<ALogStream*> mStreams;

	public:
		/**
		*	\brief Register a stream to output.
		* 
		*	\param[in] _stream	Stream to register.
		*/
		void Register(ALogStream& _stream);

		/**
		*	\brief Unregister a stream from output.
		*
		*	\param[in] _stream	Stream to unregister.
		*
		*	\return true on success.
		*/
		bool Unregister(ALogStream& _stream);

		/**
		*	\brief Output a log into registered streams.
		*
		*	\param[in] _log		Log to output.
		*/
		void Output(const Log& _log);
		virtual void Flush();
	};
}

#endif // GUARD

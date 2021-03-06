// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOGGER_GUARD
#define SAPPHIRE_LOGGER_LOGGER_GUARD

#include <vector>

#include <SA/Logger/Streams/ALogStream.hpp>

/**
*	\file Logger.hpp
*
*	\brief <b>Logger</b> class implementation.
*
*	\ingroup Logger
*	\{
*/


namespace SA
{
	/**
	*	\brief Basic Logger class implementation.
	* 
	*	Non-thread-safe logging.
	*/
	class Logger
	{
	protected:
		/// Should duplicate logs on push.
		const bool bDuplicateLogs = false;

		/// Registered output streams.
		std::vector<ALogStream*> mStreams;


		/**
		*	\brief Child-implementation constructor.
		* 
		*	\param[in] _bDuplicateLogs	bDuplicateLogs value.
		*/
		Logger(bool _bDuplicateLogs) noexcept;

		/**
		*	\brief Push a new \b abstract log in logger.
		* 
		*	\param[in] _log		Log to push.
		*/
		virtual void Push_Internal(const Log* _log);

		/**
		*	\brief Process log to output.
		* 
		*	\param[in] _log		Log to process.
		*	\param[in] _bForce	Should force log process. Default is false.
		*/
		virtual void ProcessLog(const Log* _log, bool _bForce = false);

	public:
		/// Default constructor.
		Logger() = default;

		/**
		*	\brief Register a stream to output.
		* 
		*	\param[in] _stream	Stream to register.
		*/
		virtual void Register(ALogStream& _stream);

		/**
		*	\brief Unregister a stream from output.
		*
		*	\param[in] _stream	Stream to unregister.
		*
		*	\return true on success.
		*/
		virtual bool Unregister(ALogStream& _stream);

		/**
		*	\brief Force logger to flush all streams.
		*/
		virtual void Flush();

		/**
		*	\brief Push a new \b typped log in logger.
		* 
		*	\tparam LogT		Log type.
		*	\param[in] _log		Log to push.
		*/
		template <typename LogT>
		void Push(LogT&& _log);

		/**
		*	\brief Process exception.
		*
		*	Log assertion on success, otherwise throw exception.
		*	Use SA_ASSERT as helper call.
		*
		*	\tparam ExcepT		Exception type.
		*	\param[in] _exc		exception to process.
		*/
		template <typename ExcepT>
		void Assert(ExcepT&& _exc);
	};

	/// Global Debug namespace
	namespace Debug
	{
		/// Logger instance.
		extern Logger* logger;
	}
}

#include <SA/Logger/Logger.inl>


/** \} */

#endif // GUARD

// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_LOGGER_GUARD
#define SAPPHIRE_LOGGER_LOGGER_GUARD

#include <list>

#include <SA/Logger/Streams/ALogStream.hpp>
#include <SA/Logger/Exceptions/Exception.hpp>

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
		std::list<ALogStream*> mStreams;

		uint32_t mFrameNum = 0u;

//{ Streams

		/**
		*	\brief Process log to output.
		* 
		*	\param[in] _log		Log to process.
		*	\param[in] _bForce	Should force log process. Default is false.
		*/
		virtual void ProcessLog(const SA::Log& _log, bool _bForce = false);

		/**
		*	\brief Register a stream to output.
		* 
		*	\param[in] _stream	Stream to register.
		*/
		virtual void RegisterStream(ALogStream* _stream);

		/**
		*	\brief Unregister a stream from output.
		*
		*	\param[in] _stream	Stream to unregister.
		*
		*	\return true on success.
		*/
		virtual bool UnregisterStream(ALogStream* _stream);

//}

	public:
		/**
		*	\brief Destructor
		*	Destroy all created log streams.
		*/
		virtual ~Logger();

		/**
		*	\brief Push a new log in logger.
		* 
		*	\param[in] _log		Log to push.
		*/
		virtual void Log(SA::Log _log);

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
		void Assert(ExcepT _exc);

//{ Streams

		/**
		*	\brief Create a new stream to output in.
		* 
		*	\tparam StreamT 	Type of stream to create.
		*	\tparam Args...		Argument variadic types to construct stream.
		*	\param[in] _args	Arguments to construct stream.
		*
		*	\return Newly created stream.
		*/
		template <typename StreamT, typename... Args>
		StreamT& CreateSteam(Args&&... _args);

		/**
		 * \brief Destroy a previously created stream.
		 * 
		 * \tparam StreamT 	Type of stream to destroy.
		 * \param _stream 	Stream variable to destroy.
		 * \param _bFlush 	Should flush stream before destroy.
		 * 
		 * \return true on destroy success.
		 */
		template <typename StreamT>
		bool DestroyStream(StreamT& _stream, bool _bFlush = true);

		/**
		*	Destroy all streams.
		* 
		*	\param _bFlush 	Should flush stream before destroy.
		*/
		void ClearStreams(bool _bFlush = true);

		/**
		*	\brief Force logger to flush all streams.
		*/
		virtual void Flush();

//}

//{ Frame Num

		void IncrementFrameNum();

		uint32_t GetFrameNum() const;
//}
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

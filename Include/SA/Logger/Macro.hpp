// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_MACRO_GUARD
#define SAPPHIRE_LOGGER_MACRO_GUARD

#include <iostream>

#include <SA/Support/Compilers.hpp>
#include <SA/Support/Stringify.hpp>

#include <SA/Logger/Logger.hpp>
#include <SA/Logger/Log/Log.hpp>

#include <SA/Logger/Misc/RemoveSpaces.hpp>
#include <SA/Logger/Misc/FileNameFromPath.hpp>

/**
*	\file Macro.hpp
*
*	\brief \b Logger helper macro implementation.
*
*	Define log and assertion macros.
*
*	\ingroup Logger
*	\{
*/

namespace Sa
{
	namespace Debug
	{
		/// Logger instance.
		extern Logger* logger = nullptr;
	}

	/// \cond Internal

//{ Function Name

	#if SA_GNU || SA_CLANG && !SA_MSVC

		#define __SA_FUNC_NAME __PRETTY_FUNCTION__

	#elif SA_MSVC

		#define __SA_FUNC_NAME __FUNCSIG__

	#else

		#define __SA_FUNC_NAME __FUNCTION__

	#endif

//}


	#define __SA_FILE_NAME Sa::Intl::FileNameFromPath(SA_WIDE(__FILE__))

	#define __SA_CHAN_NAME(_chan) Sa::Intl::RemoveSpaces(SA_WSTR(_chan))

	/// \endcond

//{ Logging

	/// \cond Internal

	#define __SA_LOGGER if(!Sa::Debug::logger) std::cerr << "Try logging with invalid logger instance! Initialize Sa::Debug::logger." << std::endl; else Sa::Debug::logger

	#define __SA_CREATE_LOG(_str, _lvl, _chan, _dets) Sa::Log(\
		__SA_FILE_NAME,\
		__LINE__,\
		__SA_FUNC_NAME,\
		(std::wstring() << _str),\
		Sa::LogLevel::_lvl,\
		__SA_CHAN_NAME(_chan),\
		(std::wstring() << _dets)\
	)

	#define __SA_SELECT_LOG_MACRO(_1, _2, _3, _4, _name, ...) _name

	#define __SA_LOG4(_str, _lvl, _chan, _dets)	{ __SA_LOGGER->Push(__SA_CREATE_LOG(_str, _lvl, _chan, _dets)); }
	#define __SA_LOG3(_str, _lvl, _chan)	__SA_LOG4(_str, _lvl, _chan, L"")
	#define __SA_LOG2(_str, _lvl)			__SA_LOG3(_str, _lvl, Default)
	#define __SA_LOG1(_str)					__SA_LOG2(_str, Normal)

	#define __SA_COND_LOG(_pred, _lvl, ...)		{ if(!(_pred)) SA_LOG(SA_WSTR(_pred), _lvl, ##__VA_ARGS__) }

	/// \endcond

	/**
	*	\def SA_LOG(_str, _lvl, _chan, _dets)
	*
	*	\brief Sapphire Log macro.
	*
	*	Helper macro to use Debug::Log.
	*
	*	\param[in] _str		String message of the log.
	*	\param[in] _lvl		Level of the log (optional).
	*	\param[in] _chan	Channel of the log (optional).
	*	\param[in] _dets	Additional details string of the log (optional).
	*/
	#define SA_LOG(...) __SA_SELECT_LOG_MACRO(__VA_ARGS__, __SA_LOG4, __SA_LOG3, __SA_LOG2, __SA_LOG1)(__VA_ARGS__)

	/**
	*	\def SA_WARN(_pred, _chan, _dets)
	*
	*	\brief Sapphire Log "warning if" macro.
	*
	*	Helper macro to use conditionnal Debug::Log warning.
	*
	*	\param[in] _pred	predicate of the Log. Output warnings on false.
	*	\param[in] _chan	Channel of the log.
	*	\param[in] _dets	Additional details string of the log (optional).
	*/
	#define SA_WARN(_pred, ...) __SA_COND_LOG(_pred, Warning, ##__VA_ARGS__)

	/**
	*	\def SA_ERROR(_pred, _chan, _dets)
	*
	*	\brief Sapphire Log "error if" macro.
	*
	*	Helper macro to use conditionnal Debug::Log error.
	*
	*	\param[in] _pred	predicate of the Log. Output error on false.
	*	\param[in] _chan	Channel of the log.
	*	\param[in] _dets	Additional details string of the log (optional).
	*/
	#define SA_ERROR(_pred, ...) __SA_COND_LOG(_pred, Error, ##__VA_ARGS__)

//}

}

/** \} */

#endif // GUARD

// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_MACRO_GUARD
#define SAPPHIRE_LOGGER_MACRO_GUARD

#include <iostream>

#include <SA/Support/Debug.hpp>
#include <SA/Support/Compilers.hpp>
#include <SA/Support/Stringify.hpp>

#include <SA/Logger/Logger.hpp>

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
	/// Global Debug namespace
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

#if defined(DOXYGEN)

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
	#define SA_LOG(_str, _lvl, _chan, _dets)

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
	#define SA_WARN(_pred, _chan, _dets)

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
	#define SA_ERROR(_pred, _chan, _dets)

#elif SA_DEBUG || SA_LOG_RELEASE_OPT

	#define SA_LOG(...) __SA_SELECT_LOG_MACRO(__VA_ARGS__, __SA_LOG4, __SA_LOG3, __SA_LOG2, __SA_LOG1)(__VA_ARGS__)

	#define SA_WARN(_pred, ...) __SA_COND_LOG(_pred, Warning, ##__VA_ARGS__)

	#define SA_ERROR(_pred, ...) __SA_COND_LOG(_pred, Error, ##__VA_ARGS__)

#else

	#define SA_LOG(...) {}

	#define SA_WARN(...) {}

	#define SA_ERROR(...) {}

#endif

//}


//{ Assert

	/// \cond Internal

	#define __SA_CREATE_EXCEPTION(_type, _chan, ...) __SA_CREATE_EXCEPTION_##_type(\
		(Sa::Exception::BaseInfos{\
			__SA_FILE_NAME,\
			__LINE__,\
			__SA_FUNC_NAME,\
			__SA_CHAN_NAME(_chan)\
		}),\
		##__VA_ARGS__\
	)

	/// \endcond

#if SA_DEBUG || SA_LOG_RELEASE_OPT || defined(DOXYGEN)

	/**
	*	\def SA_ASSERT(_type, _chan, ...)
	*
	*	\brief Sapphire Assertion macro.
	*
	*	Helper macro to use Debug::Assert.
	*
	*	\param[in] _type		type of the exception.
	*	\param[in] _chan		Channel of the assert.
	*	\param[in] ...			Additionnal args for exception (depends on _type).
	*/
	#define SA_ASSERT(_type, _chan, ...) { __SA_LOGGER->Assert(__SA_CREATE_EXCEPTION(_type, _chan, ##__VA_ARGS__)); }

	/**
	*	\def SA_ASSERT_EXEC(_type, _chan, _exec, ...)
	*
	*	\brief Sapphire Assertion execution macro.
	*	_exec will still be executed in non-debug but no debug infos will be generated.
	*
	*	Helper macro to use Debug::Assert.
	*
	*	\param[in] _type		type of the exception.
	*	\param[in] _chan		Channel of the assert.
	*	\param[in] _exec		Method to execute (even in non-debug).
	*	\param[in] ...			Additionnal args for exception (depends on _type).
	*/
	#define SA_ASSERT_EXEC(_type, _chan, _exec, ...) SA_ASSERT(_type, _chan, _exec, ##__VA_ARGS__)

#else

	#define SA_ASSERT(...) {}

	#define SA_ASSERT_EXEC(_type, _chan, _exec, ...) { _exec; }

#endif

//}

}

/** \} */

#endif // GUARD

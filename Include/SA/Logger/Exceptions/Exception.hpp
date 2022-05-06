// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_GUARD

#include <SA/Logger/Log/Log.hpp>

/**
*	\file Exception.hpp
*
*	\brief <b>Default Exception</b> type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace Sa
{
	/// Default (base) Exception type.
	class Exception : public Log
	{
	public:
		/// Base exception <b>create infos</b>.
		struct BaseInfos
		{
			/// File name.
			std::wstring file;

			/// line number.
			uint32_t line;

			/// Funciton name.
			std::string function;

			/// LogChannel name.
			std::wstring chanName;
		};

		/**
		*	\e Value move Constructor.
		* 
		*	\param[in] _infos		Base create infos.
		*	\param[in] _pred		Predicate used for assertion.
		*	\param[in] _msg			Message to display on assertion.
		*	\param[in] _details		Additional details to display on assertion.
		*/
		Exception(
			BaseInfos&& _infos,
			bool _pred,
			std::wstring&& _msg = L"",
			std::wstring&& _details = L""
		) noexcept;
	};

	/// Default type of exception.
	using Exception_Default = Exception;


	/// \cond Internal

	/// Define Default Exception creation method.
	#define __SA_CREATE_EXCEPTION_Default(_baseInfos, _pred, ...) Sa::Exception_Default(\
		_baseInfos,\
		_pred,\
		##__VA_ARGS__\
	)

	/// \endcond
}


/** \} */

#endif // GUARD

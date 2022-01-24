// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_NON_ZERO_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_NON_ZERO_GUARD

#include <SA/Logger/Exceptions/Exception.hpp>

/**
*	\file Exception_NonZero.hpp
*
*	\brief <b>NonZero Exception</b> type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace Sa
{
	/// NonZero Exception type.
	class Exception_NonZero : public Exception
	{
	public:
		/**
		*	\e Value Move Constructor.
		*
		*	\param[in] _infos		Base create infos.
		*	\param[in] _pred		Evaluated value predicate.
		*	\param[in] _predStr		Predicate as a string.
		*	\param[in] _details		Additional details to display on assertion.
		*/
		Exception_NonZero(
			BaseInfos&& _infos,
			bool _pred,
			std::wstring&& _predStr = L"pred",
			std::wstring&& _details = L""
		) noexcept;
	};

	#define __SA_CREATE_EXCEPTION_NonZero(_baseInfos, _pred, ...) Sa::Exception_NonZero(\
		_baseInfos,\
		_pred,\
		SA_WSTR(_pred),\
		##__VA_ARGS__\
	)
}


/** \} */

#endif // GUARD

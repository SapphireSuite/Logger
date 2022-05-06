// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_NULLPTR_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_NULLPTR_GUARD

#include <SA/Logger/Exceptions/Exception.hpp>

#include <SA/Support/Stringify.hpp>

/**
*	\file Exception_Nullptr.hpp
*
*	\brief <b>Nullptr Exception</b> type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace Sa
{
	/// Nullptr Exception type.
	class Exception_Nullptr : public Exception
	{
	public:
		/**
		*	\e Value move Constructor.
		*
		*	\param[in] _infos		Base create infos.
		*	\param[in] _pred		Evaluated pointer predicate.
		*	\param[in] _predStr		Predicate as a string.
		*	\param[in] _details		Additional details to display on assertion.
		*/
		Exception_Nullptr(
			BaseInfos&& _infos,
			bool _pred,
			std::wstring&& _predStr = L"ptr",
			std::wstring&& _details = L""
		) noexcept;
	};



	/// \cond Internal

	/// Define Nullptr Exception creation method.
	#define __SA_CREATE_EXCEPTION_Nullptr(_baseInfos, _pred, ...) Sa::Exception_Nullptr(\
		_baseInfos,\
		_pred,\
		SA_WSTR(_pred),\
		##__VA_ARGS__\
	)

	/// \endcond
}

/**
*	\example Exception_NullptrTests.cpp
*	Examples and Unitary Tests for Exception_Nullptr.
*/


/** \} */

#endif // GUARD

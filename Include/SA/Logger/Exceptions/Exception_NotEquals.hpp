// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_NOT_EQUALS_GUARD

#include <SA/Logger/Exceptions/Exception_Equals.hpp>

/**
*	\file Exception_NotEquals.hpp
*
*	\brief <b>Not Equals</b> Exception base type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace Sa
{
	/// Not Equals exception base type.
	class Exception_NotEquals : public Exception
	{
	public:
		/**
		*	\e Value move Constructor.
		*
		*	\param[in] _exc		Equals exception to be reversed.
		*/
		Exception_NotEquals(Exception_Equals&& _exc) noexcept;
	};

	/// \cond Internal

	/// Define NotEquals Exception creation method.
	#define __SA_CREATE_EXCEPTION_NotEquals(_baseInfos, _lhs, _rhs) Sa::Exception_NotEquals(\
		__SA_CREATE_EXCEPTION_Equals(_baseInfos, _lhs, _rhs)\
	)

	/// \endcond
}

/**
*	\example Exception_NotEqualsTests.cpp
*	Examples and Unitary Tests for Exception_NotEquals.
*/


/** \} */

#endif // GUARD

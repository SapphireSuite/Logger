// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_EQUALS_1_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_EQUALS_1_GUARD

#include <SA/Logger/Exceptions/Exception_Equals.hpp>

#include <SA/Logger/Misc/ClassName.hpp>

/**
*	\file Exception_Equals1.hpp
*
*	\brief <b>Equals 1</b> Exception type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace Sa
{
	/// Equals 1 exception implementation.
	class Exception_Equals1 : public Exception_Equals
	{
	public:
		/**
		*	\e Template value move Constructor.
		*
		*	\tparam T				Operands type.
		* 
		*	\param[in] _infos		Base create infos.
		*	\param[in] _lhs			Left hand side operand to compare to T(1).
		*	\param[in] _predStr		Predicate as a string.
		*	\param[in] _details		Additional details to display on assertion.
		*/
		template <typename T>
		Exception_Equals1(
			BaseInfos&& _infos,
			const T& _lhs,
			std::wstring&& _predStr = L"pred",
			std::wstring&& _details = L""
		) noexcept :
			Exception_Equals(std::move(_infos), _lhs, T(1), std::move(_predStr), std::move(_details))
		{
		}
	};

	/// \cond Internal

	/// Define Equals1 Exception creation method.
	#define __SA_CREATE_EXCEPTION_Equals1(_baseInfos, _lhs, ...) Sa::Exception_Equals1(\
		_baseInfos,\
		_lhs,\
		SA_WSTR(_lhs) L" == " + Sa::ToWString(Sa::Intl::GetClassName(_lhs)) + L"{ 1 }",\
		##__VA_ARGS__\
	)

	/// \endcond
}

/**
*	\example Exception_Equals1Tests.cpp
*	Examples and Unitary Tests for Exception_Equals1.
*/


/** \} */

#endif // GUARD

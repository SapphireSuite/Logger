// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_EQUALS_0_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_EQUALS_0_GUARD

#include <SA/Logger/Exceptions/Exception_Equals.hpp>

#include <SA/Logger/Misc/ClassName.hpp>

/**
*	\file Exception_Equals0.hpp
*
*	\brief <b>Equals 0</b> Exception type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/// Equals 0 exception implementation.
	class Exception_Equals0 : public Exception_Equals
	{
	public:
		/**
		*	\e Template value move Constructor.
		*
		*	\tparam T				Operands type.
		* 
		*	\param[in] _infos		Base create infos.
		*	\param[in] _lhs			Left hand side operand to compare to T().
		*	\param[in] _predStr		Predicate as a string.
		*	\param[in] _details		Additional details to display on assertion.
		*/
		template <typename T>
		Exception_Equals0(
			BaseInfos&& _infos,
			const T& _lhs,
			std::wstring&& _predStr = L"pred",
			std::wstring&& _details = L""
		) noexcept :
			Exception_Equals(std::move(_infos), _lhs, T(), std::move(_predStr), std::move(_details))
		{
		}
	};

	/// \cond Internal

	/// Define Equals0 Exception creation method.
	#define __SA_CREATE_EXCEPTION_Equals0(_baseInfos, _lhs, ...) SA::Exception_Equals0(\
		_baseInfos,\
		_lhs,\
		SA_WSTR(_lhs) L" == " + SA::ToWString(SA::Intl::GetClassName(_lhs)) + L"{ 0 }",\
		##__VA_ARGS__\
	)

	/// \endcond
}

/**
*	\example Exception_Equals0Tests.cpp
*	Examples and Unitary Tests for Exception_Equals0.
*/


/** \} */

#endif // GUARD

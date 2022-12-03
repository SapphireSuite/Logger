// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_EQUALS_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_EQUALS_GUARD

#include <SA/Logger/Exceptions/Exception.hpp>

#include <SA/Support/Stringify.hpp>

/**
*	\file Exception_Equals.hpp
*
*	\brief \b Equals Exception base type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/// Equals exception base type.
	class Exception_Equals : public Exception
	{
	public:
		/**
		*	\e Template value move Constructor.
		*
		*	\tparam T				Operands type.
		* 
		*	\param[in] _info		Base create info.
		*	\param[in] _lhs			Left hand side operand.
		*	\param[in] _rhs			Left hand side operand.
		*	\param[in] _predStr		Predicate as a string.
		*	\param[in] _details		Additional details to display on assertion.
		*/
		template <typename T>
		Exception_Equals(
			BaseInfo&& _info,
			const T& _lhs,
			const T& _rhs,
			std::wstring&& _predStr = L"pred",
			std::wstring&& _details = L""
		) noexcept;


		/**
		*	\e Float value move Constructor.
		* 
		*	Perform NearlyEquals (epsilon).
		*
		*	\param[in] _info		Base create info.
		*	\param[in] _lhs			Left hand side float operand.
		*	\param[in] _rhs			Left hand side float operand.
		*	\param[in] _predStr		Predicate as a string.
		*	\param[in] _details		Additional details to display on assertion.
		*/
		Exception_Equals(
			BaseInfo&& _info,
			float _lhs,
			float _rhs,
			std::wstring&& _predStr = L"pred",
			std::wstring&& _details = L""
		) noexcept;


		/**
		*	\e Double value move Constructor.
		* 
		*	Perform NearlyEquals (epsilon).
		*
		*	\param[in] _info		Base create info.
		*	\param[in] _lhs			Left hand side double operand.
		*	\param[in] _rhs			Left hand side double operand.
		*	\param[in] _predStr		Predicate as a string.
		*	\param[in] _details		Additional details to display on assertion.
		*/
		Exception_Equals(
			BaseInfo&& _info,
			double _lhs,
			double _rhs,
			std::wstring&& _predStr = L"pred",
			std::wstring&& _details = L""
		) noexcept;
	};


	/// \cond Internal

	/// Define Equals Exception creation method.
	#define __SA_CREATE_EXCEPTION_Equals(_baseInfo, _lhs, _rhs, ...) SA::Exception_Equals(\
		_baseInfo,\
		_lhs,\
		_rhs,\
		SA_WSTR(_lhs) L" == " SA_WSTR(_rhs),\
		##__VA_ARGS__\
	)

	/// \endcond
}

#include <SA/Logger/Exceptions/Exception_Equals.inl>

/**
*	\example Exception_EqualsTests.cpp
*	Examples and Unitary Tests for Exception_Equals.
*/


/** \} */

#endif // GUARD

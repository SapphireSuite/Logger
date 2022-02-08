// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

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


namespace Sa
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
		*	\param[in] _infos		Base create infos.
		*	\param[in] _lhs			Left hand side operand.
		*	\param[in] _rhs			Left hand side operand.
		*	\param[in] _predStr		Predicate as a string.
		*/
		template <typename T>
		Exception_Equals(
			BaseInfos&& _infos,
			const T& _lhs,
			const T& _rhs,
			std::wstring&& _predStr = L"pred"
		) noexcept;


		/**
		*	\e Float value move Constructor.
		* 
		*	Perform NearlyEquals (epsilon).
		*
		*	\param[in] _infos		Base create infos.
		*	\param[in] _lhs			Left hand side float operand.
		*	\param[in] _rhs			Left hand side float operand.
		*	\param[in] _predStr		Predicate as a string.
		*/
		Exception_Equals(
			BaseInfos&& _infos,
			float _lhs,
			float _rhs,
			std::wstring&& _predStr = L"pred"
		) noexcept;


		/**
		*	\e Double value move Constructor.
		* 
		*	Perform NearlyEquals (epsilon).
		*
		*	\param[in] _infos		Base create infos.
		*	\param[in] _lhs			Left hand side double operand.
		*	\param[in] _rhs			Left hand side double operand.
		*	\param[in] _predStr		Predicate as a string.
		*/
		Exception_Equals(
			BaseInfos&& _infos,
			double _lhs,
			double _rhs,
			std::wstring&& _predStr = L"pred"
		) noexcept;
	};


	/// \cond Internal

	/// Define Equals Exception creation method.
	#define __SA_CREATE_EXCEPTION_Equals(_baseInfos, _lhs, _rhs) Sa::Exception_Equals(\
		_baseInfos,\
		_lhs,\
		_rhs,\
		SA_WSTR(_lhs) L" == " SA_WSTR(_rhs)\
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

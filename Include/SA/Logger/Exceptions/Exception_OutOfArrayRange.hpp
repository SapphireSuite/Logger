// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_OUT_OF_ARRAY_RANGE_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_OUT_OF_ARRAY_RANGE_GUARD

#include <SA/Logger/Exceptions/Exception_OutOfRange.hpp>

/**
*	\file Exception_OutOfArrayRange.hpp
*
*	\brief <b>OutOfRange Array Exception</b> type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace SA
{
	/**
	*	\brief OutOfArrayRange Exception type
	* 
	*	Exception will be thrown if curr is out of [0u;_array.size()[ range.
	*/
	class Exception_OutOfArrayRange : public Exception_OutOfRange
	{
	public:
		/**
		*	\e Value move Constructor.
		* 
		*	\param[in] _infos		Base create infos.
		*	\param[in] _currIndex	Index used for access.
		*	\param[in] _array		Array to check bounds with.
		*	\param[in] _details		Additional details to display on assertion.
		*/
		template <typename U>
		Exception_OutOfArrayRange(BaseInfos&& _infos,
			uint32_t _currIndex,
			const U& _array,
			std::wstring&& _details = L"") :
			Exception_OutOfRange(std::move(_infos), _currIndex, 0u, (uint32_t)_array.size() - 1, std::move(_details))
		{
		}
	};


	/// \cond Internal

	/// Define OutOfRange Exception creation method.
	#define __SA_CREATE_EXCEPTION_OutOfArrayRange(_baseInfos, _currIndex, _array, ...) SA::Exception_OutOfArrayRange(\
		_baseInfos,\
		_currIndex,\
		_array,\
		##__VA_ARGS__\
	)

	/// \endcond
}


/**
*	\example Exception_OutOfArrayRangeTests.cpp
*	Examples and Unitary Tests for Exception_OutOfArrayRange.
*/


/** \} */

#endif // GUARD

// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_EXCEPTION_OUT_OF_RANGE_GUARD
#define SAPPHIRE_LOGGER_EXCEPTION_OUT_OF_RANGE_GUARD

#include <SA/Logger/Exceptions/Exception.hpp>

/**
*	\file Exception_OutOfRange.hpp
*
*	\brief <b>OutOfRange Exception</b> type implementation.
*
*	\ingroup Logger_Exception
*	\{
*/


namespace Sa
{
	/**
	*	\brief OutOfRange Exception type
	* 
	*	Exception will be thrown if curr in out of [min;max[
	*/
	class Exception_OutOfRange : public Exception
	{
	public:
		/// Index used for access.
		uint32_t currIndex = 0u;

		/// Minimum bound included.
		uint32_t minBound = 0u;

		/// Maximum bound excluded.
		uint32_t maxBound = 1u;

		/**
		*	\e Value move Constructor.
		* 
		*	\param[in] _infos		Base create infos.
		*	\param[in] _currIndex	Index used for access.
		*	\param[in] _minBound	Minimum bound allowed.
		*	\param[in] _maxBound	Maximum bound allowed.
		*	\param[in] _details		Additional details to display on assertion.
		*/
		Exception_OutOfRange(
			BaseInfos&& _infos,
			uint32_t _currIndex,
			uint32_t _minBound,
			uint32_t _maxBound,
			std::wstring&& _details = L""
		) noexcept;
	};
	

	/// \cond Internal

	/// Define OutOfRange Exception creation method.
	#define __SA_CREATE_EXCEPTION_OutOfRange(_baseInfos, _currIndex, _minBound, _maxBound, ...) Sa::Exception_OutOfRange(\
		_baseInfos,\
		_currIndex,\
		_minBound,\
		_maxBound,\
		##__VA_ARGS__\
	)

	/// \endcond
}


/** \} */

#endif // GUARD

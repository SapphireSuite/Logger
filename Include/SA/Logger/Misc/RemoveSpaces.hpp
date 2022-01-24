// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_RMEOVE_SPACES_GUARD
#define SAPPHIRE_LOGGER_RMEOVE_SPACES_GUARD

#include <string>

/**
*	\file RemoveSpaces.hpp
*
*	\brief Remove spaces in string algorithm implementation.
*
*	\ingroup Logger_Misc
*	\{
*/


namespace Sa
{
	/// \cond Internal

	namespace Intl
	{
		/**
		*	\brief Remove spaces in string.
		*
		*	\param[in] _str	string to remove spaces in.
		*
		*	\return New string without spaces.
		*/
		std::wstring RemoveSpaces(std::wstring _str) noexcept;
	}

	/// \endcond
}


/** \} */

#endif // GUARD

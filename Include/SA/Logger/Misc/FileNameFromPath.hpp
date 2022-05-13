// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_FILE_NAME_FROM_PATH_GUARD
#define SAPPHIRE_LOGGER_FILE_NAME_FROM_PATH_GUARD

/**
*	\file FileNameFromPath.hpp
* 
*	\brief Retreive file name from full path algorithm implementation.
* 
*	\ingroup Logger_Misc
*	\{
*/

namespace SA
{
	/// \cond Internal

	namespace Intl
	{
		/**
		*	\brief \e Getter of file name from file path.
		*
		*	\param[in] _filePath	Full path to the file.
		*
		*	\returns pointer to the file name in _filePath.
		*/
		const wchar_t* FileNameFromPath(const wchar_t* _filePath) noexcept;
	}

	/// \endcond
}


/** \} */

#endif // GUARD

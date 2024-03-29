// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_CONSOLE_COLOR_GUARD
#define SAPPHIRE_LOGGER_CONSOLE_COLOR_GUARD

#include <cstdint>

/**
*	\file ConsoleColor.hpp
*
*	\brief <b>Console Color</b> enum implementation.
*
*	\ingroup Logger_Console
*	\{
*/

namespace SA
{
	/**
	*	\brief Console Color enum.
	*
	*	Bright BG bit		BG Color bits		Bright FG bit		FG Color bits
	*		0					000					0					000
	*/
	enum ConsoleColor : uint8_t
	{
		// 4 bits for foreground attributes.

		// 3 bits for foreground color (text).

		/// Default foreground.
		None_FG = 0,

		/// Red foreground.
		Red_FG = 1,

		/// Green foreground.
		Green_FG = 2,

		/// Blue foreground.
		Blue_FG = 3,

		/// Cyan foreground.
		Cyan_FG = 4,

		/// Magenta foreground.
		Magenta_FG = 5,

		/// Yellow foreground.
		Yellow_FG = 6,

		/// Black foreground.
		Black_FG = 7,


		/// 1 bit for bright attribute.
		Bright_FG = 8,


		// 4 bits for background attributes.

		// 3 bits for background color.

		/// Default background.
		None_BG = 0 << 4,

		/// Red background.
		Red_BG = 1 << 4,

		/// Green background.
		Green_BG = 2 << 4,

		/// Blue background.
		Blue_BG = 3 << 4,

		/// Cyan background.
		Cyan_BG = 4 << 4,

		/// Magenta background.
		Magenta_BG = 5 << 4,

		/// Yellow background.
		Yellow_BG = 6 << 4,

		/// White background.
		White_BG = 7 << 4,


		/// 1 bit for Bright attribute.
		Bright_BG = 8 << 4,

		/// Reset console color value.
		Reset = None_FG | None_BG,
	};

	/// Shortcut alias.
	using CslColor = ConsoleColor;

	/**
	*	\brief \e Crossplatform implementation of set color in console.
	*
	*	\param[in] _cslColor	Console color mask.
	*/
	void SetConsoleColor(ConsoleColor _cslColor);
}

/** \} */

#endif // GUARD

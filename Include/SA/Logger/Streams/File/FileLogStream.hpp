// Copyright(c) 2022 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_FILE_LOG_STREAM_GUARD
#define SAPPHIRE_LOGGER_FILE_LOG_STREAM_GUARD

#include <fstream>

#include <SA/Logger/Streams/ALogStream.hpp>

namespace Sa
{
	class FileLogStream : public ALogStream
	{
	protected:
		/// Handled file stream.
		std::wofstream mHandle;

		/**
		*	\brief Create log and log backup files.
		* 
		*	\param[in] _fileFullPath	Name and path of the log file.
		*/
		void CreateLogFile(const std::string& _fileFullPath);

	public:
		/**
		*	\e Value Constructor
		* 
		*	\param[in] _fileFullPath	Name and path of the file.
		*/
		FileLogStream(const std::string& _fileFullPath = "Logs/log.txt") noexcept;

		/**
		*	\e Destructor. Close the file stream.
		*/
		~FileLogStream() noexcept;

		ALogStream& Output(const Log& _log) override final;
	};
}

#endif // GUARD

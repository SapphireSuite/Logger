// Copyright (c) 2023 Sapphire's Suite. All Rights Reserved.

#include <Exceptions/Exception_OutOfRange.hpp>

namespace SA
{
	Exception_OutOfRange::Exception_OutOfRange(
		BaseInfo _info,
		uint32_t _currIndex,
		uint32_t _minBound,
		uint32_t _maxBound,
		std::wstring _msg,
		std::wstring _details
	) noexcept :
		Exception(std::move(_info),
			_minBound <= _currIndex && _currIndex <= _maxBound,
			std::move(_msg),
			std::move(_details)),
		currIndex{ _currIndex },
		minBound{ _minBound },
		maxBound{ _maxBound }
	{
	}

	Exception_OutOfRange::Exception_OutOfRange(
		BaseInfo _info,
		uint32_t _currIndex,
		std::wstring _currIndexStr,
		uint32_t _minBound,
		std::wstring _minBoundStr,
		uint32_t _maxBound,
		std::wstring _maxBoundStr,
		std::wstring _details
	) noexcept :
		Exception_OutOfRange(std::move(_info),
			_currIndex,
			_minBound,
			_maxBound,
			L"Index \'" + _currIndexStr + L"\' [" + ToWString(_currIndex) + L"] is out of range [\'" + _minBoundStr + L"\';\'" + _maxBoundStr + L"\'] => [" + ToWString(_minBound) + L';' + ToWString(_maxBound) + L']',
			std::move(_details))
	{
	}
}

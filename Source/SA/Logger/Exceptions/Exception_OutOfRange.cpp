// Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

#include <Exceptions/Exception_OutOfRange.hpp>

namespace SA
{
	Exception_OutOfRange::Exception_OutOfRange(
		BaseInfos&& _infos,
		uint32_t _currIndex,
		uint32_t _minBound,
		uint32_t _maxBound,
		std::wstring&& _details
	) noexcept :
		Exception(std::move(_infos),
			_minBound <= _currIndex && _currIndex <= _maxBound,
			L"Index [" + ToWString(_currIndex) + L"] is out of range [" + ToWString(_minBound) + L',' + ToWString(_maxBound) + L']',
			std::move(_details)),
		currIndex{ _currIndex },
		minBound{ _minBound },
		maxBound{ _maxBound }
	{
	}
}

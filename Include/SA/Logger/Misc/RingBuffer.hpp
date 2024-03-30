// Copyright (c) 2024 Sapphire's Suite. All Rights Reserved.

#pragma once

#ifndef SAPPHIRE_LOGGER_RING_BUFFER_GUARD
#define SAPPHIRE_LOGGER_RING_BUFFER_GUARD

#include <atomic>
#include <thread>

namespace SA
{
	template <typename T>
	class RingBuffer
	{
		T* mHandleBuffer = nullptr;
		std::atomic<bool>* mPushCompleted = nullptr;

		const uint32_t mCapacity = 0;

		std::atomic<uint32_t> mPushCursor = 0;
		std::atomic<uint32_t> mPopCursor = 0;

	public:
		RingBuffer(uint32_t _capacity = 32);
		~RingBuffer();

		void Push(T&& _obj);
		T Pop();

		uint32_t Size() const noexcept;
		uint32_t Capacity() const noexcept;

		bool IsEmpty() const noexcept;
		bool IsFull() const noexcept;
	};
}

#include "RindBuffer.inl"

#endif // SAPPHIRE_LOGGER_RING_BUFFER_GUARD

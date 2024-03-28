// Copyright (c) 2024 Sapphire's Suite. All Rights Reserved.

namespace SA
{
	template <typename T>
	RingBuffer<T>::RingBuffer(uint32_t _capacity)
	{
		mRingBuffer.resize(_capacity);
	}


	template <typename T>
	void RingBuffer<T>::Push(T&& _obj)
	{
		while (IsFull())
			std::this_thread::yield();

		const uint32_t index = mPushCursor = (mPushCursor + 1) % Capacity();

		mRingBuffer[index].obj = std::move(_obj);

#if SA_DEBUG || 1

		if (mRingBuffer[index].bCompleted)
		{
			throw std::string("DATA RACE");
		}

#endif

		mRingBuffer[index].bCompleted = true;
	}

	template <typename T>
	T RingBuffer<T>::Pop()
	{
		//while (IsEmpty())
		//	std::this_thread::yield();

		const uint32_t index = mPopCursor = (mPopCursor + 1) % Capacity();

		while(!mRingBuffer[index].bCompleted)
			std::this_thread::yield();

		// Reset for next use.
		mRingBuffer[index].bCompleted = false;

		return std::move(mRingBuffer[index].obj);
	}


	template <typename T>
	uint32_t RingBuffer<T>::Size() const noexcept
	{
		return mPushCursor - mPopCursor;
	}

	template <typename T>
	uint32_t RingBuffer<T>::Capacity() const noexcept
	{
		return static_cast<uint32_t>(mRingBuffer.size());
	}

	
	template <typename T>
	bool RingBuffer<T>::IsEmpty() const noexcept
	{
		return Size() == 0;
	}
	
	template <typename T>
	bool RingBuffer<T>::IsFull() const noexcept
	{
		return Size() == Capacity();
	}
}

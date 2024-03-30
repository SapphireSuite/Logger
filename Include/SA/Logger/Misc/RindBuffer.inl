// Copyright (c) 2024 Sapphire's Suite. All Rights Reserved.

namespace SA
{
	template <typename T>
	RingBuffer<T>::RingBuffer(uint32_t _capacity) :
		mCapacity { _capacity }
	{
		mHandleBuffer = static_cast<T*>(::operator new(_capacity * sizeof(T)));
		mPushCompleted = new std::atomic<bool>[_capacity];
	}

	template <typename T>
	RingBuffer<T>::~RingBuffer()
	{
		::operator delete(mHandleBuffer);
		delete[] mPushCompleted;
	}


	template <typename T>
	void RingBuffer<T>::Push(T&& _obj)
	{
		while (IsFull())
			std::this_thread::yield();

		const uint32_t index = mPushCursor = (mPushCursor + 1) % Capacity();

		new(&mHandleBuffer[index]) T(std::move(_obj));

#if SA_DEBUG || 1

		if (mPushCompleted[index])
		{
			throw std::string("DATA RACE");
		}

#endif

		mPushCompleted[index] = true;
	}

	template <typename T>
	T RingBuffer<T>::Pop()
	{
		//while (IsEmpty())
		//	std::this_thread::yield();

		const uint32_t index = mPopCursor = (mPopCursor + 1) % Capacity();

		while(!mPushCompleted[index])
			std::this_thread::yield();

		// Reset for next use.
		mPushCompleted[index] = false;

		T output = std::move(mHandleBuffer[index]);

		mHandleBuffer[index].~T();

		return std::move(output);
	}


	template <typename T>
	uint32_t RingBuffer<T>::Size() const noexcept
	{
		return mPushCursor - mPopCursor;
	}

	template <typename T>
	uint32_t RingBuffer<T>::Capacity() const noexcept
	{
		return mCapacity;
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

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
		// Reserve index.
		const uint32_t index = mPushCursor++;

		/**
		 * Check is full
		 * Can be out of mCapacity range for index queue.
		*/
		while(index - mPopCursor >= mCapacity)
			std::this_thread::yield();

		new(&mHandleBuffer[index % mCapacity]) T(std::move(_obj));
		mPushCompleted[index % mCapacity] = true;



	#if 0 // V1 (tuto)
		while (IsFull())
			std::this_thread::yield();

		new(&mHandleBuffer[mPushCursor % mCapacity]) T(std::move(_obj));
		++mPushCursor;
	#endif


	#if 0 // V2
		while (IsFull())
			std::this_thread::yield();

		const uint32_t index = mPushCursor++;
		new(&mHandleBuffer[index % mCapacity]) T(std::move(_obj));
		mPushCompleted[index % mCapacity] = true;
	#endif





	/*
		const uint32_t index = (mPushCursor++) % mCapacity;
		//const uint32_t index = mPushCursor = (mPushCursor + 1) % Capacity();

		new(&mHandleBuffer[index]) T(std::move(_obj));

// #if SA_DEBUG || 1

// 		if (mPushCompleted[index])
// 		{
// 			throw std::string("DATA RACE");
// 		}

// #endif

		mPushCompleted[index] = true;
	*/
	}

	template <typename T>
	T RingBuffer<T>::Pop()
	{
		while(IsEmpty())
			std::this_thread::yield();

		const uint32_t index = mPopCursor % mCapacity;

		while(!mPushCompleted[index])
			std::this_thread::yield();

		T output = std::move(mHandleBuffer[index]);

		mHandleBuffer[index].~T();

		// Reset for next use.
		mPushCompleted[index] = false;

		++mPopCursor;



	#if 0 // V1 (tuto)
		T output = std::move(mHandleBuffer[mPopCursor % mCapacity]);
		mHandleBuffer[mPopCursor % mCapacity].~T();
		++mPopCursor;
	#endif



	#if 0 // V2
		const uint32_t index = mPopCursor;

		while(!mPushCompleted[index % mCapacity])
			std::this_thread::yield();

		T output = std::move(mHandleBuffer[index % mCapacity]);

		mHandleBuffer[index % mCapacity].~T();
		
		// Reset for next use.
		mPushCompleted[index % mCapacity] = false;

		++mPopCursor;
	#endif







		// const uint32_t index = (mPopCursor++) % mCapacity;
		// //const uint32_t index = mPopCursor = (mPopCursor + 1) % Capacity();

		// while(!mPushCompleted[index])
		// 	std::this_thread::yield();

		// // Reset for next use.
		// mPushCompleted[index] = false;

		// T output = std::move(mHandleBuffer[index]);

		// mHandleBuffer[index].~T();

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

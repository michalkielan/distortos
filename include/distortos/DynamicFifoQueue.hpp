/**
 * \file
 * \brief DynamicFifoQueue class header
 *
 * \author Copyright (C) 2015 Kamil Szczygiel http://www.distortec.com http://www.freddiechopin.info
 *
 * \par License
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not
 * distributed with this file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * \date 2015-10-20
 */

#ifndef INCLUDE_DISTORTOS_DYNAMICFIFOQUEUE_HPP_
#define INCLUDE_DISTORTOS_DYNAMICFIFOQUEUE_HPP_

#include "FifoQueue.hpp"

#include "distortos/memory/dummyDeleter.hpp"

namespace distortos
{

/**
 * \brief DynamicFifoQueue class is a wrapper for FifoQueue that also provides dynamic storage for queue's contents.
 *
 * \note Objects of this class can be safely casted to (const) reference to FifoQueue.
 *
 * \param T is the type of data in queue
 */

template<typename T>
class DynamicFifoQueue
{
public:

	/// unique_ptr to uninitialized storage for data
	using StorageUniquePointer = std::unique_ptr<typename FifoQueue<T>::Storage>;

	/**
	 * \brief DynamicFifoQueue's constructor
	 *
	 * \param [in] queueSize is the maximum number of elements in queue
	 */

	explicit DynamicFifoQueue(size_t queueSize);

	/**
	 * \brief DynamicFifoQueue's destructor
	 */

	~DynamicFifoQueue();

	/**
	 * \brief conversion to FifoQueue<T>&
	 *
	 * \return reference to internal FifoQueue<T> object
	 */

	operator FifoQueue<T>&()
	{
		return fifoQueue_;
	}

	/**
	 * \brief conversion to const FifoQueue<T>&
	 *
	 * \return const reference to internal FifoQueue<T> object
	 */

	operator const FifoQueue<T>&() const
	{
		return fifoQueue_;
	}

#if DISTORTOS_FIFOQUEUE_EMPLACE_SUPPORTED == 1 || DOXYGEN == 1

	/**
	 * \brief Wrapper for FifoQueue::emplace()
	 */

	template<typename... Args>
	int emplace(Args&&... args)
	{
		return fifoQueue_.emplace(std::forward<Args>(args)...);
	}

#endif	// DISTORTOS_FIFOQUEUE_EMPLACE_SUPPORTED == 1 || DOXYGEN == 1

	/**
	 * \brief Wrapper for FifoQueue::pop()
	 */

	int pop(T& value)
	{
		return fifoQueue_.pop(value);
	}

	/**
	 * \brief Wrapper for FifoQueue::push(const T&)
	 */

	int push(const T& value)
	{
		return fifoQueue_.push(value);
	}

	/**
	 * \brief Wrapper for FifoQueue::push(T&&)
	 */

	int push(T&& value)
	{
		return fifoQueue_.push(std::move(value));
	}

#if DISTORTOS_FIFOQUEUE_EMPLACE_SUPPORTED == 1 || DOXYGEN == 1

	/**
	 * \brief Wrapper for FifoQueue::tryEmplace()
	 */

	template<typename... Args>
	int tryEmplace(Args&&... args)
	{
		return fifoQueue_.tryEmplace(std::forward<Args>(args)...);
	}

	/**
	 * \brief Wrapper for FifoQueue::tryEmplaceFor()
	 */

	template<typename Rep, typename Period, typename... Args>
	int tryEmplaceFor(const std::chrono::duration<Rep, Period> duration, Args&&... args)
	{
		return fifoQueue_.tryEmplaceFor(duration, std::forward<Args>(args)...);
	}

	/**
	 * \brief Wrapper for FifoQueue::tryEmplaceUntil()
	 */

	template<typename Duration, typename... Args>
	int tryEmplaceUntil(const std::chrono::time_point<TickClock, Duration> timePoint, Args&&... args)
	{
		return fifoQueue_.tryEmplaceUntil(timePoint, std::forward<Args>(args)...);
	}

#endif	// DISTORTOS_FIFOQUEUE_EMPLACE_SUPPORTED == 1 || DOXYGEN == 1

	/**
	 * \brief Wrapper for FifoQueue::tryPop()
	 */

	int tryPop(T& value)
	{
		return fifoQueue_.tryPop(value);
	}

	/**
	 * \brief Wrapper for FifoQueue::tryPopFor()
	 */

	template<typename Rep, typename Period>
	int tryPopFor(const std::chrono::duration<Rep, Period> duration, T& value)
	{
		return fifoQueue_.tryPopFor(duration, value);
	}

	/**
	 * \brief Wrapper for FifoQueue::tryPopUntil()
	 */

	template<typename Duration>
	int tryPopUntil(const std::chrono::time_point<TickClock, Duration> timePoint, T& value)
	{
		return fifoQueue_.tryPopUntil(timePoint, value);
	}

	/**
	 * \brief Wrapper for FifoQueue::tryPush(const T&)
	 */

	int tryPush(const T& value)
	{
		return fifoQueue_.tryPush(value);
	}

	/**
	 * \brief Wrapper for FifoQueue::tryPush(T&&)
	 */

	int tryPush(T&& value)
	{
		return fifoQueue_.tryPush(std::move(value));
	}

	/**
	 * \brief Wrapper for FifoQueue::tryPushFor(std::chrono::duration<Rep, Period>, const T&)
	 */

	template<typename Rep, typename Period>
	int tryPushFor(const std::chrono::duration<Rep, Period> duration, const T& value)
	{
		return fifoQueue_.tryPushFor(duration, value);
	}

	/**
	 * \brief Wrapper for FifoQueue::tryPushFor(std::chrono::duration<Rep, Period>, T&&)
	 */

	template<typename Rep, typename Period>
	int tryPushFor(const std::chrono::duration<Rep, Period> duration, T&& value)
	{
		return fifoQueue_.tryPushFor(duration, std::move(value));
	}

	/**
	 * \brief Wrapper for FifoQueue::tryPushUntil(std::chrono::time_point<TickClock, Duration>, const T&)
	 */

	template<typename Duration>
	int tryPushUntil(const std::chrono::time_point<TickClock, Duration> timePoint, const T& value)
	{
		return fifoQueue_.tryPushUntil(timePoint, value);
	}

	/**
	 * \brief Wrapper for FifoQueue::tryPushUntil(std::chrono::time_point<TickClock, Duration>, T&&)
	 */

	template<typename Duration>
	int tryPushUntil(const std::chrono::time_point<TickClock, Duration> timePoint, T&& value)
	{
		return fifoQueue_.tryPushUntil(timePoint, std::move(value));
	}

	DynamicFifoQueue(const DynamicFifoQueue&) = delete;
	DynamicFifoQueue(DynamicFifoQueue&&) = default;
	const DynamicFifoQueue& operator=(const DynamicFifoQueue&) = delete;
	DynamicFifoQueue& operator=(DynamicFifoQueue&&) = delete;

private:

	/// unique_ptr to allocated storage for queue's contents
	StorageUniquePointer storageUniquePointer_;

	/// internal FifoQueue<T> object
	FifoQueue<T> fifoQueue_;
};

template<typename T>
DynamicFifoQueue<T>::DynamicFifoQueue(const size_t queueSize) :
		storageUniquePointer_{new typename StorageUniquePointer::element_type[queueSize]},
		fifoQueue_{{storageUniquePointer_.get(), memory::dummyDeleter}, queueSize}
{

}

template<typename T>
DynamicFifoQueue<T>::~DynamicFifoQueue()
{

}

}	// namespace distortos

#endif	// INCLUDE_DISTORTOS_DYNAMICFIFOQUEUE_HPP_
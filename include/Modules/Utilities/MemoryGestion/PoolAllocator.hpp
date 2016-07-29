/*!
 * \brief TODO
 * \file PoolAllocator.hpp
 * \author Exidhor
 * \version 0.1
 * \date 2016-07-29
 */

#ifndef DEF_POOL_ALLOCATOR_HPP
#define DEF_POOL_ALLOCATOR_HPP

#include <iostream>
#include <stdlib.h>

#include "Modules/ModConfig.hpp"

/*!
 * \class PoolAlocator
 * \brief Allocate elements from the same Type
 *        in a reserved memory emplacement.
 *
 */
template <class T>
class UTILITIES_API PoolAllocator
{
public:
	/*!
	 * \brief TODO
	 */
	PoolAllocator();

	/*!
	 * \brief TODO
	 */
	~PoolAllocator();

	/**
	 * \brief TODO
	 * \param TODO
	 */
	void init(unsigned int numberOfElements);

	/**
	 * \brief TODO
	 * \return TODO
	 */
	T* getFreeElement();

	/**
	 * \brief TODO
	 * \param TODO
	 */
	void removeElement(unsigned int index);

private:
	/**
	 * \brief TODO
	 */
	void clear();

	/**
	 * \brief TODO
	 * \param TODO
	 * \return TODO
	 */
	int getNextFreeIndex(unsigned int elementIndex);

	/**
	 * \brief TODO
	 * \param TODO
	 * \param TODO
	 */
	void writeNextFreeIndex(unsigned int elementIndex, int newIndex);

	T* m_start;
	unsigned int m_poolSize;
	int m_indexNextFreeElement;
};

#endif // DEF_POOL_ALLOCATOR_HPP
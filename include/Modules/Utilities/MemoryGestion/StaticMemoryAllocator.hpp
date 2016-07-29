/*!
 * \brief TODO
 * \file StaticMemoryAllocator.hpp
 * \author Exidhor
 * \version 0.1
 * \date 2016-07-29
 */

#ifndef DEF_STATIC_MEMORY_ALLOCATOR_HPP
#define DEF_STATIC_MEMORY_ALLOCATOR_HPP

#include <iostream>
#include <stdlib.h>

#include "Modules/ModConfig.hpp"

/*!
 * \class PoolAlocator
 * \brief The Stack Mechanism to allocate elements
 *
 */
class UTILITIES_API StaticMemoryAllocator
{
public :
	/**
	 * \brief TODO
	 */
	StaticMemoryAllocator();

	/**
	 * \brief TODO
	 */
	~StaticMemoryAllocator();

	/**
	 * \brief TODO
	 * \param TODO
	 */
	void init(unsigned int sizeInBytes);

	/**
	 * \brief TODO
	 * \param TODO
	 */
	void * allocate(unsigned int sizeInBytes);

private :

	/**
	 * \brief TODO
	 */
	void clear();

	/**
	 * \brief TODO
	 */
	void * m_start;

	unsigned int m_sizeInBytes;
	unsigned int m_currentHeadPosition;
};

#endif // DEF_STATIC_MEMORY_ALLOCATOR_HPP
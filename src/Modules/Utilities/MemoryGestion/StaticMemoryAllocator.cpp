/*!
 * \brief TODO
 * \file StaticMemoryAllocator.cpp
 * \author Exidhor
 * \version 0.1
 * \date 2016-07-29
 */
#include "Modules/Utilities/MemoryGestion/StaticMemoryAllocator.hpp"

StaticMemoryAllocator::StaticMemoryAllocator()
{
	m_start = nullptr;
	m_currentHeadPosition = 0;
	m_sizeInBytes = 0;
}

StaticMemoryAllocator::~StaticMemoryAllocator()
{
	clear();
}

void StaticMemoryAllocator::init(unsigned int sizeInBytes)
{
	m_sizeInBytes = sizeInBytes;
	m_start = malloc(m_sizeInBytes);
	m_currentHeadPosition = 0;
}

void* StaticMemoryAllocator::allocate(unsigned int sizeInBytes)
{
	m_currentHeadPosition += sizeInBytes;

	if (m_currentHeadPosition > m_sizeInBytes)
	{
		std::cerr << "ERROR : not enough free memory to allocate " << sizeInBytes << "." << std::endl;
		std::cerr << "\tCurrent head position : " << m_currentHeadPosition << std::endl;
		std::cerr << "\tStack size : " << m_sizeInBytes << std::endl;
		return nullptr;
	}

	return (void*)((char*)m_start + m_currentHeadPosition - sizeInBytes);
}

void StaticMemoryAllocator::clear() {
	free(m_start);
}
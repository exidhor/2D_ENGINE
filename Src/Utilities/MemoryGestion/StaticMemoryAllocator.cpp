#include "Utilities/MemoryGestion/StaticMemoryAllocator.hpp"

StaticMemoryAllocator::StaticMemoryAllocator()
{
	m_start = nullptr;
	m_curentHeadPosition = 0;
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
	m_curentHeadPosition = 0;
}

void* StaticMemoryAllocator::allocate(unsigned int sizeInBytes)
{
	m_curentHeadPosition += sizeInBytes;

	if (m_curentHeadPosition > m_sizeInBytes)
	{
		std::cerr << "ERROR : not enough free memory to allocate " << sizeInBytes << "." << std::endl;
		std::cerr << "\tCurrent head position : " << m_curentHeadPosition << std::endl;
		std::cerr << "\tStack size : " << m_sizeInBytes << std::endl;
		return nullptr;
	}

	return (void*)((char*)m_start + m_curentHeadPosition - sizeInBytes);
}

void StaticMemoryAllocator::clear()
{
	free(m_start);
}
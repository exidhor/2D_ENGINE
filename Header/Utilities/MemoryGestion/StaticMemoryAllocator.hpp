#pragma once
#include <iostream>
#include <stdlib.h>

/*
* \brief	TODO
*/
class StaticMemoryAllocator
{
public :
	StaticMemoryAllocator();
	~StaticMemoryAllocator();

	void init(unsigned int sizeInBytes);
	void* allocate(unsigned int sizeInBytes);

private :
	void clear();

	void* m_start;
	unsigned int m_sizeInBytes;
	unsigned int m_curentHeadPosition;
};
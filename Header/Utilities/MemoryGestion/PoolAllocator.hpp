#pragma once
#include <iostream>
#include <stdlib.h>

//#define Test PoolAllocator<long>

/*
* \brief	Allocate elements from the same Type
			in a reserved memory emplacement.
*/
template <class T>
class PoolAllocator
{
public:
	PoolAllocator();
	~PoolAllocator();

	void init(unsigned int numberOfElements);
	T* getFreeElement();
	void removeElement(unsigned int index);

private:
	void clear();
	int getNextFreeIndex(unsigned int elementIndex);
	void writeNextFreeIndex(unsigned int elementIndex, int newIndex);

	T* m_start;
	int m_indexNextFreeElement;
	unsigned int m_poolSize;
};
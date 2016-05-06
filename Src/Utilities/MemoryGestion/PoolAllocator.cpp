#include "Utilities/MemoryGestion/PoolAllocator.hpp"

template class PoolAllocator < long >;

template <class T>
PoolAllocator<T>::PoolAllocator()
{
	m_start = nullptr;
	m_indexNextFreeElement = 0;
	m_poolSize = 0;
}

template <class T>
PoolAllocator<T>::~PoolAllocator()
{
	clear();
}

template <class T>
void PoolAllocator<T>::init(unsigned int numberOfElements)
{
	m_poolSize = numberOfElements;
	m_start =(T*) malloc(sizeof(T) * m_poolSize);
	m_indexNextFreeElement = 0;

	for (unsigned int i = 0; i < m_poolSize - 1; i++)
	{
		writeNextFreeIndex(i, i + 1);
	}
	// the last free emplacement point to nullptr 
	writeNextFreeIndex(m_poolSize - 1, -1);
}

template <class T>
T* PoolAllocator<T>::getFreeElement()
{
	T* returnFreeElement = &m_start[m_indexNextFreeElement];
	m_indexNextFreeElement = getNextFreeIndex(m_indexNextFreeElement);

	return returnFreeElement;
}

template <class T>
void PoolAllocator<T>::removeElement(unsigned int indexToFree)
{
	if ((unsigned int)m_indexNextFreeElement > indexToFree || 
		m_indexNextFreeElement == -1)
	{
		writeNextFreeIndex(indexToFree, m_indexNextFreeElement);
		m_indexNextFreeElement = indexToFree;
	}
	else
	{
		int nextIndex = getNextFreeIndex(m_indexNextFreeElement);
		int lastIndex = m_indexNextFreeElement;

		while (indexToFree > (unsigned int)nextIndex)
		{
			lastIndex = nextIndex;
			nextIndex = getNextFreeIndex(nextIndex);
		}

		writeNextFreeIndex(lastIndex, indexToFree);
		writeNextFreeIndex(indexToFree, nextIndex);
	}
}

template <class T>
void PoolAllocator<T>::clear()
{
	free((void*)m_start);
}

template <class T>
int PoolAllocator<T>::getNextFreeIndex(unsigned int elementIndex)
{
	// cast T-th element address in void*
	// cast the void* in the int*
	// return the index of the next emplacement
	return *((int*)((void*)(&m_start[elementIndex])));
}

template <class T>
void PoolAllocator<T>::writeNextFreeIndex(unsigned int elementIndex, int newIndex)
{
	// cast T-th element address in void*
	// cast the void* in the int*
	// take the emplacement, and write the index of the next emplacement
	*((int*)((void*)(&m_start[elementIndex]))) = newIndex;
}
#pragma once

/*
* \brief	TODO (i don't know which is the purpose of this, 
			the global management ... ?)
*/
class MemoryManagement
{
public :
	MemoryManagement();
	~MemoryManagement();
	
private :
	void* m_startArray;
	int m_sizeArray;
	int m_cacheAllocator;
};
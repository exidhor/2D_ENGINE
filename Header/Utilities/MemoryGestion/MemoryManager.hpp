#pragma once

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
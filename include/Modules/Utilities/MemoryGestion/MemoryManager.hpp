/*!
 * \brief TODO
 * \file MemoryManager.cpp
 * \author Exidhor
 * \version 0.1
 * \date 2016-07-29
 */

#ifndef DEF_MEMORY_MANAGER_HPP
#define DEF_MEMORY_MANAGER_HPP

#include "Modules/ModConfig.hpp"

/*!
 * \class MemoryManager
 * \brief Allocate elements from the same Type
 *        in a reserved memory emplacement.
 *
 */
class UTILITIES_API MemoryManager
{
public :
    /**
     * \brief
     */
	MemoryManager();

    /**
     * \brief
     */
	~MemoryManager();
	
private :

	int m_sizeArray;
    void * m_startArray;
	int m_cacheAllocator;
};

#endif // DEF_MEMORY_MANAGER_HPP
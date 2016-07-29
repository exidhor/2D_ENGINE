/*!
* \brief TODO
* \file HashTable.hpp
* \author Exidhor
* \version 0.1
* \date 2016-07-29
*/

#ifndef DEF_HASHTABLE_HPP
#define DEF_HASHTABLE_HPP

#include <string>

#include "Modules/ModConfig.hpp"

/*! \class HashTable
* \brief TODO
*
*/
class UTILITIES_API HashTable
{
public:
    /**
     * \brief TODO
     */
    HashTable();

    /**
     * \brief TODO
     * \param TODO
     * \return TODO
     */
    int getHashValue(const std::string& key);
};


#endif // DEF_HASHTABLE_HPP

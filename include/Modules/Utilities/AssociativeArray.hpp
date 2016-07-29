/*!
* \brief TODO
* \file AssociativeArray.hpp
* \author Exidhor
* \version 0.1
* \date 2016-07-29
*/
#ifndef DEF_ASSOCIATIVE_ARRAY_HPP
#define DEF_ASSOCIATIVE_ARRAY_HPP

#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#include "Modules/ModConfig.hpp"

/*!
 * \class AssociativeArray
 * \brief A optimized map to be able to cycle quickly and
 *        provide a key-string mechanism.
 *
 */
template < typename T >
class UTILITIES_API AssociativeArray
{
	public:
        /*!
         * \brief TODO
         */
		AssociativeArray();

        /*!
         * \brief TODO
         * \param TODO
         */
		AssociativeArray(unsigned int numberOfElementsToReserve);

        /*!
         * \brief TODO
         * \param TODO
         */
		AssociativeArray(AssociativeArray<T> const& associativeArray);

        /*!
         * \brief TODO
         */
		~AssociativeArray();

        /*!
         * \brief TODO
         * \param TODO
         */
		void reserve(unsigned int numberOfElements);

        /*!
         * \brief TODO
         * \param TODO
         */
		T &operator[](int i);

        /*!
         * \brief TODO
         * \param TODO
         * \return TODO
         */
		T getByKey(std::string const key);

        /*!
         * \brief TODO
         * \param TODO
         * \param TODO
         * \return TODO
         */
		bool add(T element, std::string const& key);

        /*!
         * \brief TODO
         * \param TODO
         * \return TODO
         */
		bool remove(std::string const& key);

	private:

        /*!
         * \brief TODO
         * \param TODO
         * \return TODO
         */
		int getIndex(std::string const &key);

        /*!
         * \brief TODO
         * \param TODO
         * \return TODO
         */
		bool keyExists(std::string const& key);

        /*!
         * \brief TODO
         * \param TODO
         * \return TODO
         */
		bool addElement(T element);

		std::vector <T> m_container;
        std::queue <int> m_emptyLocations;
		std::unordered_map <std::string, int> m_keys;
};

#endif // DEF_ASSOCIATIVE_ARRAY_HPP
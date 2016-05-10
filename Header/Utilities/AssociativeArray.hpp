#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>

/*
* \brief	A otpimized map to be able to cycle quickly and
			provide a key-string mecanism.
*/
template < typename T >
class AssociativeArray
{
	public:
		AssociativeArray();
		AssociativeArray(int numberOfElementsToReserve);
		AssociativeArray(AssociativeArray<T> const& associativeArray);
		~AssociativeArray();

		void reserve(int numberOfElements);

		T &operator[](int i);
		T getByKey(std::string const key);

		bool add(T element, std::string const& key);
		bool remove(std::string const& key);

	private:
		int getIndice(std::string const& key);
		bool keyExists(std::string const& key);
		bool addElement(T element);

		std::vector <T> m_container;
		std::unordered_map <std::string, int> m_keys;
		std::queue <int> m_emptyLocations;
};
#include "Utilities/AssociativeArray.hpp"

template < typename T >
AssociativeArray<T>::AssociativeArray()
{}

template < typename T >
AssociativeArray<T>::AssociativeArray(int numberOfElementsToReserve)
{
	reserve(numberOfElementsToReserve);
}

template < typename T >
AssociativeArray<T>::AssociativeArray(AssociativeArray<T> const& associativeArray)
	: m_container(associativeArray.m_container),
	m_emptyLocations(associativeArray.m_emptyLocations),
	m_keys(associativeArray.m_keys)
{}

template < typename T >
AssociativeArray<T>::~AssociativeArray()
{
	m_container.clear();
	m_keys.clear();
    m_emptyLocations.clear();
}

template < typename T >
void AssociativeArray<T>::reserve(int numberOfElements)
{
	m_container.reserve(numberOfElements);
	m_keys.reserve(numberOfElements);
}

template < typename T >
T& AssociativeArray<T>::operator[](int i)
{
	return m_container[i];
}

template < typename T >
T AssociativeArray<T>::getByKey(std::string const key)
{
	return m_container[getIndice(key)];
}

template < typename T >
bool AssociativeArray<T>::add(T element, std::string const& key)
{
	if (keyExists(key))
	{
		std::cerr << "Key already exists" << std::endl;
		return false;
	}

	if (addElement(element))
	{
		std::cout << "Construction element [" + key + "]" << std::endl;
	}
	return true;
}

template < typename T >
bool AssociativeArray<T>::remove(std::string const& key)
{

}

template < typename T >
int AssociativeArray<T>::getIndice(std::string const& key)
{
	return m_key[key];
}

template < typename T >
bool AssociativeArray<T>::keyExists(std::string const& key)
{
	return m_keys.end() == m_keys.find(key);
}

template < typename T >
bool AssociativeArray<T>::addElement(T element)
{
	// check if there is some void locations
	if (m_emptyLocations.empty())
}
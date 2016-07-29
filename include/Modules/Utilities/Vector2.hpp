/*!
* \brief TODO
* \file Vector2.hpp
* \author Exidhor
* \version 0.1
* \date 2016-07-29
*/

#ifndef DEF_VECTOR2_HPP
#define DEF_VECTOR2_HPP

#include "Modules/ModConfig.hpp"

/*! \class Vector2
* \brief TODO
*
*/
template < typename T >
class UTILITIES_API Vector2
{
public :
	/*!
	* \brief initialize with (0,0) values
	*/
	Vector2()
	{
		this->x = 0;
		this->y = 0;
	}

    /*!
     * \brief TODO
     * \param TODO
     * \param TODO
     * \return TODO
     */
	Vector2(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

    /**
     * \brief TODO
     * \param TODO
     * \return TODO
     */
	template < typename U >
	Vector2(Vector2<U> const& vector2)
	{
		x = (T)vector2.x;
		y = (T)vector2.y;
	}

	T x;
	T y;
};

typedef Vector2<int> Vector2i;
typedef Vector2<long> Vector2l;
typedef Vector2<float> Vector2f;
typedef Vector2<double>  Vector2d;
typedef Vector2<unsigned int> Vector2u;

#endif // DEF_VECTOR2_HPP
#pragma once
#include "Engines/Config.hpp"

/*
 * \brief	A point.
*/
class PHYSIC_API Point
{
public :
	Point();
	Point(float abscissa, float ordinate);
	Point(Point const& point);

	
	float abscissa;
	float ordinate;
};
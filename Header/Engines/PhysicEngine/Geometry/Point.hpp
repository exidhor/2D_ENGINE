#pragma once

/*
 * \brief	TODO
*/
class Point
{
public :
	Point();
	Point(float abscissa, float ordinate);
	Point(Point const& point);

	
	float abscissa;
	float ordinate;
};
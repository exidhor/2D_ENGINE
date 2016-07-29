#pragma once
#include "Engines/PhysicEngine/Geometry/Point.hpp"
#include "Engines/PhysicEngine/Geometry/Size.hpp"
#include "Engines/Config.hpp"
/*
* \brief	A Rectangle.
*/
class PHYSIC_API Rectangle
{
public:
	Rectangle();
	Rectangle(Size const& size);
	Rectangle(Point const& position, Size const& size);
	Rectangle(float abscissa, float ordinate, float width, float height);

	float abscissa;
	float ordinate;
	float width;
	float height;
};
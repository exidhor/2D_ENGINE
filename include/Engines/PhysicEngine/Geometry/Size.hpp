#pragma once
#include "Engines/Config.hpp"

/*
* \brief	TODO
*/
class PHYSIC_API Size
{
public:
	Size();
	Size(float width, float height);
	Size(Size const& size);


	float width;
	float height;
};
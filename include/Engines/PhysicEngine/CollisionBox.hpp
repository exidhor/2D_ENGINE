#pragma once
#include "Engines/PhysicEngine/Geometry.hpp"
#include "Engines/Config.hpp"
/*
* \brief	TODO (manage the collision bounds of an entity)
*/
class PHYSIC_API CollisionBox
{
public:
	CollisionBox();

	bool estEnCollision(CollisionBox const& collisionBox) const;
	bool contientPoint(float abscissa, float ordinate) const;

	void setPosition(float abscissa, float ordinate);
	void setPosition(Point const& point);
	void setSize(float width, float height);
	void setSize(Size const& size);

	Point getPosition() const;
	Size getSize() const;

private:
	Rectangle rectangle;
};
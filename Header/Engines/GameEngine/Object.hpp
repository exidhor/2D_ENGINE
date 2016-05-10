#pragma once
#include "Engines/PhysicEngine.hpp"
#include "Engines/GraphicEngine.hpp"

/* 
 * \brief	An Object of the Game (i.e. a GameObject for Unity).
 */
class Object
{
public:
	Object();
	virtual ~Object();

private:
	CollisionBox	m_collisionBox;
	GraphicMonsters::Sprite		m_sprite;
};
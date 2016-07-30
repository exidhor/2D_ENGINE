#include "Engines/GraphicEngine/Transformation.hpp"

GraphicMonsters::Transformation::Transformation()
{
	m_quadVertices = NULL;
	m_isInfinite = false;
	m_isOn = false;
}

GraphicMonsters::Transformation::~Transformation()
{
	//void
}

void GraphicMonsters::Transformation::initAttribute(GraphicMonsters::QuadVertices* newQuadVertices)
{
	m_quadVertices = newQuadVertices;
}

void GraphicMonsters::Transformation::start()
{
	m_isOn = true;
}

void GraphicMonsters::Transformation::stop()
{
	m_isOn = false;
}

void GraphicMonsters::Transformation::setIsInfinite(bool state)
{
	m_isInfinite = state;
}
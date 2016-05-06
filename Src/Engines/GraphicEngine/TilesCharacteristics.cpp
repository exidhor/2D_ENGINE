#include "Engines/GraphicEngine/TilesCharacteristics.hpp"

GraphicMonsters::TilesCharacteristics::TilesCharacteristics(
	Vector2f const& newtileSize,
	std::vector <Vector2f> newTexturePoints,
	double newTimePerFrame)
{
	m_tileSize = newtileSize;
	m_texturePoints = newTexturePoints;
	m_timePerFrame = newTimePerFrame;
}

GraphicMonsters::TilesCharacteristics::TilesCharacteristics(
	Vector2f const& tileSize,
	Vector2f const& oneTexturePoint)
	:TilesCharacteristics(tileSize, std::vector <Vector2f> (1, oneTexturePoint), 0)
{
	// void
}

GraphicMonsters::TilesCharacteristics::~TilesCharacteristics()
{
	m_texturePoints.clear();
}

Vector2f const& GraphicMonsters::TilesCharacteristics::getTileSize()
{
	return m_tileSize;
}

Vector2f const& GraphicMonsters::TilesCharacteristics::getTexturePoints(unsigned int index)
{
	return m_texturePoints[index];
}

double GraphicMonsters::TilesCharacteristics::getTimePerFrame()
{
	return m_timePerFrame;
}

unsigned int GraphicMonsters::TilesCharacteristics::getArraySize()
{
	return m_texturePoints.size();
}
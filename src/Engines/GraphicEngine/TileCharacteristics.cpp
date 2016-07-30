#include "Engines/GraphicEngine/TileCharacteristics.hpp"

GraphicMonsters::TileCharacteristics::TileCharacteristics(
	Vector2f const& newtileSize,
	std::vector <Vector2f> newTexturePoints,
	double newTimePerFrame)
{
	m_tileSize = newtileSize;
	m_texturePoints = newTexturePoints;
	m_timePerFrame = newTimePerFrame;
}

GraphicMonsters::TileCharacteristics::TileCharacteristics(
	Vector2f const& tileSize,
	Vector2f const& oneTexturePoint)
	:TileCharacteristics(tileSize, std::vector <Vector2f> (1, oneTexturePoint), 0)
{
	// void
}

GraphicMonsters::TileCharacteristics::~TileCharacteristics()
{
	m_texturePoints.clear();
}

Vector2f const& GraphicMonsters::TileCharacteristics::getTileSize()
{
	return m_tileSize;
}

Vector2f const& GraphicMonsters::TileCharacteristics::getTexturePoints(unsigned int index)
{
	return m_texturePoints[index];
}

double GraphicMonsters::TileCharacteristics::getTimePerFrame()
{
	return m_timePerFrame;
}

unsigned int GraphicMonsters::TileCharacteristics::getArraySize()
{
	return m_texturePoints.size();
}
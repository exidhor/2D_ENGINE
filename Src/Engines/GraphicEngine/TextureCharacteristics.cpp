#include "Engines/GraphicEngine/TextureCharacteristics.hpp"

//Constructor
GraphicMonsters::TextureCharacteristics::TextureCharacteristics(
		std::vector <GraphicMonsters::TilesCharacteristics*> targetTilesCharacteristics,
		GraphicMonsters::TileSet* targetTileSet)
{
	m_arrayOfTileCharacteristic = targetTilesCharacteristics;
	m_tileSet = targetTileSet;
}

GraphicMonsters::TextureCharacteristics::TextureCharacteristics(
		TilesCharacteristics* tileCharacteristics,
		TileSet* tileSet)

	:TextureCharacteristics(
		std::vector <GraphicMonsters::TilesCharacteristics*> (1, tileCharacteristics),
													tileSet)
{
	// void
}

GraphicMonsters::TextureCharacteristics::TextureCharacteristics(
		TileSet* tileSet,
		float width,
		float height)
{
	m_tileSet = tileSet;
	m_arrayOfTileCharacteristic.push_back(new TilesCharacteristics(Vector2f(width, height),
																	std::vector <Vector2f> (), 0));
}

//Desctructor
GraphicMonsters::TextureCharacteristics::~TextureCharacteristics()
{
	m_arrayOfTileCharacteristic.clear();
}

//Add an TilesCharacteristics at the vector
void GraphicMonsters::TextureCharacteristics::addTilesCharacteristics(GraphicMonsters::TilesCharacteristics* newArray)
{
	m_arrayOfTileCharacteristic.push_back(newArray);
}

//Return the TileSet
GraphicMonsters::TileSet* GraphicMonsters::TextureCharacteristics::getTileSet()  const
{
	return m_tileSet;
}

//Return the TileSize of an ArrayOFTileCharacteristic
Vector2f const& GraphicMonsters::TextureCharacteristics::getTileSize(
	unsigned int indexTileCharac)  const
{
	return m_arrayOfTileCharacteristic[indexTileCharac]->getTileSize();
}

Vector2f const& GraphicMonsters::TextureCharacteristics::getTexturePoints(
	unsigned int indexCulumn,
	unsigned int indexLine)  const
{
	return m_arrayOfTileCharacteristic[indexLine]->getTexturePoints(indexCulumn);
}

//Return the ArraySize of an ArrayOFTileCharacteristic
unsigned int GraphicMonsters::TextureCharacteristics::getLineSizeOf(
	unsigned int indexTileCharac) const
{
	return m_arrayOfTileCharacteristic[indexTileCharac]->getArraySize();
}

unsigned int GraphicMonsters::TextureCharacteristics::getCulumnSize() const
{
	return m_arrayOfTileCharacteristic.size();
}

//Return the TimePerFrame of an ArrayOFTileCharacteristic
double GraphicMonsters::TextureCharacteristics::getTimePerFrame(
	unsigned int indexTileCharac) const
{
	return m_arrayOfTileCharacteristic[indexTileCharac]->getTimePerFrame();
}
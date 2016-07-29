#include "Engines/GraphicEngine/TextureCharacteristics.hpp"

/*
 * \brief   Construct a TextureCharacteristics from a
 *          TilesCharacteristics array.
 * \param   targetTilesCharacteristics : the array of   
 *          TileCharacteristics.
 * \param   targetTileset : 
*/
GraphicMonsters::TextureCharacteristics::TextureCharacteristics(std::vector <GraphicMonsters::TilesCharacteristics*> targetTilesCharacteristics,
		                                                        GraphicMonsters::Tileset* targetTileset)
{
	m_arrayOfTileCharacteristic = targetTilesCharacteristics;
	m_tileset = targetTileset;
}

GraphicMonsters::TextureCharacteristics::TextureCharacteristics(
		TilesCharacteristics* tileCharacteristics,
		Tileset* tileset)

	:TextureCharacteristics(
		std::vector <GraphicMonsters::TilesCharacteristics*> (1, tileCharacteristics),
													tileset)
{
	// void
}

GraphicMonsters::TextureCharacteristics::TextureCharacteristics(
		Tileset* tileset,
		float width,
		float height)
{
	m_tileset = tileset;
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

//Return the Tileset
GraphicMonsters::Tileset* GraphicMonsters::TextureCharacteristics::getTileset()  const
{
	return m_tileset;
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
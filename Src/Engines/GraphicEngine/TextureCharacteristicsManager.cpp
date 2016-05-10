#include "Engines/GraphicEngine/TextureCharacteristicsManager.hpp"

/*!
* \brief Construct a void TextureCharacteristicsManager
*/
GraphicMonsters::TextureCharacteristicsManager::TextureCharacteristicsManager()
{
	//none
}

// Destructor
GraphicMonsters::TextureCharacteristicsManager::~TextureCharacteristicsManager()
{
	//none
}

/*!
* \brief Construct a GraphicMonsters::TilesCharacteristics witch each
* \brief arguments needed
* \brief search in the map if the key entered already exists
* \brief if it exists, add the GraphicMonsters::TilesCharacteristics
* \brief to the GraphicMonsters::TextureCharacteristics corresponding
* \brief if it's not, create a GraphicMonsters::TextureCharacteristics
* \brief with the key, the GraphicMonsters::TilesCharacteristics and
* \brief the GraphicMonsters::TileSet
* \param key the key to get it to the map
* \param all the params to create a GraphicMonsters::TileCharacteristics
* \param tileSetTarget the GraphicMonsters::TileSet associated to the 
			GraphicMonsters::TextureCharacteristics
*/
bool GraphicMonsters::TextureCharacteristicsManager::addTextureCharacteristics(
	std::string key, 
	Vector2f const& tileSize,
	std::vector <Vector2f> texturePoints,
	double timePerFrame,
	GraphicMonsters::TileSet* tileSetTarget)
{
	GraphicMonsters::TilesCharacteristics* tilesCharacteritics = new GraphicMonsters::TilesCharacteristics(
																		tileSize, 
																		texturePoints,
																		timePerFrame);

	m_textureCharacteristicsIndex = m_textureCharacteristics.find(key);

	if (m_textureCharacteristicsIndex != m_textureCharacteristics.end()) {
		m_textureCharacteristicsIndex->second->addTilesCharacteristics(tilesCharacteritics);
		return true;
	}
	else
	{
		m_textureCharacteristics.insert(std::pair <std::string, GraphicMonsters::TextureCharacteristics*>(
			key,
			new GraphicMonsters::TextureCharacteristics(
					std::vector <TilesCharacteristics*>(1, tilesCharacteritics),
					tileSetTarget)));

		return false;
	}
}

bool GraphicMonsters::TextureCharacteristicsManager::addTextureCharacteristics(
	std::string key,
	Vector2f const& tileSize,
	Vector2f oneTexturePoint,
	GraphicMonsters::TileSet* tileSetTarget)
{
	std::vector <Vector2f> texturePoints;
	texturePoints.push_back(oneTexturePoint);
	return addTextureCharacteristics(key, tileSize, texturePoints, -1, tileSetTarget);
}

// Getter
GraphicMonsters::TextureCharacteristics* GraphicMonsters::TextureCharacteristicsManager::getTextureCharacteristics(std::string key)
{
	return m_textureCharacteristics[key];
}
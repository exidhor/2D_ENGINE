#include "Engines/GraphicEngine/TileSetManager.hpp"

//Constructor
GraphicMonsters::TileSetManager::TileSetManager()
{
	//none
}

//Destructor
GraphicMonsters::TileSetManager::~TileSetManager()
{
	for (std::map<std::string, GraphicMonsters::TileSet*>::iterator tileSet = m_tileSetMap.begin();
		tileSet != m_tileSetMap.end(); ++tileSet)
	{
		delete tileSet->second;
		tileSet->second = 0;
	}
	m_tileSetMap.clear();
}

//Add a TileSet with a texture at the m_tileSetMap
bool GraphicMonsters::TileSetManager::addTileSet(std::string const& key, std::string const& path)
{
	//Load the texture
	sf::Texture* tile = new sf::Texture();
	if (!tile->loadFromFile(path)) {
		return false;
	}

	GraphicMonsters::TileSet* tileSet = new GraphicMonsters::TileSet(tile);

	m_tileSetMap.insert(std::pair <std::string, GraphicMonsters::TileSet *>(key, tileSet));
	return true;
}

//Load the vertexArray of a TileSet
void GraphicMonsters::TileSetManager::loadTileSet(std::string const& key, unsigned int maxSizeVertexArray, unsigned int level)
{
	m_tileSetMap[key]->loading(maxSizeVertexArray, level);
}

//Return a TileSet
GraphicMonsters::TileSet * GraphicMonsters::TileSetManager::getTileSet(std::string const& key)
{
	return m_tileSetMap[key];
}

void GraphicMonsters::TileSetManager::assembleContinousArrays()
{
	for (std::map<std::string, GraphicMonsters::TileSet*>::iterator tileSet = m_tileSetMap.begin();
		tileSet != m_tileSetMap.end(); ++tileSet)
	{
		tileSet->second->assembleContinousArray();
	}
}

void GraphicMonsters::TileSetManager::clearAllTileSets()
{
	for (std::map<std::string, GraphicMonsters::TileSet*>::iterator tileSet = m_tileSetMap.begin();
		tileSet != m_tileSetMap.end(); ++tileSet)
	{
		tileSet->second->clearAllLayers();
	}
}
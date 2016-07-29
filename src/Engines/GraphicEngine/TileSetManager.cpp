#include "Engines/GraphicEngine/TilesetManager.hpp"

//Constructor
GraphicMonsters::TilesetManager::TilesetManager()
{
	//none
}

//Destructor
GraphicMonsters::TilesetManager::~TilesetManager()
{
	for (std::map<std::string, GraphicMonsters::Tileset*>::iterator tileset = m_tilesetMap.begin();
		tileset != m_tilesetMap.end(); ++tileset)
	{
		delete tileset->second;
		tileset->second = 0;
	}
	m_tilesetMap.clear();
}

//Add a Tileset with a texture at the m_tilesetMap
bool GraphicMonsters::TilesetManager::addTileset(std::string const& key, std::string const& path)
{
	//Load the texture
	sf::Texture* tile = new sf::Texture();
	if (!tile->loadFromFile(path)) {
		return false;
	}

	GraphicMonsters::Tileset* tileset = new GraphicMonsters::Tileset(tile);

	m_tilesetMap.insert(std::pair <std::string, GraphicMonsters::Tileset *>(key, tileset));
	return true;
}

//Load the vertexArray of a Tileset
void GraphicMonsters::TilesetManager::loadTileset(std::string const& key, unsigned int maxSizeVertexArray, unsigned int level)
{
	m_tilesetMap[key]->loading(maxSizeVertexArray, level);
}

//Return a Tileset
GraphicMonsters::Tileset * GraphicMonsters::TilesetManager::getTileset(std::string const& key)
{
	return m_tilesetMap[key];
}

void GraphicMonsters::TilesetManager::assembleContinousArrays()
{
	for (std::map<std::string, GraphicMonsters::Tileset*>::iterator tileset = m_tilesetMap.begin();
		tileset != m_tilesetMap.end(); ++tileset)
	{
		tileset->second->assembleContinousArray();
	}
}

void GraphicMonsters::TilesetManager::clearAllTilesets()
{
	for (std::map<std::string, GraphicMonsters::Tileset*>::iterator tileset = m_tilesetMap.begin();
		tileset != m_tilesetMap.end(); ++tileset)
	{
		tileset->second->clearAllLayers();
	}
}
#include "Engines/GraphicEngine/TilesetDisplayer.hpp"

GraphicMonsters::TilesetDisplayer::TilesetDisplayer()
{
	// void
}

void GraphicMonsters::TilesetDisplayer::addTileset(GraphicMonsters::Tileset* tileset)
{
	m_tilesetArray.push_back(tileset);
}

/*
 * \brief   [DEPRECATED] now use the other draw method
 */
void GraphicMonsters::TilesetDisplayer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i < m_tilesetArray.size(); i++)
	{
		m_tilesetArray[i]->draw(target, states);
	}
}

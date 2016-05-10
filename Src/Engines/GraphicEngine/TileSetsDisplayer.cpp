#include "Engines/GraphicEngine/TilesetsDisplayer.hpp"

GraphicMonsters::TilesetsDisplayer::TilesetsDisplayer()
{
	// void
}

void GraphicMonsters::TilesetsDisplayer::addTileset(GraphicMonsters::Tileset* tileset)
{
	m_tilesetArray.push_back(tileset);
}

void GraphicMonsters::TilesetsDisplayer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i < m_tilesetArray.size(); i++)
	{
		m_tilesetArray[i]->draw(target, states);
	}
}
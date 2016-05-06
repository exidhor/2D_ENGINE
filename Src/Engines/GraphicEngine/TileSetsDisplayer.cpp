#include "Engines/GraphicEngine/TileSetsDisplayer.hpp"

GraphicMonsters::TileSetsDisplayer::TileSetsDisplayer()
{
	// void
}

void GraphicMonsters::TileSetsDisplayer::addTileSet(GraphicMonsters::TileSet* tileSet)
{
	m_tileSetArray.push_back(tileSet);
}

void GraphicMonsters::TileSetsDisplayer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (unsigned int i = 0; i < m_tileSetArray.size(); i++)
	{
		m_tileSetArray[i]->draw(target, states);
	}
}
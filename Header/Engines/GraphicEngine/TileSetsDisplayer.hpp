#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Engines/GraphicEngine/TileSet.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	It manage all TileSet to be drawn
	*			in the right order.
	*/
	class TileSetsDisplayer : public sf::Drawable
	{
	public:
		TileSetsDisplayer();

		void			addTileSet(TileSet* tileSet);

		virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		std::vector <TileSet*> m_tileSetArray;
	};
}
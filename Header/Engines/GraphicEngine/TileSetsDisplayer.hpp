#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Engines/GraphicEngine/Tileset.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	It manage all Tileset to be drawn
	*			in the right order.
	*/
	class TilesetsDisplayer : public sf::Drawable
	{
	public:
		TilesetsDisplayer();

		void			addTileset(Tileset* tileset);

		virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		std::vector <Tileset*> m_tilesetArray;
	};
}
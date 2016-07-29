#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engines/GraphicEngine/Tileset.hpp"
#include "Engines/Config.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	store GraphicMonsters::Tileset in a map.
	*			Allow to clear and assemble
	*			every Tileset in the map.
	*/
	class GRAPHIC_API TilesetManager
	{
	public:
		TilesetManager();
		~TilesetManager();

		bool		addTileset(
						std::string const& key,
						std::string const& path);

		void		loadTileset(
						std::string const& key,
						unsigned int maxSizeVertexArray,
						unsigned int level);

		void		assembleContinousArrays();

		void		clearAllTilesets();

		Tileset*	getTileset(std::string const& key);

	private:
		std::map <std::string, Tileset*> m_tilesetMap;
	};
}
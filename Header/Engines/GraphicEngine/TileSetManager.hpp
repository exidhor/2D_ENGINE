#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engines/GraphicEngine/TileSet.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	store GraphicMonsters::TileSet in a map.
	*			Allow to clear and assemble
	*			every TileSet in the map.
	*/
	class TileSetManager
	{
	public:
		TileSetManager();
		~TileSetManager();

		bool		addTileSet(
						std::string const& key,
						std::string const& path);

		void		loadTileSet(
						std::string const& key,
						unsigned int maxSizeVertexArray,
						unsigned int level);

		void		assembleContinousArrays();

		void		clearAllTileSets();

		TileSet*	getTileSet(std::string const& key);

	private:
		std::map <std::string, TileSet*> m_tileSetMap;
	};
}
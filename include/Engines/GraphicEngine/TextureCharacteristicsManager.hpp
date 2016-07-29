#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engines/GraphicEngine/TextureCharacteristics.hpp"
#include "Modules/Utilities/Vector2.hpp"
#include "Engines/Config.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	Create and add a TextureCharacteristics in a map.
	*			Allow to retreive them by its keys
	*/
	class GRAPHIC_API TextureCharacteristicsManager
	{
	public:
		TextureCharacteristicsManager();

		~TextureCharacteristicsManager();

		bool addTileCharacteristics(
				std::string key,
				Vector2f const& tileSize,
				std::vector <Vector2f> texturePoints,
				double timePerFrame, 
				Tileset* tilesetTarget);

		bool addTileCharacteristics(
				std::string key, 
				Vector2f const& tileSize,
				Vector2f oneTexturePoint,
				Tileset* tilesetTarget);

		TextureCharacteristics*	getTextureCharacteristics(std::string key);


	private:
		std::map < std::string, TextureCharacteristics*>::iterator	m_textureCharacteristicsIndex;
		std::map <std::string, TextureCharacteristics*>				m_textureCharacteristics;
	};
}
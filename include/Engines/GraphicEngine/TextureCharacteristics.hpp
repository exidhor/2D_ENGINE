#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engines/GraphicEngine/TileCharacteristics.hpp"
#include "Engines/GraphicEngine/Tileset.hpp"
#include "Modules/Utilities/Vector2.hpp"
#include "Engines/Config.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	All the characteristics necessary
	*			to build an Animation.
	*			store an array of TilesCharacteristics
	*			and the Tileset used
	*/
	class GRAPHIC_API TextureCharacteristics
	{
	public:
		TextureCharacteristics(Tileset* tileset, float width, float height);
		TextureCharacteristics(std::vector <TileCharacteristics*> tilesCharacteristics,
								Tileset* tileset);
		TextureCharacteristics(TileCharacteristics* tileCharacteristics,
								Tileset* tileset);


		~TextureCharacteristics();

		void		addTilesCharacteristics(TileCharacteristics* newArray);

		//Getters
		Tileset*	getTileset() const;
		Vector2f	const& getTileSize(unsigned int indexTileCharac)  const;
		Vector2f	const& getTexturePoints(unsigned int indexCulumn, unsigned int indexLine)  const;
		unsigned	int getLineSizeOf(unsigned int indexTileCharac)  const;
		unsigned	int getCulumnSize()  const;
		double		getTimePerFrame(unsigned int indexTileCharac)  const;

	private:
		std::vector <TileCharacteristics*> m_arrayOfTileCharacteristic;
		Tileset*							m_tileset;
	};
}
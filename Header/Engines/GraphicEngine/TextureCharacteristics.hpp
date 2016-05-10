#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engines/GraphicEngine/TilesCharacteristics.hpp"
#include "Engines/GraphicEngine/Tileset.hpp"
#include "Utilities/Vector2.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	All the characteristics necessary
	*			to build an Animation.
	*			store an array of TilesCharacteristics
	*			and the Tileset used
	*/
	class TextureCharacteristics
	{
	public:
		TextureCharacteristics(Tileset* tileset, float width, float height);
		TextureCharacteristics(std::vector <TilesCharacteristics*> tilesCharacteristics,
								Tileset* tileset);
		TextureCharacteristics(TilesCharacteristics* tileCharacteristics,
								Tileset* tileset);


		~TextureCharacteristics();

		void		addTilesCharacteristics(TilesCharacteristics* newArray);

		//Getters
		Tileset*	getTileset() const;
		Vector2f	const& getTileSize(unsigned int indexTileCharac)  const;
		Vector2f	const& getTexturePoints(unsigned int indexCulumn, unsigned int indexLine)  const;
		unsigned	int getLineSizeOf(unsigned int indexTileCharac)  const;
		unsigned	int getCulumnSize()  const;
		double		getTimePerFrame(unsigned int indexTileCharac)  const;

	private:
		std::vector <TilesCharacteristics*> m_arrayOfTileCharacteristic;
		Tileset*							m_tileset;
	};
}
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engines/GraphicEngine/TextureCharacteristics.hpp"
#include "Utilities/Timer.hpp"
#include "Engines/GraphicEngine/Sprite.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	A empty rectangle simbolize by
	*			stripped lines
	*/
	class RectangleShape
	{
	public:


	private:
		
		TextureCharacteristics* m_textureCharacteristics;
		sf::Color				m_color;
	};
}


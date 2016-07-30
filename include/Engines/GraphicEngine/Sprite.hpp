#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engines/GraphicEngine/TextureCharacteristics.hpp"
#include "Engines/GraphicEngine/QuadVertices.hpp"
#include "Engines/GraphicEngine/Drawable.hpp"
#include "Engines/Config.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	A unique texture symbolize by a QuadVertices
	*			It provides transformation like rotation
	*			or translation
	*/
	class GRAPHIC_API Sprite : public Drawable
	{
	public:
		Sprite();
		Sprite(TextureCharacteristics* textureCharacteristics,
			unsigned int layerLevel = 0);
		Sprite(Sprite const& sprite);

		virtual ~Sprite();

		// method to provide a efficient polymorphism
        virtual bool actualize(double deltaTime);


		// methods to provide a powerful polymorphism
		virtual bool isAnimation();
		virtual bool isSprite();
		virtual bool isShape();

		// void method to use animation with polymorphism
		virtual void goToLine(unsigned int indexLine);
		virtual bool goToTheNextLine();
		virtual void setRepeated(bool state);
		virtual void setContinueSequence(bool state);
		virtual void start();
		virtual void stop();
		virtual void restart();
		virtual void softRestart();


	protected:
		TextureCharacteristics*		m_textureCharacteristics;
	};
}
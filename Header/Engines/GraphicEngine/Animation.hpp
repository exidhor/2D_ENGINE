#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engines/GraphicEngine/TextureCharacteristics.hpp"
#include "Utilities/Timer.hpp"
#include "Engines/GraphicEngine/Sprite.hpp"

namespace GraphicMonsters
{
	/*
	* \brief	An animation which is an succession
	*			of images.
	*/
	class Animation : public Sprite
	{
	public:
		Animation(TextureCharacteristics* animationCharacteristic,
					unsigned int layerLevel);
		Animation(Animation const& animation);
		~Animation();

		virtual void addToTileSet();

		// managing of the animation
		virtual bool actualize(double timeSpent);
		virtual void goToLine(unsigned int indexLine);
		virtual bool goToTheNextLine();

		virtual void setRepeated(bool state);
		virtual void setContinueSequence(bool state);

		// state controls
		virtual void start();
		virtual void stop();
		virtual void restart();
		virtual void softRestart();

		// methods to provide a powerfull polymorphism
		virtual bool isAnimation();
		virtual bool isSprite();

	private:
		bool			increaseAnimationIndex();
		void			applyTextureOnVertices();

		Timer			m_timer;
		unsigned int	m_indexCulumn;
		unsigned int	m_indexLine;

		//state
		bool			m_isOn;
		bool			m_repeated;
		bool			m_continueSequence;
	};
}


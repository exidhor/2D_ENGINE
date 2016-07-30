#include "Engines/GraphicEngine/Sprite.hpp"


/*
 * \brief   Construct a Sprite.
 * \param   textureCharacteristics : The model for the sprite construction.
 * \param   layerLevel : the level of display.
*/
GraphicMonsters::Sprite::Sprite(TextureCharacteristics* textureCharacteristics,
					unsigned int layerLevel)
{
	// initialization of the Drawable part
	initTileset(textureCharacteristics->getTileset());
	setLayerLevel(layerLevel);
	QuadVertices* quadVertices = new QuadVertices(sf::FloatRect(textureCharacteristics->getTexturePoints(0, 0).x,
																textureCharacteristics->getTexturePoints(0, 0).y,
																textureCharacteristics->getTileSize(0).x,
																textureCharacteristics->getTileSize(0).y));
	initVertices(quadVertices);
	initOriginCenteredRelative(textureCharacteristics->getTileSize(0).x / 2,
								textureCharacteristics->getTileSize(0).y / 2);

	// initialization of the Sprite part
	m_textureCharacteristics = textureCharacteristics;

}



/*
* \brief   Copy a sprite.
* \param   sprite : the sprite to copy.
*/
GraphicMonsters::Sprite::Sprite(GraphicMonsters::Sprite const& sprite)
	: Drawable(sprite)
{
	m_textureCharacteristics = sprite.m_textureCharacteristics;
}

GraphicMonsters::Sprite::~Sprite()
{
	// void
}

// -------------- animations ---------------------------------


/*
* \brief   Actualize the sprite.
* \param   sprite : the sprite to copy.
*/
bool GraphicMonsters::Sprite::actualize(double deltaTime)
{
	/*
	sf::Transform transform2;

	m_translationManager.actualize(
		timeSpent,
		m_originCenteredRelative,
		transform2
		);

	sf::Transform transform;

	m_rotationManager.actualize(
		timeSpent,
		m_originCenteredRelative,
		transform
		);

		*/
	//m_quadVertices.applyTranformation(transform);

	return false;
}

// ------ methods to provide a powerfull polymorphism ------------

/*!
* \brief give the type of the current object
* \return false because it's not an Animation
*/
bool GraphicMonsters::Sprite::isAnimation()
{
	return false;
}

/*!
* \brief give the type of the current object
* \return true because it's a Sprite
*/
bool GraphicMonsters::Sprite::isSprite()
{
	return true;
}

/*!
* \brief give the type of the current object
* \return false because it's not a Shape
*/
bool GraphicMonsters::Sprite::isShape()
{
	return false;
}

// void method to use animation with polymorphism

void GraphicMonsters::Sprite::goToLine(unsigned int indexLine) {}
bool GraphicMonsters::Sprite::goToTheNextLine() { return false; }
void GraphicMonsters::Sprite::setRepeated(bool state) {}
void GraphicMonsters::Sprite::setContinueSequence(bool state) {}
void GraphicMonsters::Sprite::start() {}
void GraphicMonsters::Sprite::stop() {}
void GraphicMonsters::Sprite::restart() {}
void GraphicMonsters::Sprite::softRestart() {}

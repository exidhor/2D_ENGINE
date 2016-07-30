#include "Engines/GraphicEngine/Drawable.hpp"

/*!
* \brief	Construct a drawable object with
*           NULL value. It needs to be init
*			before use it.
*/
GraphicMonsters::Drawable::Drawable()
{
	m_vertices = NULL;
	m_tileset = NULL;
	
	m_layerLevelOfDisplay = 0;
	m_isHidden = false;
}

/*!
* \brief	Copy a drawable object and
*           the same value for everything
*			except flag hide.
* \param	drawableObject : the model for
*			the copy.
*/
GraphicMonsters::Drawable::Drawable(Drawable const& drawableObject)
{
	m_vertices = new QuadVertices(*drawableObject.m_vertices);

	m_tileset = drawableObject.m_tileset;
	m_layerLevelOfDisplay = drawableObject.m_layerLevelOfDisplay;
	m_originCenteredRelative = drawableObject.m_originCenteredRelative;

	// doesn't copy this value
	m_isHidden = false;
}

/*!
* \brief	Destruct the vertices array.
*/
GraphicMonsters::Drawable::~Drawable()
{
	delete m_vertices;
}

/*!
* \brief	Set the value of the tileset.
*			Keep a reference.
*			tileset : reference to the Tileset.
*/
void GraphicMonsters::Drawable::initTileset(Tileset* tileset)
{
	m_tileset = tileset;
}

/*!
* \brief	Set the value of the vertices array.
*           Keep a reference.
* \param	vertices : reference to the vertices array.
*/
void GraphicMonsters::Drawable::initVertices(TextureVertices* vertices)
{
	m_vertices = vertices;
}

/*!
* \brief	Initialize the origin value.
* \param	abscissa : the abscissa origin.
* \param	ordinate : the ordinate origin.
*/
void GraphicMonsters::Drawable::initOriginCenteredRelative(int abscissa, int ordinate)
{
	m_originCenteredRelative.x = abscissa;
	m_originCenteredRelative.y = ordinate;
}


/*!
* \brief	Add all vertices to the linked GraphicMonsters::Tileset
*           if the object is not hidden.
*/
void GraphicMonsters::Drawable::addToTileset()
{
	if (!m_isHidden)
	{
		m_vertices->addVerticesToTheTileset(m_tileset, m_layerLevelOfDisplay);
	}
}

/*!
* \return	The position of the left top
*			point of the globalBounds.
*/
Vector2f GraphicMonsters::Drawable::getPosition()
{
	return m_vertices->getPosition();
}

/*!
* \return	The size of the globalBounds.
*/
Vector2f GraphicMonsters::Drawable::getGlobalSize()
{
	return Vector2f(m_vertices->getGlobalBounds().width,
					m_vertices->getGlobalBounds().height);
}

/*!
* \brief	Set the position of the object with
*           a translation.
*			Update the origin centered.
* \param	position : the new position
*/
void GraphicMonsters::Drawable::setPosition(Vector2f const position)
{
	// TODO : a deplacer dans le PhysicEngine et enlever
	// la translation

	Vector2f newOrigin(
		position.x + m_vertices->getGlobalBounds().width / 2,
		position.y + m_vertices->getGlobalBounds().height / 2
		);

	Vector2f offset(
		newOrigin.x - m_originCenteredRelative.x,
		newOrigin.y - m_originCenteredRelative.y
		);

	sf::Transform transform;
	this->m_vertices->translate(offset, transform);
	m_vertices->applyTranformation(transform);

	m_originCenteredRelative = newOrigin;
}

/*!
* \brief	Set the position of the object with
*           a translation.
*			Update the origin centered.
* \param	abscissa : the new abscissa
* \param	ordinate : the new ordinate
*/
void GraphicMonsters::Drawable::setPosition(float abscissa, float ordinate)
{
	setPosition(Vector2f(abscissa, ordinate));
}

/*!
* \brief	Set the texture with the coord
*			of the left top point of the 
*			globalBounds sprite.
* \param	coordTexture : the coord of the
*			left top point of the globalBounds sprite.
*/
void GraphicMonsters::Drawable::setTexture(Vector2f const& newCoordTexture)
{
	m_vertices->setTexture(newCoordTexture);
}

/*!
* \brief	Set the color of the object.
* \param	color : the of the object.
*/
void GraphicMonsters::Drawable::setColor(sf::Color const& color)
{
	m_vertices->setColor(color);
}

/*!
* \brief	Move the object with a translation.
*			Update the origin.
* \param	offsetX : the x composant of the 
*			movement vector.
* \param	offsetY	: the y composant of the 
*			movement vector.
*/
void GraphicMonsters::Drawable::move(float offsetX, float offsetY)
{
	Vector2f offset(
		offsetX,
		offsetY
		);

	sf::Transform transform;
	m_vertices->translate(offset, transform);
	m_vertices->applyTranformation(transform);

	m_originCenteredRelative.x += offsetX;
	m_originCenteredRelative.y += offsetY;
}

/*!
* \brief	Set the level of the layer of
*			display.
* \param	layelLevel : the level of the
*			layer of display.
*/
void GraphicMonsters::Drawable::setLayerLevel(unsigned int layerLevel)
{
	m_layerLevelOfDisplay = layerLevel;
}

// -------------- state --------------------------------------

/*!
* \brief	Hide the object.
*			The object is not add
*			to the Tileset anymore.
*/
void GraphicMonsters::Drawable::hide()
{
	m_isHidden = true;
}

/*!
* \brief	Show the object.
*			The object can now be add
*			to the Tileset.
*/
void GraphicMonsters::Drawable::show()
{
	m_isHidden = false;
}
#include "Engines/GraphicEngine/TextureVertices.hpp"

GraphicMonsters::TextureVertices::TextureVertices(int numberOfVertex)
{
	m_size = numberOfVertex;
	//m_globalBoundsUpToDate = false; TODO : REWORK Transformation
}

GraphicMonsters::TextureVertices::TextureVertices(TextureVertices const& textureVertices)
{
	m_size = textureVertices.m_size;

    // TODO : REWORK Transformation
    //if (textureVertices.m_globalBoundsUpToDate)
	//{
	//	m_globalBounds = textureVertices.m_globalBounds;
	//	m_globalBoundsUpToDate = true;
	//}
	//else
	//{
	//	m_globalBoundsUpToDate = false;
	//}
}

GraphicMonsters::TextureVertices::~TextureVertices()
{
	// void
}

/*!
* \brief add m_vertices to the tileset on the layel level target
* \param newTargetTileSet the tileset which will display the m_vertices
* \param layerLevel the layer of display
*/
void GraphicMonsters::TextureVertices::addVerticesToTheTileset(Tileset* targetTileset, 
													unsigned int layerLevel)
{
	targetTileset->addVertices(getVerticesArray(), m_size, layerLevel);
}

/*!
* \return the position of the left-top vertex of the global bounds
*/
Vector2f GraphicMonsters::TextureVertices::getPosition()
{
    // TODO : REWORK Transformation
	//checkUpdateGlobalBounds();
	//return Vector2f(m_globalBounds.left, m_globalBounds.top);

    return Vector2f(); // TO_REMOVE : Just to be able to compile
}

/*!
* \return the global bounds
*/
/* TODO : REWORK Transformation
sf::FloatRect const& GraphicMonsters::TextureVertices::getGlobalBounds()
{
	checkUpdateGlobalBounds();

	return m_globalBounds;
}
 */

/*!
* \brief set the position of the left-top vertex of the global bounds
* \param the new position
*/
void GraphicMonsters::TextureVertices::setPosition(Vector2f const& newPosition)
{
    // TODO : REWORK Transformation
	//sf::Vector2f offset(
	//	newPosition.x - m_globalBounds.left,
	//	newPosition.y - m_globalBounds.top
	//	);

	//sf::Transform transformation;
	//transformation.translate(offset);
	//applyTranformation(transformation);
}

/* TODO : REWORK Transformation
void GraphicMonsters::TextureVertices::setSizeGlobalBounds(float width, float height)
{
	m_globalBounds.width = width;
	m_globalBounds.height = height;
} */

void GraphicMonsters::TextureVertices::setColor(sf::Color const& color)
{
	sf::Vertex* vertices = getVerticesArray();

	for (unsigned int i = 0; i < m_size; i++)
	{
		vertices[i].color = color;
	}
}

/*!
* \brief calculate a translation on the sf::Tranform transformation
* \param offset the offset of the translation
* \param transformation the actual parameters of the final transformation
*			where the translation will be apply
*/
/* TODO : REWORK Transformation
void GraphicMonsters::TextureVertices::translate(Vector2f const& offset, sf::Transform & transformation)
{
	transformation.translate(offset.x, offset.y);
}
*/

/*!
* \brief calculate a rotation on the sf::Tranform transformation
* \param angleOfRotation in degree
* \param origin the origin of the rotation
* \param transformation the actual parameters of the final transformation
*			where the rotation will be apply
*/
/* TODO : REWORK Transformation
void GraphicMonsters::TextureVertices::rotate(float angleOfRotation, Vector2f const& origin,
	sf::Transform & transformation)
{
	transformation.rotate(
		angleOfRotation,
		origin.x,
		origin.y
		);
}
 */

/*!
* \brief apply the transformation on the m_vertices by calculating their
* \brief new position, and set the flag for the computing of the GlobalBounds
* \param transformation all parameters for the transformation calculated
*			before
*/
/* TODO : REWORK Transformation
void GraphicMonsters::TextureVertices::applyTranformation(sf::Transform const& transformation)
{
	sf::Vertex* vertices = getVerticesArray();

	for (unsigned int i = 0; i < m_size; i++)
	{
		vertices[i].position = transformation.transformPoint(vertices[i].position);
	}

	m_globalBoundsUpToDate = false;
}
 */

void GraphicMonsters::TextureVertices::setSizeArray(unsigned int newSize)
{
	m_size = newSize;
}

/* TODO : REWORK Transformation
void GraphicMonsters::TextureVertices::checkUpdateGlobalBounds()
{
	if (!m_globalBoundsUpToDate)
	{
		computeGlobalBounds();
	}
}*/

/* TODO : REWORK Transformation
void GraphicMonsters::TextureVertices::globalBoundsIsComputed()
{
	m_globalBoundsUpToDate = true;
}
 */

/* TODO : REWORK Shape
bool GraphicMonsters::TextureVertices::isQuadVertices()
{
	return false;
}
 */

/* TODO : REWORK Shape
bool GraphicMonsters::TextureVertices::isEmptyBoxVertices()
{
	return false;
}
 */
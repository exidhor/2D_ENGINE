#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Engines/GraphicEngine/Tileset.hpp"
#include "Modules/Utilities/Vector2.hpp"
#include "Engines/Config.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	Vertices array which represents a shape.
	*			get globalBounds and can be transformed
	*/
	class GRAPHIC_API TextureVertices
	{
	public :
		TextureVertices(int numberOfVertex = 0);
		TextureVertices(TextureVertices const& textureVertices);
		virtual ~TextureVertices();

		void			addVerticesToTheTileset(Tileset* targetTileset, unsigned int layerLevel);

		Vector2f		getPosition(); // Not Working Yet TODO : REWORK Transformation
		//sf::FloatRect	const& getGlobalBounds();  -- TODO : REWORK Transformation

		virtual void	setTexture(Vector2f const& newCoordTexture) = 0;
		void			setPosition(Vector2f const& newPosition);
		void			setColor(sf::Color const& color);

		//void			translate(Vector2f const& offset, sf::Transform & transformation);  -- TODO : REWORK Transformation
		//void			rotate(float angleOfRotation, Vector2f const& originOfTheRotation,  -- TODO : REWORK Transformation
		//					sf::Transform & transformation);  -- TODO : REWORK Transformation
		//void			applyTranformation(sf::Transform const& transformation);  -- TODO : REWORK Transformation

		// used to well copy vertices
		//virtual bool	isQuadVertices();  -- TODO : REWORK Shape
		//virtual bool	isEmptyBoxVertices();  -- TODO : REWORK Shape
		virtual const	sf::Vertex* getConstVerticesArray() const = 0;

	protected :
		virtual sf::Vertex* getVerticesArray() = 0;
		//virtual void computeGlobalBounds() = 0;  -- TODO : REWORK Transformation

		//void setSizeGlobalBounds(float width, float height);  -- TODO : REWORK Transformation
		//void globalBoundsIsComputed();  -- TODO : REWORK Transformation
		void setSizeArray(unsigned int newSize);
		
	private :
		//void checkUpdateGlobalBounds();  -- TODO : REWORK Transformation

		unsigned int	m_size;
		//sf::FloatRect	m_globalBounds;  -- TODO : REWORK Transformation
		//bool			m_globalBoundsUpToDate;  -- TODO : REWORK Transformation
	};
}
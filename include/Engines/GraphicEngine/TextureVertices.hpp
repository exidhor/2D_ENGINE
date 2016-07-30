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

		Vector2f		getPosition();
		sf::FloatRect	const& getGlobalBounds();

		virtual void	setTexture(Vector2f const& newCoordTexture) = 0;
		void			setPosition(Vector2f const& newPosition);
		void			setColor(sf::Color const& color);

		void			translate(Vector2f const& offset, sf::Transform & transformation);
		void			rotate(float angleOfRotation, Vector2f const& originOfTheRotation,
							sf::Transform & transformation);
		void			applyTranformation(sf::Transform const& transformation);

		// used to well copy vertices
		virtual bool	isQuadVertices();
		virtual bool	isEmptyBoxVertices();
		virtual const	sf::Vertex* getConstVerticesArray() const = 0;

	protected :
		virtual sf::Vertex* getVerticesArray() = 0;
		virtual void computeGlobalBounds() = 0;

		void setSizeGlobalBounds(float width, float height);
		void globalBoundsIsComputed();
		void setSizeArray(unsigned int newSize);
		
	private :
		void checkUpdateGlobalBounds();

		unsigned int	m_size;
		sf::FloatRect	m_globalBounds;
		bool			m_globalBoundsUpToDate;
	};
}
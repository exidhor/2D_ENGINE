#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engines/GraphicEngine/Tileset.hpp"
#include "Modules/Utilities/Vector2.hpp"
#include "Engines/GraphicEngine/TextureVertices.hpp"
#include "Engines/Config.hpp"

namespace GraphicMonsters
{
	/*
	* \brief	4 vertices which describes a textured sprite.
	*			This group is a rectangle
	*/
	class GRAPHIC_API QuadVertices : public TextureVertices
	{
	public:
		QuadVertices(sf::FloatRect const& textureBounds);
		QuadVertices(TextureVertices const& textureVertices);
		QuadVertices(QuadVertices const& quadVertices);
		~QuadVertices();

		virtual void setTexture(Vector2f const& newCoordTexture);

		virtual bool isQuadVertices();

		virtual const sf::Vertex* getConstVerticesArray() const;

	private:
		virtual sf::Vertex* getVerticesArray();
		//virtual void computeGlobalBounds();  -- TODO : REWORK Transformation

		sf::Vertex		m_vertices[4];
	};
}
#pragma once
#include <SFML/Graphics.hpp>
#include "Modules/Utilities/Vector2.hpp"
#include "Engines/GraphicEngine/Tileset.hpp"
#include "Engines/GraphicEngine/TextureVertices.hpp"
#include "Engines/GraphicEngine/QuadVertices.hpp"
//#include "Engines/GraphicEngine/EmptyBoxVertices.hpp" -- TODO : REWORK Shape
#include "Engines/Config.hpp"

namespace GraphicMonsters
{
	/*
	* \brief	An object with a shape and
	*			a texture/color which can
	*			be drawn
	*/
	class GRAPHIC_API Drawable
	{
	public:
		Drawable();
		Drawable(Drawable const& drawableObject);
		virtual ~Drawable();

		void initTileset(Tileset* tileset);
		void initVertices(TextureVertices* vertices);

		virtual void addToTileset();

		Vector2f getPosition();
		//Vector2f getGlobalSize(); // TODO : REWORK Transformation

		void setPosition(Vector2f const position); // Not Working Yet TODO : REWORK Transformation
		void setPosition(float abscissa, float ordinate); // Not Working Yet TODO : REWORK Transformation
		void move(float offsetX, float offsetY); // Not Working Yet TODO : REWORK Transformation
		void setLayerLevel(unsigned int layerLevel);

		void hide();
		void show();

	protected:
		//void initOriginCenteredRelative(int abscissa, int ordinate);  -- TODO : REWORK Transformation

		void setTexture(Vector2f const& newCoordTexture);
		void setColor(sf::Color const& color);

	private:
		TextureVertices*	m_vertices;
		Tileset*			m_tileset;
		//Vector2f			m_originCenteredRelative;  -- TODO : REWORK Transfor
		unsigned int		m_layerLevelOfDisplay;
		bool				m_isHidden;
	};
}

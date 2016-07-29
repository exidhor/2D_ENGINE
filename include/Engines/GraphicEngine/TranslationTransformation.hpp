#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Engines/GraphicEngine/Transformation.hpp"
#include "Modules/Utilities/Timer.hpp"
#include "Engines/Config.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	[DEPRECATED] manage translations
	*			during time
	*/
	class GRAPHIC_API TranslationTransformation : public Transformation
	{
	public:
		TranslationTransformation();

		void initAttribute(QuadVertices* quadVertices);
		void initByTargetPoint(
			double timeUntilTheEnd,
			Vector2f const& origin,
			Vector2f const& targetPoint);
		void initBySpeed(double timeUntilTheEnd,
			Vector2f const& speedPerSecond);

		bool actualize(double timeSpent,
			Vector2f & origin,
			sf::Transform & transformation);

	private:
		Timer		m_timer;
		Vector2f	m_targetPoint;
		float		m_speedAbscissa;
		float		m_speedOrdinate;
		bool		m_isDeterminedByTime;
	};
}
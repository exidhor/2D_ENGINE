#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Engines/GraphicEngine/QuadVertices.hpp"
#include "Engines/Config.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	[DEPRECATED] Abstract class to
	*			an eventual future polymorphism
	*/

	/*  -- TODO : REWORK Transformation
	class GRAPHIC_API Transformation
	{
	public:
		Transformation();
		virtual ~Transformation();

		void			initAttribute(QuadVertices* quadVertices);

		virtual void	start();
		void			stop();

		void			setIsInfinite(bool state);

	protected:
		bool			m_isOn;
		bool			m_isInfinite;
		QuadVertices*	m_quadVertices;
	};
	 */
}
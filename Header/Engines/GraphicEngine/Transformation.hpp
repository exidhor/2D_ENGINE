#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System/Time.hpp>
#include "Engines/GraphicEngine/QuadVertices.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	[DEPRECATED] Abstract class to
	*			an eventual future polymorphism
	*/
	class Transformation
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
}
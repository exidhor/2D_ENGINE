#pragma once
#include <thread>
#include <chrono>
#include "Engines/GraphicEngine.hpp"
#include "Engines/PhysicEngine.hpp"

/*
 * \brief	The Core of the engine. It manage the graphic
 *			engine, the physic engine and a bit of IA.
 */
class GameEngine
{
public :
	GameEngine();
	~GameEngine();

	bool construct();

	void startGraphicEngine(float framePerSecond);

private :
	GraphicMonsters::Engine	m_graphicEngine;
	PhysicEngine		m_physicEngine;

	std::thread*		m_threadGraphic;
};
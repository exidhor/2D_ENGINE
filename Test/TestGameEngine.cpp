#include <thread>
#include <chrono>
#include <vld.h>
#include "Engines/GameEngine.hpp"

int main()
{
	GameEngine gameEngine;

	gameEngine.construct();

	gameEngine.startGraphicEngine(100);

	// freeze !!!!!!!!
	std::this_thread::sleep_for(std::chrono::minutes(1));

	return 0;
}

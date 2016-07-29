#include "Engines/GameEngine/GameEngine.hpp"

/*
 * \brief	Allocate the gameEngine.
*/
GameEngine::GameEngine()
{
	m_threadGraphic = NULL;
}

GameEngine::~GameEngine()
{
	if (m_threadGraphic != NULL)
	{
		delete m_threadGraphic;
	}
}

/*
* \brief	Construct the gameEngine and the
*			graphicEngine.	
*/
bool GameEngine::construct() // tmp for Test
{
	
	m_graphicEngine.init(); // dynamic allocations

	int numberOfElements = 1000;

	// TODO : 
			// temporary : to remplace by a ressource loader

	// creation du Tileset et initialisation
	m_graphicEngine.addTileset("Test", "res/tileTest.png", numberOfElements, 1);

	std::string nomCleAnimation("vieuxJaune");
	Vector2f tailleTuile(32, 48);

	// preparation necessaire pour la creation des sprites/animations
	// creation des caracteristiques des textures
	for (unsigned int indiceLigne = 0; indiceLigne < 4; indiceLigne++)
	{
		//creation des points pour les textures/animations
		std::vector <Vector2f> texturePoints;

		for (unsigned int indiceColonne = 0; indiceColonne < 3; indiceColonne++)
		{
			texturePoints.push_back(Vector2f(indiceColonne*tailleTuile.x, indiceLigne*tailleTuile.y));
		}

		// ajout dans le moteur des caracteristiques
		m_graphicEngine.addTileCharacteristics(
			nomCleAnimation,
			"Test",
			tailleTuile,
			texturePoints,
			0.25);
	}

	// creation d'une animation a partir des caracteristiques "vieuxJaune" au niveau 0
	m_graphicEngine.addAnimation(nomCleAnimation, 0, 1);

	// lancement de l'animation en mode infini
	std::vector <GraphicMonsters::Sprite*> animations;
	for (int i = 0; i < numberOfElements; i++)
	{
		animations.push_back(m_graphicEngine.getFreeSprite(nomCleAnimation));
		animations[i]->setRepeated(true);
		animations[i]->setContinueSequence(true);
		animations[i]->setPosition((i % 100) * 3, (i / 100) * 3);
		animations[i]->start();
	}

	return true;
}

/*
* \brief	Start the graphic engine in a new thread.
*/
void GameEngine::startGraphicEngine(float framePerSecond)
{
	m_graphicEngine.openWindow("Test GraphicMonsters Engine");
	m_threadGraphic = new std::thread(&GraphicMonsters::Engine::run, &m_graphicEngine, framePerSecond);
	m_threadGraphic->detach();
}
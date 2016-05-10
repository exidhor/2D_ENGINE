#include "Engines/GraphicEngine/Engine.hpp"

/*
 * \brief TODO
 */
GraphicMonsters::Engine::Engine()
{
	m_tileSetManager = NULL;
	m_textureCharactertisticsManager = NULL;
	m_ressourceManager = NULL;
	m_tileSetDisplayer = NULL;
	m_window = NULL;
	m_frameTime = 0;
	m_mergeFrameTime = 0;
	m_windowIsOpen = false;
}

/*
* \brief TODO
*/
GraphicMonsters::Engine::~Engine()
{
	if (m_tileSetDisplayer != NULL)
	{
		delete m_tileSetDisplayer;
	}

	if (m_ressourceManager != NULL)
	{
		delete m_ressourceManager;
	}

	if (m_textureCharactertisticsManager != NULL)
	{
		delete m_textureCharactertisticsManager;
	}

	if (m_tileSetManager != NULL)
	{
		delete m_tileSetManager;
	}

	if (m_window != NULL)
	{
		delete m_window;
	}
}

// ----------- initialization ------------------------------------------------------

/*
* \brief TODO
*/
void GraphicMonsters::Engine::init()
{
	m_tileSetManager = new GraphicMonsters::TileSetManager();
	m_textureCharactertisticsManager = new GraphicMonsters::TextureCharacteristicsManager();
	m_ressourceManager = new GraphicMonsters::RessourceManager();
	m_tileSetDisplayer = new GraphicMonsters::TileSetsDisplayer();
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::openWindow(std::string const& title)
{
	m_window = new sf::RenderWindow(sf::VideoMode(1000, 600), title);
	m_windowIsOpen = true;
	m_window->setActive(false);
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::closeWindow()
{
	m_windowIsOpen = false;
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::setFrameRate(float framePerSecond)
{
	m_frameTime = 1. / framePerSecond;
	m_mergeFrameTime = m_frameTime * (0.7 / 60);
}

// ----------------- use ----------------------------------------------------------

/*
* \brief TODO
*/
void GraphicMonsters::Engine::run(int framePerSecond)
{
	setFrameRate(framePerSecond);

	sf::Clock clock;
	double timeSpent = 0;
	double offsetTime = 0;

	while (m_windowIsOpen)
	{
		timeSpent = clock.getElapsedTime().asSeconds();
		offsetTime = m_frameTime - (timeSpent + m_mergeFrameTime);

		if (offsetTime < 0)
		{
			update(timeSpent);

			m_window->clear();
			m_window->draw(*this);
			m_window->display();
			clock.restart();
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::microseconds((long)offsetTime * 1000000));
		}
	}
}

// --------------- creation -------------------------------------------------------

/*
* \brief TODO
*/
void GraphicMonsters::Engine::addTileSet(std::string const& key, std::string const& path)
{
	if (!m_tileSetManager->addTileSet(key, path))
	{
		std::cerr << "ERROR during the loading of the texture\n"
			<< "\tkey :\t" << key
			<< "\tpath :\t" << path << std::endl;
	}
	else
	{
		//m_ressourceManager->createKey(key); duplicate keys with the createkey from the addTextureCharacteristics(...) method
		m_tileSetDisplayer->addTileSet(m_tileSetManager->getTileSet(key));
	}
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::initTileSetLayers(std::string const& key,
	unsigned int maxSizeArray,
	unsigned int numberOfLayer)
{
	m_tileSetManager->loadTileSet(key, maxSizeArray, numberOfLayer);
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::addTileSet(std::string const& key, 
	std::string const& path,
	unsigned int maxSizeArray,
	unsigned int numberOfLayer)
{
	addTileSet(key, path);
	initTileSetLayers(key, maxSizeArray, numberOfLayer);
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::addTextureCharacteristics(
	std::string const& spriteKey,
	std::string const& tileSetKey,
	Vector2f const& tileSize,
	std::vector <Vector2f> texturePoints,
	double timePerFrame)
{
	if (!m_textureCharactertisticsManager->addTextureCharacteristics(
												spriteKey,
												tileSize,
												texturePoints,
												timePerFrame,
												m_tileSetManager->getTileSet(tileSetKey)
												))
	{
		if (m_ressourceManager->createKey(spriteKey))
		{
			std::cerr << "ERROR : duplicating keys in m_ressourceManager\n"
				<< "\tkey :\t" << spriteKey << std::endl;
		}
	}
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::addTextureCharacteristics(
	std::string const& spriteKey,
	std::string const& tileSetKey,
	Vector2f const& tileSize,
	Vector2f const& oneTexturePoint)
{
	if (!m_textureCharactertisticsManager->addTextureCharacteristics(
											spriteKey,
											tileSize,
											oneTexturePoint,
											m_tileSetManager->getTileSet(tileSetKey)
											))
	{
		if (m_ressourceManager->createKey(spriteKey))
		{
			std::cerr << "ERROR : duplicating keys in m_ressourceManager\n"
				<< "\tkey :\t" << spriteKey << std::endl;
		}
	}
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::addSprite(std::string const& key,
	unsigned int layerLevel,
	unsigned int numberOfElements)
{
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		m_ressourceManager->createSprite(
			key,
			m_textureCharactertisticsManager->getTextureCharacteristics(key),
			layerLevel
			);
	}
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::addAnimation(std::string const& key,
	unsigned int layerLevel,
	unsigned int numberOfElements)
{
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		m_ressourceManager->createAnimation(
			key,
			m_textureCharactertisticsManager->getTextureCharacteristics(key),
			layerLevel
			);
	}
}

/*
* \brief TODO
*/
GraphicMonsters::Sprite* GraphicMonsters::Engine::getFreeSprite(std::string const& key)
{
	return m_ressourceManager->getFreeSprite(key);
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::freeSpecificSprite(std::string const& key, unsigned int id)
{
	if (!m_ressourceManager->freeSpecificSprite(key, id))
	{
		std::cerr << "ERROR during the freeing of the sprite\n"
			<< "\tkey :\t" << key
			<< "\tid :\t" << id << std::endl;
	}
}

// -------------- animation gestion during the game ---------------------------------

/*
* \brief TODO
*/
void GraphicMonsters::Engine::update(double time)
{
	m_tileSetManager->clearAllTileSets();
	m_ressourceManager->updateAnimations(time);
	m_tileSetManager->assembleContinousArrays();
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_tileSetDisplayer->draw(target, states);
}

/*
* \brief TODO
*/
GraphicMonsters::RessourceManager * GraphicMonsters::Engine::getResourceManager() {
	return m_ressourceManager;
}
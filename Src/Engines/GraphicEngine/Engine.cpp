#include "Engines/GraphicEngine/Engine.hpp"

/*
 * \brief	Allocate the minimum structure of the Graphic Engine
 *			and init the attributes to NULL.
 */
GraphicMonsters::Engine::Engine()
{
	m_tilesetManager = NULL;
	m_textureCharactertisticsManager = NULL;
	m_ressourceManager = NULL;
	m_tilesetDisplayer = NULL;
	m_window = NULL;
	m_frameTime = 0;
	m_mergeFrameTime = 0;
	m_windowIsOpen = false;
}

/*
* \brief free the used memory.
*/
GraphicMonsters::Engine::~Engine()
{
	if (m_tilesetDisplayer != NULL)
	{
		delete m_tilesetDisplayer;
	}

	if (m_ressourceManager != NULL)
	{
		delete m_ressourceManager;
	}

	if (m_textureCharactertisticsManager != NULL)
	{
		delete m_textureCharactertisticsManager;
	}

	if (m_tilesetManager != NULL)
	{
		delete m_tilesetManager;
	}

	if (m_window != NULL)
	{
		delete m_window;
	}
}

// ----------- initialization ------------------------------------------------------

/*
* \brief	Allocate the attributes.
*/
void GraphicMonsters::Engine::init()
{
	m_tilesetManager = new GraphicMonsters::TilesetManager();
	m_textureCharactertisticsManager = new GraphicMonsters::TextureCharacteristicsManager();
	m_ressourceManager = new GraphicMonsters::RessourceManager();
	m_tilesetDisplayer = new GraphicMonsters::TilesetsDisplayer();
}

/*
* \brief	Create the window and show it.
* \param	title : The title of the window.
*/
void GraphicMonsters::Engine::openWindow(std::string const& title)
{
	m_window = new sf::RenderWindow(sf::VideoMode(1000, 600), title);
	m_windowIsOpen = true;
	m_window->setActive(false); // we have to set active to false to be able to run this in an detached thread.
}

/*
* \brief	Hide the window.
*/
void GraphicMonsters::Engine::closeWindow()
{
	m_windowIsOpen = false;
}

/*
* \brief	Set the maximum frameRate.
* \param	framePeSecond : the maximum frame rate
*/
void GraphicMonsters::Engine::setFrameRate(float framePerSecond)
{
	m_frameTime = 1. / framePerSecond;
	m_mergeFrameTime = m_frameTime * (0.7 / 60);
}

// ----------------- use ----------------------------------------------------------

/*
* \brief	Start the engine (it needs to be initialized before).
*			framePerSecond : the maximum frame rate
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
* \brief	Create and store a tileset in the tilesetManager.
* \param	key : the key of the new tileset 
*/
void GraphicMonsters::Engine::addTileset(std::string const& key, std::string const& path)
{
	if (!m_tilesetManager->addTileset(key, path))
	{
		std::cerr << "ERROR during the loading of the texture\n"
			<< "\tkey :\t" << key
			<< "\tpath :\t" << path << std::endl;
	}
	else
	{
		//m_ressourceManager->createKey(key); duplicate keys with the createkey from the addTileCharacteristics(...) method
		m_tilesetDisplayer->addTileset(m_tilesetManager->getTileset(key));
	}
}

/*
* \brief	Load the tileset in the tileset manager.
* \param	key : the key of the tileset we want to load.
* \param	maxSizeArray : the size of elements we want to allocate per layer
* \param	numberOfLayer : the number of layer we want.
*/
void GraphicMonsters::Engine::initTilesetLayers(std::string const& key,
												unsigned int maxSizeArray,
												unsigned int numberOfLayer)
{
	m_tilesetManager->loadTileset(key, maxSizeArray, numberOfLayer);
}

/*
* \brief	Add a tileset to the tileset manager and init it.
* \param	key : the key of the tileset we want to add.
* \param	path : the path of the texture.
* \param	maxSizeArray : the size of elements we want to allocate per layer.
* \param	numberOfLayer : the number of layer we want.
*/
void GraphicMonsters::Engine::addTileset(std::string const& key, 
										 std::string const& path,
										 unsigned int maxSizeArray,
										 unsigned int numberOfLayer)
{
	addTileset(key, path);
	initTilesetLayers(key, maxSizeArray, numberOfLayer);
}

/*
* \brief	Add a texturechara
*/
void GraphicMonsters::Engine::addTileCharacteristics(std::string const& spriteKey,
														std::string const& tilesetKey,
														Vector2f const& tileSize,
														std::vector <Vector2f> texturePoints,
														double timePerFrame)
{
	if (!m_textureCharactertisticsManager->addTileCharacteristics(spriteKey,
																	 tileSize,
																	 texturePoints,
																	 timePerFrame,
																	 m_tilesetManager->getTileset(tilesetKey)))
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
void GraphicMonsters::Engine::addTileCharacteristics(
	std::string const& spriteKey,
	std::string const& tilesetKey,
	Vector2f const& tileSize,
	Vector2f const& oneTexturePoint)
{
	if (!m_textureCharactertisticsManager->addTileCharacteristics(
											spriteKey,
											tileSize,
											oneTexturePoint,
											m_tilesetManager->getTileset(tilesetKey)
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
	m_tilesetManager->clearAllTilesets();
	m_ressourceManager->updateAnimations(time);
	m_tilesetManager->assembleContinousArrays();
}

/*
* \brief TODO
*/
void GraphicMonsters::Engine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_tilesetDisplayer->draw(target, states);
}

/*
* \brief TODO
*/
GraphicMonsters::RessourceManager * GraphicMonsters::Engine::getResourceManager() {
	return m_ressourceManager;
}
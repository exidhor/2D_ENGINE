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
	m_tilesetDisplayer = new GraphicMonsters::TilesetDisplayer();
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
* \param	tilesetKey : the key of the new tileset 
*/
void GraphicMonsters::Engine::addTileset(std::string const& tilesetKey, 
										 std::string const& path)
{
	if (!m_tilesetManager->addTileset(tilesetKey, path))
	{
		std::cerr << "ERROR during the loading of the texture\n"
			<< "\tkey :\t" << tilesetKey
			<< "\tpath :\t" << path << std::endl;
	}
	else
	{
		//m_ressourceManager->createKey(tilesetKey); duplicate keys with the createkey from the addTileCharacteristics(...) method
		m_tilesetDisplayer->addTileset(m_tilesetManager->getTileset(tilesetKey));
	}
}

/*
* \brief	Load the tileset in the tileset manager.
* \param	tilesetKey : the key of the tileset we want to load.
* \param	maxSizeArray : the size of elements we want to allocate per layer
* \param	numberOfLayer : the number of layer we want.
*/
void GraphicMonsters::Engine::initTilesetLayers(std::string const& tilesetKey,
												unsigned int maxSizeArray,
												unsigned int numberOfLayer)
{
	m_tilesetManager->loadTileset(tilesetKey, maxSizeArray, numberOfLayer);
}

/*
* \brief	Add a tileset to the tileset manager and init it.
* \param	tilesetKey : the key of the tileset we want to add.
* \param	path : the path of the texture.
* \param	maxSizeArray : the size of elements we want to allocate per layer.
* \param	numberOfLayer : the number of layer we want.
*/
void GraphicMonsters::Engine::addTileset(std::string const& tilesetKey, 
										 std::string const& path,
										 unsigned int maxSizeArray,
										 unsigned int numberOfLayer)
{
	addTileset(tilesetKey, path);
	initTilesetLayers(tilesetKey, maxSizeArray, numberOfLayer);
}

/*
* \brief	Add a tileCharacteristics to a textureCharacteristics.
*			If the spriteKey is associate with any textureCharacteristics,
*			it creates a new one.
* \param	spriteKey : the key of the textureCharacteristics.
* \param	tilesetKey : the key of an existing tileset.
* \param	tileSize : the size of the sprite.
* \param	texturePoints : the left-top corner of the tiles.
* \param	timePerframe : the time between each texture.
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
* \brief	Add a tileCharacteristics with a unique tile (not animated)
			to a textureCharacteristics.
*			If the spriteKey is associate with any textureCharacteristics,
*			it creates a new one.
* \param	spriteKey : the key of the textureCharacteristics.
* \param	tilesetKey : the key of an existing tileset.
* \param	tileSize : the size of the sprite.
* \param	oneTexturePoint : the left-top corner of the tile.
*/
void GraphicMonsters::Engine::addTileCharacteristics(std::string const& spriteKey,
													 std::string const& tilesetKey,
													 Vector2f const& tileSize,
													 Vector2f const& oneTexturePoint)
{
	if (!m_textureCharactertisticsManager->addTileCharacteristics(spriteKey,
																  tileSize,
																  oneTexturePoint,
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
* \brief	Add a Sprite array (i.e. not animated) to the RessourceManager.
*			This prepare n sprites by allocate and configure them.
* \param	spriteKey : the key of the sprite, it needs to match with an 
*			existing TextureCharacteristics.
* \param	layerLevel : the level of display.
* \param	numberOfElements : the number of elements we want to prepare.
*			(this param can be used to avoid dynamic memory allocation)
*/
void GraphicMonsters::Engine::addSprite(std::string const& spriteKey,
										unsigned int layerLevel,
										unsigned int numberOfElements)
{
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		m_ressourceManager->createSprite(spriteKey,
                                         m_textureCharactertisticsManager->getTextureCharacteristics(spriteKey),
										 layerLevel);
	}
}

/*
* \brief	Add an Animation array to the RessourceManager.
*			This prepare n animations by allocate and configure them.
* \param	spriteKey : the key of the animation, it needs to match with an
*			existing TextureCharacteristics.
* \param	layerLevel : the level of display.
* \param	numberOfElements : the number of elements we want to prepare.
*			(this param can be used to avoid dynamic memory allocation)
*/
void GraphicMonsters::Engine::addAnimation(std::string const& spriteKey,
										   unsigned int layerLevel,
										   unsigned int numberOfElements)
{
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
		m_ressourceManager->createAnimation(spriteKey,
		                                    m_textureCharactertisticsManager->getTextureCharacteristics(spriteKey),
			                                layerLevel);
	}
}

/*
* \brief    Get an inactive instance of a Sprite/Animation. If no one
            is free, it resize the array and creates new instances.
* \param    spriteKey : the key of the Sprite/Animation.
*/
GraphicMonsters::Sprite* GraphicMonsters::Engine::getFreeSprite(std::string const& spriteKey)
{
	return m_ressourceManager->getFreeSprite(spriteKey);
}

/*
 * \brief   Free a specific Sprite/Animation by setting isActive to false.
 *          (it means that the memory is not really released and the object
 *          can be used again).
 * \param   spriteKey : the key of the Sprite/Animation
 * \param   id : the index of the instance which will be released in the array.
*/
void GraphicMonsters::Engine::releaseSpecificSprite(std::string const& spriteKey, 
                                                 unsigned int id)
{
	if (!m_ressourceManager->releaseSpecificSprite(spriteKey, id))
	{
		std::cerr << "ERROR during the freeing of the sprite\n"
			<< "\tkey :\t" << spriteKey
			<< "\tid :\t" << id << std::endl;
	}
}

// -------------- animation gestion during the game ---------------------------------

/*
* \brief    Update animations and transformation with the delaTime.
* \param    deltaTime : the time since the last update.           
*/
void GraphicMonsters::Engine::update(double delaTime)
{
	m_tilesetManager->clearAllTilesets();
    m_ressourceManager->updateAnimations(delaTime);
	m_tilesetManager->assembleContinousArrays();
}

/*
 * \brief   [INHERITED] Display all the elements. Calls a SFML draw for each Tileset. 
 *          I bet this is a little bit more efficient than call a traditional draw method.
 * \param   target : the sfml parameter to draw
 * \param   state : the sfml parameter to draw
*/
void GraphicMonsters::Engine::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	m_tilesetDisplayer->draw(target, states);
}
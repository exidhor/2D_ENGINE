#include "Engines/GraphicEngine/RessourceManager.hpp"

GraphicMonsters::RessourceManager::RessourceManager()
{
	// void 
}

GraphicMonsters::RessourceManager::~RessourceManager()
{
	// TO DO
}


/*
 * \brief   Add a key to the RessourceManager.
 *          This key is associated with a Sprite Array 
 *          (which is contruscted). It's a TextureCharacteristics key.
 * \param   spriteKey : the key associated with the new Sprite array
 * \return  bool : True if the key is add, false otherwise.
*/
bool GraphicMonsters::RessourceManager::createKey(std::string const& spriteKey)
{
	// check if the key exists
    m_ressourceArrayIndex = getIterator(spriteKey);
	if (m_ressourceArrayIndex != m_ressources.end()) {
		return true;
	}

	// create a new array from the new key
    m_ressources.emplace(spriteKey, std::vector <GraphicMonsters::Ressource>());
	return false;
}



/*
* \brief    Create Sprite copies ready to be used.
* \param    spriteKey : the key of the sprite.
* \param    spriteCharacteristics : the model for the sprite creation.
* \param    layerLevel : the level of the layer for the display.
* \param    numberOfElements : The number of instance of this Sprite we want to create
*           and prepare.
* \return   bool : True if the sprite(s) is created, false otherwise.
*/
bool GraphicMonsters::RessourceManager::createSprite(std::string const& spriteKey,
	                                                 GraphicMonsters::TextureCharacteristics* spriteCharacteristics,
	                                                 unsigned int layerLevel,
	                                                 unsigned int numberOfElements)
{
	// check if the key exists
    m_ressourceArrayIndex = getIterator(spriteKey);
	if (m_ressourceArrayIndex == m_ressources.end()) {
		return false;
	}

	// create n sprites in the array
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
        m_ressourceArrayIndex->second.push_back(GraphicMonsters::Ressource(new GraphicMonsters::Sprite(spriteCharacteristics, layerLevel)));
	}
	return true;
}




/*
* \brief    Create Animation copies ready to be used.
* \param    spriteKey : the key of the animation.
* \param    animationCharacteristic : the model for the animation creation.
* \param    layerLevel : the level of the layer for the display.
* \param    numberOfElements : The number of instance of this Sprite we want to create
*           and prepare.
* \return   bool : True if the animation(s) is created, false otherwise.
*/
bool GraphicMonsters::RessourceManager::createAnimation(std::string const& spriteKey,
	                                                    GraphicMonsters::TextureCharacteristics* animationCharacteristic,
	                                                    unsigned int layerLevel,
	                                                    unsigned int numberOfElements)
{
	// check if the key exists
    m_ressourceArrayIndex = getIterator(spriteKey);
	if (m_ressourceArrayIndex == m_ressources.end()) {
		return false;
	}

	// create n animations in the array
	for (unsigned int i = 0; i < numberOfElements; i++)
	{
        m_ressources[spriteKey].push_back(GraphicMonsters::Ressource(new GraphicMonsters::Animation(animationCharacteristic, layerLevel)));
	}

	return true;
}




/*
* \brief    Get a reference on a free Sprite/Animation, and add one
*           if all are busy.
* \param    spriteKey : The key of the sprite we want.
* \return   GraphicMonsters::Sprite* : a free sprite pointeur
*/
GraphicMonsters::Sprite* GraphicMonsters::RessourceManager::getFreeSprite(std::string const& spriteKey)
{
	// check if the key exists
    m_ressourceArrayIndex = getIterator(spriteKey);
	if (m_ressourceArrayIndex == m_ressources.end()) {
		return NULL;
	}

	// check if there is a non used sprite
	for (unsigned int i = 0; i < m_ressourceArrayIndex->second.size(); i++)
	{
		// return the adress of the free sprite
		if (!m_ressourceArrayIndex->second[i].isUsed)
		{
			// set the variable isUsed to show that this object is busy
			m_ressourceArrayIndex->second[i].isUsed = true;
            return m_ressources[spriteKey][i].sprite;
		}
	}

	// create a sprite if all sprites are busy

	// check if there is an another element to copy it
	if (m_ressourceArrayIndex->second.size() == 0)
	{
		return NULL;
	}

	GraphicMonsters::Sprite* newSprite = NULL;

	// check if we need to construct a GraphicMonsters::Sprite or an GraphicMonsters::Animation
	if (m_ressourceArrayIndex->second[0].sprite->isSprite())
	{
		// create a copy from the first GraphicMonsters::Sprite element
		newSprite = new GraphicMonsters::Sprite(*m_ressourceArrayIndex->second[0].sprite);
	}
	else
	{
		// create an GraphicMonsters::Animation by casting the first element in GraphicMonsters::Animation
		newSprite = new GraphicMonsters::Animation(*(GraphicMonsters::Animation*)m_ressourceArrayIndex->second[0].sprite);
	}

	// add the new objet to the map
    m_ressources[spriteKey].push_back(GraphicMonsters::Ressource(newSprite));

	// set the variable isUsed to show that this object is busy
	m_ressourceArrayIndex->second[m_ressourceArrayIndex->second.size()-1].isUsed = true;

	// return the address of the object
	return newSprite;
}

GraphicMonsters::Sprite* GraphicMonsters::RessourceManager::getSpecificSprite(std::string const& key, 
                                                                              unsigned int id)
{
	// check if the key exists
	m_ressourceArrayIndex = getIterator(key);
	if (m_ressourceArrayIndex == m_ressources.end()) {
		return NULL;
	}

	// check if the id exists
	if (m_ressourceArrayIndex->second.size() <= id)
	{
		return NULL;
	}

	// return the address of the sprite at the index id
	return m_ressourceArrayIndex->second[id].sprite;
}


/*
* \brief    Release a specific sprite instance identified by his spriteKey and his id.
* \param    spriteKey : the key of the sprite.
* \param    id : the id in the sprite array of the specific instance of the sprite.
* \return   bool : true if the instance was release, false otherwise.
*/
bool GraphicMonsters::RessourceManager::releaseSpecificSprite(std::string const& spriteKey, unsigned int id)
{
    m_ressourceArrayIndex = getIterator(spriteKey);
	if (m_ressourceArrayIndex != m_ressources.end()) {
		if (m_ressourceArrayIndex->second.size() >= id)
		{
			m_ressourceArrayIndex->second[id].isUsed = false;
			return true;
		}
	}
	return false;
}


/*
* \brief    Update the animations.
*           delaTime : the time between this frame and the last.
*/
void GraphicMonsters::RessourceManager::updateAnimations(double delaTime)
{
	for (std::map<std::string, std::vector<GraphicMonsters::Ressource>>::iterator animation = m_ressources.begin();
		animation != m_ressources.end(); ++animation)
	{
		for (unsigned int i = 0; i < animation->second.size(); i++)
		{
			if (animation->second[i].isUsed)
			{
                animation->second[i].sprite->actualize(delaTime);
				animation->second[i].sprite->addToTileset();
			}
		}
	}
}


/*
 * \brief   Return the iterator on the sprite array.
 * \param   keySprite : The key of the sprite array.
 * \return  std::map <std::string, std::vector <GraphicMonsters::Ressource> >::iterator
 *          the iterator on the sprite array.
*/
std::map <std::string, std::vector <GraphicMonsters::Ressource> >::iterator GraphicMonsters::RessourceManager::getIterator(std::string const& keySprite)
{
    return m_ressources.find(keySprite);
}
#pragma once
#include <map>
#include <vector>
#include <string>
#include "Engines/GraphicEngine/Sprite.hpp"
#include "Engines/GraphicEngine/Animation.hpp"
#include "Engines/GraphicEngine/TextureCharacteristics.hpp"
#include "Engines/GraphicEngine/Ressource.hpp"
#include "Engines/Config.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	Manage the ressources to
	*			avoid useless copy of elements
	*			and minimize memory use.
	*/
	class GRAPHIC_API RessourceManager
	{
	public:
		RessourceManager();
		~RessourceManager();

		//create methods
        bool	createKey(std::string const& spriteKey);
		
		bool	createSprite(std::string const& spriteKey,
					         TextureCharacteristics* animationCharacteristic,
					         unsigned int layerLevel,
					         unsigned int numberOfElements = 1);
		
		bool	createAnimation(std::string const& spriteKey,
					            TextureCharacteristics* animationCharacteristic,
					            unsigned int layerLevel,
					            unsigned int numberOfElements = 1);

		// get a free sprite
        Sprite* getFreeSprite(std::string const& spriteKey);

		// get a specific sprite
        Sprite* getSpecificSprite(std::string const& spriteKey, unsigned int id);

		// free a ressource
        bool	releaseSpecificSprite(std::string const& spriteKey, unsigned int id);

		// time gestion
        void	updateAnimations(double delaTime);

	private:
		std::map <std::string, std::vector <Ressource> >::iterator
            getIterator(std::string const& keySprite);

		std::map 
			< std::string, std::vector < Ressource > >::iterator	m_ressourceArrayIndex;
		std::map <std::string, std::vector <Ressource> >			m_ressources;
	};
}
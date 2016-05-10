#pragma once
#include "Engines/GraphicEngine/Sprite.hpp"

namespace GraphicMonsters
{
	/*!
	* \brief	store a sprite and a flag
	*			to know if it is being used
	*/
	class Ressource
	{
	public:
		Ressource(Sprite* sprite)
		{
			this->sprite	= sprite;
			isUsed			= false;
		}

		~Ressource()
		{
			//delete sprite;
		}

		Sprite* sprite;
		bool	isUsed;
	};
}
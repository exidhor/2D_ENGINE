/*!
* \brief Super class for all drawable component
* \file Drawable.hpp
* \author Aredhele
* \version 0.1
* \date 2016-07-29
*/
#ifndef DEF_DRAWABLE_HPP
#define DEF_DRAWABLE_HPP

#include "Modules/ModConfig.hpp"

/*! \namespace wgui
* \brief Contains all classes of the gui module
*
*/
namespace wgui
{
	/*! \class Drawable
	* \brief Super class for all drawable component
	*
	*/
	class INTERFACE_API Drawable
	{
        public:
            /*!
             * \brief Abstract method to get the drawable content
             *        of a GUI Component
             */
            void getFrame();
	};

} // namespace wgui

#endif // DEF_DRAWABLE_HPP
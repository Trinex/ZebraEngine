/**
* Render Module Class.
*
* @file RenderModule.h
* @author Sebastian Salonen
* @date 20110902 - Initial Release
*/
#ifndef   RENDERMODULE_H
#define   RENDERMODULE_H

#include "../Core.h"


namespace Graphics
{
  
//==============================================================================

    class RenderModule
    {
    private:
        Core::GameWorld*		m_game_world;
		sf::RenderWindow*		m_render_window;
      
    public:
		RenderModule();
		~RenderModule();
		
		void					InitModule(Core::GameWorld*, sf::RenderWindow*);
		void					Render();
    };
    
//==============================================================================
  
}

#endif
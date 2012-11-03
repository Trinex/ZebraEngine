/**
* Render Module Class.
*
* @file RenderModule.cpp
* @author Sebastian Salonen
* @date 20110902 - Initial Release
*/

#include "../../includes/Graphics/RenderModule.h"


namespace Graphics
{
 
//==============================================================================

RenderModule::RenderModule()
{
	//Empty
}

//==============================================================================

RenderModule::~RenderModule()
{
	//Empty
}

//==============================================================================

void RenderModule::InitModule(Core::GameWorld* _game_world, sf::RenderWindow* _window)
{
    m_game_world 	= _game_world;
	m_render_window = _window;
}

//==============================================================================

void RenderModule::Render()
{
    //render etc
}

//==============================================================================
  
}
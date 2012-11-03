/**
* Game World Class.
*
* @file GameWorld.h
* @author Sebastian Salonen
* @date 20110902 - Initial Release
*/
#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "../Properties.h"
#include "../Managers.h"

namespace Core
{
  
//==============================================================================

  class GameWorld
  {
  protected:
	  // Pointer to Application
      Core::ZebraApplication*     	mp_app;
	  
	  // Modules
      Graphics::RenderModule*		m_render_module;
      Physics::PhysicsModule*		m_physics_module;
	  
	  // Game World Data
      sf::View*						m_world_camera;
      sf::Clock						m_world_time;
      sf::Uint32					m_last_update;
      
  public:
      GameWorld();
      ~GameWorld();
	  
	  // Register Functions
	  void							RegisterApplication(Core::ZebraApplication*);
	  virtual void					RegisterProperties();
	  virtual void					RegisterEvents();
      
	  // Functions to Override
      virtual void					Update();
      virtual void					InitGameWorld();
	  virtual void					CleanGameWorld();
	  
	  // Get Methods
      Graphics::RenderModule*		GetRenderModule();
      Physics::PhysicsModule*		GetPhysicsModule();
      sf::View*						GetWorldCamera();
      sf::Uint32					GetWorldTime();
      sf::Uint32					GetUpdateDuration();
  };
  
//==============================================================================
  
}

#endif
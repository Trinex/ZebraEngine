/**
* Physics Module Class.
*
* @file PhysicsModule.h
* @author Sebastian Salonen
* @date 20110902 - Initial Release
*/
#ifndef PHYSICSMODULE_H
#define PHYSICSMODULE_H

#include "../Core.h"
#include "../Entities.h"

namespace Physics
{
  
//==============================================================================
 
    class PhysicsModule
    {
    private:
		Core::GameWorld*				m_game_world;
		b2World*					m_physics_world;
		Graphics::DebugDrawer*				m_debug_drawer;
	
    public:
		PhysicsModule();
		~PhysicsModule();
		
		void						InitModule(Core::GameWorld*, sf::RenderWindow*);
		void						Update();
    };
    
//==============================================================================
  
}

#endif
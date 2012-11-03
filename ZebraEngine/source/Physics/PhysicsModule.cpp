/**
* Physics Module Class.
*
* @file PhysicsModule.h
* @author Sebastian Salonen
* @date 20110902 - Initial Release
*/

#include "../../includes/Physics/PhysicsModule.h"


namespace Physics
{
  
//==============================================================================

PhysicsModule::PhysicsModule()
{
    //Empty
}

//==============================================================================
  
PhysicsModule::~PhysicsModule()
{
    //Empty
}

//==============================================================================

void PhysicsModule::InitModule(Core::GameWorld* _game_world, sf::RenderWindow* _window)
{
    //Setup the world
    b2Vec2 gravity(0.0f, 0.0f);
    m_game_world 	= _game_world;
    m_physics_world	= new b2World(gravity);
    
    // Create debug drawer and pass it to Box2D
    m_debug_drawer = new Graphics::DebugDrawer(_window); 
    m_debug_drawer->SetFlags(b2Draw::e_shapeBit);
    m_physics_world->SetDebugDraw(m_debug_drawer);
}

//==============================================================================
 
void PhysicsModule::Update()
{
    // Time for magic =)
    std::vector<EntityPtr>& entity_list = Managers::EntityManager::Instance()->GetEntities();
   
    std::size_t size = entity_list.size();
    for(unsigned int i = 0; i < entity_list.size(); i++)
    {
	entity_list[i]->Update();
    }
}

//==============================================================================
  
}

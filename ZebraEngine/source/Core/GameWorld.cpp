/**
* Game World Class.
*
* @file GameWorld.h
* @author Sebastian Salonen
* @date 20110902 - Initial Release
*/

#include "../../includes/Core/GameWorld.h"
#include <SFML/System/Clock.hpp>
using namespace BaseGameFeatures;

namespace Core
{

//==============================================================================
//*************************Constructor/Destructor*******************************
//==============================================================================

GameWorld::GameWorld()
{
    //Empty
}

//==============================================================================

GameWorld::~GameWorld()
{
    //Empty
}

//==============================================================================
//****************************Init/Update/Clean*********************************
//==============================================================================

void GameWorld::InitGameWorld()
{
    // Create Modules
    m_render_module  = new Graphics::RenderModule();
    m_physics_module = new Physics::PhysicsModule();
    m_world_camera   = new sf::View();
    
    // Init Modules
    m_render_module->InitModule (this, mp_app->RenderWindow());
    m_physics_module->InitModule(this, mp_app->RenderWindow());
    
    // Reset Timer
    m_world_time.restart();
    m_last_update = 0;
}

//==============================================================================

void GameWorld::CleanGameWorld()
{
    // Deletes Modules
    delete m_render_module;
    delete m_physics_module;
    delete m_world_camera;
}

//==============================================================================

void GameWorld::Update()
{
    // Physics
    m_physics_module->Update();
    
    // Update Duration
    m_last_update = m_world_time.getElapsedTime().asMilliseconds();
}

//==============================================================================
//***************************Register Functions*********************************
//==============================================================================

void GameWorld::RegisterApplication(Core::ZebraApplication* _app)
{
    mp_app = _app;
}

//==============================================================================

void GameWorld::RegisterProperties()
{
	// First test property
	CameraProperty* cameraProperty = new CameraProperty();
	__RegisterProperty( cameraProperty );
}

//==============================================================================

void GameWorld::RegisterEvents()
{
	// To be implemented...
}

//==============================================================================
//******************************Get Functions***********************************
//==============================================================================

Graphics::RenderModule* GameWorld::GetRenderModule()
{
    return m_render_module;
}

//==============================================================================

Physics::PhysicsModule* GameWorld::GetPhysicsModule()
{
    return m_physics_module;
}

//==============================================================================

sf::View* GameWorld::GetWorldCamera()
{
    return m_world_camera;
}

//==============================================================================

sf::Uint32 GameWorld::GetWorldTime()
{
    return m_world_time.getElapsedTime().asMilliseconds();
}

//==============================================================================

sf::Uint32 GameWorld::GetUpdateDuration()
{
    return m_world_time.getElapsedTime().asMilliseconds() - m_last_update;
}

//==============================================================================
//***********************************END****************************************
//==============================================================================

}
/**
* This is the starting point for all new projects.
*
* @file ZebraApplication.cpp
* @author Sebastian Salonen
* @date 20110615 - Initial Release
*/
#include <assert.h>
#include "../../includes/Core/ZebraApplication.h"
#include <SFML/Graphics/RenderWindow.hpp>


namespace Core
{

//==============================================================================

ZebraApplication::ZebraApplication(const std::string _title, Core::GameWorld* _game_world) :
    m_title(_title),
    m_game_world(_game_world),
    m_video_mode(DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT, DEFAULT_VIDEO_BPP),
    m_window(),
    m_settings(),
    m_style(sf::Style::Close | sf::Style::Resize),
    m_running(true),
    m_update_rate(DEFAULT_UPDATE_RATE)
{

}

//==============================================================================

ZebraApplication::~ZebraApplication()
{
    m_running = false;
}

//==============================================================================

int ZebraApplication::Execute() 
{
    PreInit();
    Init();
    Loop();
    Cleanup();

    return 0;
}

//==============================================================================

bool ZebraApplication::SetupManagers() 
{
    Managers::InputManager::Instance()->RegisterApplication(this);
    return true;
}

//==============================================================================

bool ZebraApplication::PreInit() 
{
    // Setup Managers
    this->SetupManagers();
    
    // Initialize Game World
	m_game_world->RegisterApplication(this);
    m_game_world->InitGameWorld();
    m_game_world->RegisterProperties();
    m_game_world->RegisterEvents();
    
    return true;
}

//==============================================================================

bool ZebraApplication::Init() 
{
    // Window settings
    sf::ContextSettings settings;
    settings.depthBits         = 32; // Request a 32 bits depth buffer
    settings.stencilBits       = 8;  // Request a 8 bits stencil buffer
    settings.antialiasingLevel = 2;  // Request 2 levels of anti aliasing

    m_window.create(sf::VideoMode(DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT, DEFAULT_VIDEO_BPP), m_title, sf::Style::Close | sf::Style::Resize, settings);
    m_window.setVerticalSyncEnabled(true);
    m_window.setActive();
    
    return true;
}

//==============================================================================

void ZebraApplication::Loop() 
{
    // Make sure there is at least one active state HERE

    while(m_running && m_window.isOpen()) 
    {
		// Get current active state

		// Logic
		OnEvent();
		OnGameLogic();

		// Render Window
		OnRender();
    }
}

//==============================================================================

void ZebraApplication::Cleanup() 
{
    //Cleanup Game World
    m_game_world->CleanGameWorld();
	
    //Close Application
    if(m_window.isOpen())
		m_window.close();
}

//==============================================================================

void ZebraApplication::OnEvent() 
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
		switch(event.type)
		{
			case sf::Event::Resized:
			{
				break;
			}
			case sf::Event::Closed:
			{
				m_running = false;
				break;
			}
			default:
			{
				Managers::InputManager::Instance()->HandleInput(event);
				break;
			}
		}
    }
}

//==============================================================================

void ZebraApplication::OnGameLogic()
{   
    // Update Game World
    m_game_world->Update();
    Managers::EntityManager::Instance()->Update();
}

//==============================================================================

void ZebraApplication::OnRender() 
{
    m_game_world->GetRenderModule()->Render();
    m_window.display();
}

//==============================================================================

void ZebraApplication::Shutdown()
{
    m_running = false;
}

//==============================================================================

Core::GameWorld* ZebraApplication::GameWorld()
{
    return m_game_world;
}

//==============================================================================

sf::RenderWindow* ZebraApplication::RenderWindow()
{
    return &m_window;
}

//==============================================================================

}
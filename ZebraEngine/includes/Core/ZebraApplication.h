/**
* This is the starting point for all new projects.
*
* @file ZebraApplication.h
* @author Sebastian Salonen
* @date 20110615 - Initial Release
*/
#ifndef ZEBRAAPPLICATION_H
#define ZEBRAAPPLICATION_H

//#include "../Core.h"
#include "GameWorld.h"
//#include "../Managers.h"


namespace Core
{

//==============================================================================

    // Constants //
    ////////////////////////////////////////////////////////////////////////////
    /// Default Video Width to use if config file not found
    static const unsigned int DEFAULT_VIDEO_WIDTH = 800;
    /// Default Video Height to use if config file not found
    static const unsigned int DEFAULT_VIDEO_HEIGHT = 600;
    /// Default Video bits per pixel (color depth) if config file not found
    static const unsigned int DEFAULT_VIDEO_BPP = 32;
    /// Default Update Rate for Game Logic
    static const float DEFAULT_UPDATE_RATE = 1.0f / 60;
    ////////////////////////////////////////////////////////////////////////////
    
//==============================================================================

    class ZebraApplication 
    {
    private:
      // Title for Window
      std::string					m_title;
      // Video Mode
      sf::VideoMode					m_video_mode;
      // Render Window
      sf::RenderWindow				m_window;
      // Game World
      Core::GameWorld*				m_game_world;
      // Window Settings
      sf::ContextSettings			m_settings;
      // Window Style
      unsigned long					m_style;
      // Is App Running?
      bool							m_running;
      // Update Rate
      float							m_update_rate;

    public:
      ZebraApplication(std::string _title, Core::GameWorld* _game_world);
      virtual ~ZebraApplication();

      // Execution
      int							Execute();

      // What to Execute
      bool							SetupManagers();
      bool							PreInit();
      bool							Init();
      void							Loop();	
      void							Cleanup();

      // What to Loop
      void							OnEvent();
      void							OnGameLogic();
      void							OnRender();
      
      // Shutdown Request
      void							Shutdown();
      
      // Game World
      Core::GameWorld*				GameWorld();
	  sf::RenderWindow*				RenderWindow();	
    };

//==============================================================================

}


#endif
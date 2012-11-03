/**
* Input Manager Class.
*
* @file InputManager.h
* @author Sebastian Salonen
* @date 20110901 - Initial Release
*/
#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "../Core.h"

namespace Input
{
   
//==============================================================================
    
    enum MouseInput
    {
		LEFT,
		RIGHT,
		WHEEL,
		MOVE
    };
    
//==============================================================================
    
}

namespace Managers
{
  
//==============================================================================

    class InputManager
    { 
    private:
      InputManager();
      InputManager(const InputManager&);
      InputManager &operator=(const InputManager&);
      
      static InputManager*					mp_instance;
      Core::ZebraApplication*     			mp_app;
      
      // Mouse Input
      sf::Vector2i							m_last_mouse_pos;
      bool									m_left_mouse_pressed,  m_left_mouse_released;
      bool									m_right_mouse_pressed, m_right_mouse_released;
      bool									m_mouse_wheeled;
      bool									m_mouse_moved;
      int									m_delta_x, m_delta_y, m_delta_wheel;
      
      // Keyboard Input
      bool*									m_keys_pressed;
      bool*									m_keys_released;
      
    public:
      ~InputManager();
      
      static InputManager*					Instance();
      void									RegisterApplication(Core::ZebraApplication*);
      void									HandleInput(sf::Event);
      int									GetDeltaX();
      int									GetDeltaY();
      int									GetDeltaWheel();
      sf::Vector2i							GetMousePos();
      bool									IsClicked(Input::MouseInput);
      bool									IsMouseReleased(Input::MouseInput);
      bool									IsMoved(Input::MouseInput);
      bool									IsPressed(int);
      bool									IsReleased(int);
    };
  
//==============================================================================
  
}


#endif
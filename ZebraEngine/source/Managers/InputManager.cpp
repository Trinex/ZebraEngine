/**
* Input Manager Class.
*
* @file InputManager.cpp
* @author Sebastian Salonen
* @date 20110901 - Initial Release
*/

#include "../../includes/Managers/InputManager.h"
#include <SFML/Window/Event.hpp>

namespace Managers
{
//==============================================================================

InputManager* InputManager::mp_instance = NULL;

//==============================================================================

InputManager::InputManager()
{
    mp_app					= NULL;
    m_left_mouse_pressed 	= false;
    m_right_mouse_pressed	= false;
    m_left_mouse_released 	= false;
    m_right_mouse_released	= false;
    m_mouse_wheeled			= false;
    m_mouse_moved			= false;

    m_keys_pressed = new bool[256];
    m_keys_released = new bool[256];
    for(int i = 0; i < 256; i++)
    {
      m_keys_pressed[i] 	= false;
      m_keys_released[i] 	= false;
    }

    m_delta_x 				= 0;
    m_delta_y 				= 0;
    m_delta_wheel			= 0;
}

//==============================================================================

InputManager* InputManager::Instance()
{
    if(mp_instance == NULL)
	mp_instance = new InputManager();
    
    return mp_instance;
}

//==============================================================================

void InputManager::RegisterApplication(Core::ZebraApplication* _app)
{
    mp_app = _app;
}

//==============================================================================

void InputManager::HandleInput(sf::Event _event)
{ 
    assert(mp_app != NULL);
    
    switch(_event.type)
    {
      
	case sf::Event::KeyPressed:
	{
	    if(_event.key.code == sf::Keyboard::Escape)
			mp_app->Shutdown();
	    
	    m_keys_pressed[_event.key.code] = true;
	    break;
	}
	case sf::Event::KeyReleased:
	{
	    m_keys_pressed[_event.key.code] = false;
	    m_keys_released[_event.key.code] = true;
	    
	    break;
	}
	case sf::Event::MouseButtonPressed:
	{
	    if(sf::Mouse::Left == _event.mouseButton.button)
			m_left_mouse_pressed = true;
	    else if(sf::Mouse::Right == _event.mouseButton.button)
			m_right_mouse_pressed = true;
	  
	    break;
	}
	case sf::Event::MouseButtonReleased:
	{
	    if(sf::Mouse::Left == _event.mouseButton.button)
			{m_left_mouse_pressed = false; m_left_mouse_released = true;}
	    else if(sf::Mouse::Right == _event.mouseButton.button)
			{m_right_mouse_pressed = false; m_right_mouse_released = true;}
	    
	    break;
	}
	case sf::Event::MouseMoved:
	{
	    m_delta_x 			= _event.mouseMove.x - m_last_mouse_pos.x;
	    m_delta_y			= _event.mouseMove.y - m_last_mouse_pos.y;
	    m_last_mouse_pos.x  = _event.mouseMove.x;
	    m_last_mouse_pos.y  = _event.mouseMove.y;
	    
	    break;
	}
	case sf::Event::MouseWheelMoved:
	{
	    m_mouse_wheeled	= true;
	    m_delta_wheel	= _event.mouseWheel.delta;
	    break;
	}
	default:
	{
	    break;
	}
      
    }
}

//==============================================================================

int InputManager::GetDeltaX()
{
    int return_value;
    
    return_value 	= m_delta_x;
    m_delta_x 		= 0;
    
    return return_value;
}

//==============================================================================

int InputManager::GetDeltaY()
{
    int return_value;
    
    return_value	= m_delta_y;
    m_delta_y 		= 0;
    
    return return_value;
}

//==============================================================================

int InputManager::GetDeltaWheel()
{
    m_mouse_wheeled = false;
    return m_delta_wheel;
}

//==============================================================================

sf::Vector2i InputManager::GetMousePos()
{
	return m_last_mouse_pos;
}

//==============================================================================

bool InputManager::IsClicked(Input::MouseInput _mouse_input)
{
    switch(_mouse_input)
    {
		case Input::LEFT:
		{
			return m_left_mouse_pressed;
			break;
		}
		case Input::RIGHT:
		{
			return m_right_mouse_pressed;
			break;
		}
		default:
		{
			return false;
			break;
		}
    }
    
}

//==============================================================================

bool InputManager::IsMouseReleased(Input::MouseInput _mouse_input)
{
    bool return_value = false;
    
    if(_mouse_input == Input::LEFT)
    {
	return_value = m_left_mouse_released;
	m_left_mouse_released = false;
    }
    else if(_mouse_input == Input::RIGHT)
    {
	return_value = m_right_mouse_released;
	m_right_mouse_released = false;
    }
    
    return return_value;
}

//==============================================================================

bool InputManager::IsMoved(Input::MouseInput _mouse_input)
{
    switch(_mouse_input)
    {
	case Input::MOVE:
	{
	    return m_mouse_moved;
	    break;
	}
	case Input::WHEEL:
	{
	    return m_mouse_wheeled;
	    break;
	}
	default:
	{
	    return false;
	    break;
	}
    }
}

//==============================================================================

bool InputManager::IsPressed(int _key_input)
{
    return m_keys_pressed[_key_input];
}

//==============================================================================

bool InputManager::IsReleased(int _key_input)
{
    bool return_value = m_keys_released[_key_input];
    m_keys_released[_key_input] = false;
    return return_value;
}

//==============================================================================

}
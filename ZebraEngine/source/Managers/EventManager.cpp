/**
* Event Manager - Handle events and broadcasts it for subscribers
*
* @file EventManager.cpp
* @author Sebastian Salonen
* @date 20111213 - Initial Release
*/
#include "../../includes/Managers/EventManager.h"

using namespace BaseGameFeatures;


namespace Managers
{
  
//==============================================================================

EventManager* EventManager::mp_instance = NULL;

//==============================================================================

EventManager::EventManager()
	: mp_app(NULL)
{
	//Empty
}

//==============================================================================

EventManager::~EventManager()
{
	//Empty
}

//==============================================================================

EventManager* EventManager::Instance()
{
    if(mp_instance == NULL)
		mp_instance = new EventManager();
    
    return mp_instance;
}

//==============================================================================

void EventManager::RegisterApplication(Core::ZebraApplication* _app)
{
    mp_app = _app;
}

//==============================================================================

void EventManager::RegisterEvent(Event* _Event, std::string _name)
{
	// To be made
}

//==============================================================================

void EventManager::Subscribe(std::string _name)
{
	// To be made
}

//==============================================================================

}
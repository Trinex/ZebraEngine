/**
* Event Manager - Handle events and broadcasts it for subscribers
*
* @file EventManager.h
* @author Sebastian Salonen
* @date 20111213 - Initial Release
*/
#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "../Core.h"
#include "../BaseGameFeatures/Event.h"
#include <map>
#include <boost\signals2.hpp>
#include <boost\ptr_container\ptr_map.hpp>


namespace Managers
{

//==============================================================================

class EventManager
{
private:
	// Constructors
	EventManager();
	EventManager(const EventManager&);
	EventManager &operator=(const EventManager&);

	// Instances
	static EventManager*								mp_instance;
	Core::ZebraApplication*     						mp_app;

	// Data
	boost::ptr_map<std::string, boost::signals2::signal_base>		m_signals;
	//std::vector<std::string>							m_registered_names;
	//std::vector<BaseGameFeatures::Event*>				m_registered_events;


public:
	~EventManager();

	static EventManager*								Instance();
	void												RegisterApplication(Core::ZebraApplication*);
	void												RegisterEvent(BaseGameFeatures::Event*, std::string);
	void												Subscribe(void* function);
};

//==============================================================================

}


#endif
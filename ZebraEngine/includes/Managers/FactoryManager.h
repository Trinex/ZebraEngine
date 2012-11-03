/**
* Factory Manager Class.
*
* @file FactoryManager.h
* @author Sebastian Salonen
* @date 20120428 - Initial Release
*/
#ifndef FACTORYMANAGER_H
#define FACTORYMANAGER_H

//#include "../BaseGameFeatures/Entity.h"
#include "../Core/Types.h"
#include "../Data/TypeDefinitions.h"
#include "../Data/XMLParser.h"

namespace BaseGameFeatures
{

//==============================================================================

    class Entity;
    class Property;

//==============================================================================

}

namespace Managers
{

//==============================================================================

    class FactoryManager
    {
    private:
	FactoryManager();
	FactoryManager(const FactoryManager&);
	FactoryManager &operator=(const FactoryManager&);
	
	static FactoryManager*						mp_instance;
	Core::ZebraApplication*     				mp_app;
	std::vector<BaseGameFeatures::Property*>	m_property_templates;
	std::vector<BaseGameFeatures::Entity>		m_entity_templates;
	Data::XMLParser								m_xml_parser;

    public:
	~FactoryManager();

	static FactoryManager*						Instance();
	void										RegisterApplication(Core::ZebraApplication* _app);
	void										RegisterProperty(BaseGameFeatures::Property* _property);
	
	// Create Entity By ID
	EntityPtr									CreateEntity(id_t _id);
	
	// Create Entity By Name
	EntityPtr									CreateEntity(std::string _name);
	
	// Load Blueprint
	void										LoadBlueprint(std::string _path);
    };
  
//==============================================================================
  
}


#endif
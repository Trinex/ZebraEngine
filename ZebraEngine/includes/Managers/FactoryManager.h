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
#include "AssetManager.h"
#include "EntityManager.h"
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
	
	static FactoryManager*							mp_instance;
	Core::ZebraApplication*     					mp_app;
	std::vector<BaseGameFeatures::Property*>		m_property_templates;
	std::vector<BaseGameFeatures::Entity>			m_entity_templates;
	std::vector<BaseGameFeatures::AssetTemplate>	m_asset_templates;
	Data::XMLParser									m_xml_parser;

    public:
	~FactoryManager();

	static FactoryManager*							Instance();
	void											RegisterApplication(Core::ZebraApplication* _app);
	void											RegisterProperty(BaseGameFeatures::Property* _property);
	
	// Create Entity By ID
	EntityPtr										CreateEntity(id_t _id);
	
	// Create Entity By Name
	EntityPtr										CreateEntity(std::string _name);

	// Get Asset Templates List
	std::vector<BaseGameFeatures::AssetTemplate>&	GetAssetTemplates();
	
	// Load Blueprint
	void											LoadEntityBlueprints(std::string _path);
	void											LoadAssetBlueprint(std::string _path);
    };
  
//==============================================================================
  
}


#endif
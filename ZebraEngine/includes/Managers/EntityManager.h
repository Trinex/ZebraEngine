/**
* Entity Manager Class.
*
* @file EntityManager.h
* @author Sebastian Salonen
* @date 20110904 - Initial Release
*/
#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "../BaseGameFeatures/Entity.h"

namespace BaseGameFeatures
{
    class Entity;
}

namespace Managers
{
  
//==============================================================================

    class EntityManager
    {
    private:
	EntityManager();
	EntityManager(const EntityManager&);
	EntityManager &operator=(const EntityManager&);

	static EntityManager*							mp_instance;
	Core::ZebraApplication*     					mp_app;
	std::vector<EntityPtr>							m_entities;
	boost::uint32_t									m_id_count;

    public:
	~EntityManager();

	static EntityManager*							Instance();
	void											RegisterApplication(Core::ZebraApplication*);
	void											RegisterEntity(EntityPtr _entity);
	std::vector<EntityPtr>&							GetEntities();
	void											DeleteEntity(id_t _id);
	void											Update();
    };
  
//==============================================================================
  
}


#endif
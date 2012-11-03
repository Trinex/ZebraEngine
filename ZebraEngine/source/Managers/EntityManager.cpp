/**
* Entity Manager Class.
*
* @file EntityManager.cpp
* @author Sebastian Salonen
* @date 20110904 - Initial Release
*/

#include "../../includes/Managers/EntityManager.h"


namespace Managers
{
  
//==============================================================================

EntityManager* EntityManager::mp_instance = NULL;

//==============================================================================

EntityManager::EntityManager()
	: mp_app(NULL), m_id_count(0)
{
	//Empty
}

//==============================================================================

EntityManager::~EntityManager()
{
	//Empty
}

//==============================================================================

EntityManager* EntityManager::Instance()
{
    if(mp_instance == NULL)
	mp_instance = new EntityManager();
    
    return mp_instance;
}

//==============================================================================

void EntityManager::RegisterApplication(Core::ZebraApplication* _app)
{
    mp_app = _app;
}

//==============================================================================

void EntityManager::RegisterEntity(EntityPtr _entity)
{
    _entity->SetID(m_id_count);
    m_entities.push_back(_entity);
    
    m_id_count++;
}

//==============================================================================

std::vector<EntityPtr>& EntityManager::GetEntities()
{
    return m_entities;
}

//==============================================================================

void EntityManager::Update()
{

}

//==============================================================================

void EntityManager::DeleteEntity(id_t _id)
{
    // Slow
    for( unsigned int i = 0; i < m_entities.size(); i++ )
    {
	if( m_entities[i]->GetID() == _id )
	{
	    m_entities.erase(m_entities.begin()+i);
	}
    }
}

//==============================================================================

}
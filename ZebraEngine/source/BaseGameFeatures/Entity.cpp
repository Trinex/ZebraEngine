/**
* Base Class for Entities.
*
* @file Entity.cpp
* @author Sebastian Salonen
* @date 20110615 - Initial Release
*/
#include "../../includes/BaseGameFeatures/Entity.h"

namespace BaseGameFeatures
{

//==============================================================================

Entity::Entity()
	: m_id(0)
{
	//Empty
}

//==============================================================================  

Entity::~Entity()
{
	//Empty
}

//==============================================================================
//*****************************Set Functions************************************
//==============================================================================

void Entity::SetID(const id_t _id)
{
    m_id = _id;
}

//==============================================================================

void Entity::SetGUID(const id_t _guid)
{
    m_guid = _guid;
}

//==============================================================================

void Entity::SetName(const std::string& _name)
{
    m_name = _name;
}

//==============================================================================

template<class TYPE>
void Entity::SetAttribute(id_t _id, TYPE& _value)
{
	size_t attrs = m_attributes.size();
	for( unsigned int i = 0; i < attrs; i++ )
	{
		if( m_attributes[i]->GetID() == _id )
		{
			m_attributes[i]->SetValue<TYPE>(_value);
			return;
		}
	}

	// Assert here
}

//==============================================================================

template<class TYPE>
void Entity::SetAttribute(const std::string& _name, TYPE& _value)
{
	size_t attrs = m_attributes.size();
	for( unsigned int i = 0; i < attrs; i++ )
	{
		if( m_attributes[i]->GetName().compare(_name) == 0 )
		{
			m_attributes[i]->SetValue<TYPE>(_value);
			return;
		}
	}
	
	// Assert here
}

//==============================================================================
//*****************************Add Functions************************************
//==============================================================================

void Entity::AddProperty(boost::shared_ptr<Property> _property)
{
    m_properties.push_back(_property);
}

//==============================================================================


void Entity::AddAttribute(boost::shared_ptr<Attribute> _attribute)
{
    m_attributes.push_back(_attribute);
}

//==============================================================================
//*****************************Get Functions************************************
//==============================================================================

const id_t Entity::GetID()
{
    return m_id;
}

//==============================================================================

const id_t Entity::GetGUID()
{
    return m_guid;
}

//==============================================================================

const std::string& Entity::GetName()
{
    return m_name;
}

//============================================================================== 

template<class TYPE>
TYPE& Entity::GetAttribute(const id_t _id)
{
    for( unsigned int i = 0; i < m_attributes.size(); i++ )
    {
	if( m_attributes[i]->GetID() == _id )
	{
	    return m_attributes[i]->GetValue<TYPE>();
	}   
    }
    
    // assert
    return 0;
}

//============================================================================== 

template<class TYPE>
TYPE& Entity::GetAttribute(const std::string& _name)
{
    for( unsigned int i = 0; i < m_attributes.size(); i++ )
    {
	if( m_attributes[i]->GetName() == _name )
	{
	    return m_attributes[i]->GetValue<TYPE>();
	}   
    }
    
    // assert
    return 0;
}

//============================================================================== 

boost::shared_ptr<Attribute> Entity::GetAttributeRef(const id_t _id)
{
	for( unsigned int i = 0; i < m_attributes.size(); i++ )
	{
		if( m_attributes[i]->GetID() == _id )
		{
			return m_attributes[i];
		}   
	}

	// assert
	return boost::shared_ptr<Attribute>();
}

//============================================================================== 

boost::shared_ptr<Attribute> Entity::GetAttributeRef(const std::string& _name)
{
	for( unsigned int i = 0; i < m_attributes.size(); i++ )
	{
		if( m_attributes[i]->GetName() == _name )
		{
			return m_attributes[i];
		}   
	}

	// assert
	return boost::shared_ptr<Attribute>();
}

//============================================================================== 

boost::shared_ptr<Property> Entity::FindProperty(const id_t _id)
{
    std::size_t size = m_properties.size();
    for(unsigned int i = 0; i < size; i++ )
    {
	if(m_properties[i]->GetID() == _id )
	{
	    return m_properties[i];
	}
    }
    
    // Assert instead
    return boost::shared_ptr<Property>();
}

//============================================================================== 

boost::shared_ptr<Property> Entity::FindProperty(const std::string& _name)
{
    std::size_t size = m_properties.size();
    for(unsigned int i = 0; i < size; i++ )
    {
	if(m_properties[i]->GetName() == _name )
	{
	    return m_properties[i];
	}
    }
    
    // Assert instead
    return boost::shared_ptr<Property>();
}

//============================================================================== 

void Entity::Update()
{
    // To be updated
}

//============================================================================== 

}
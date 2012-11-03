/**
* Property Register Class
*
* @file PropertyRegister.cpp
* @author Sebastian Salonen
* @date 20111126 - Initial Release
*/

#include "../../includes/Managers/PropertyRegister.h"
#include "../../includes/BaseGameFeatures/Properties/CameraProperty.h"

using namespace BaseGameFeatures;
using namespace boost;
using namespace std;


namespace Managers
{

//==============================================================================

PropertyRegister* PropertyRegister::mp_instance = NULL;
	
//==============================================================================

PropertyRegister::PropertyRegister()
{
    //Empty
}

//==============================================================================

PropertyRegister::~PropertyRegister()
{
    //Empty
}

//==============================================================================

PropertyRegister* PropertyRegister::Instance()
{
    if(mp_instance == NULL)
	mp_instance = new PropertyRegister();

    return mp_instance;
}

//==============================================================================

void PropertyRegister::Register( shared_ptr<Property> _property, bool _on_frame )
{
    m_registered_properties.push_back( _property );
    if( _on_frame )
	m_onframe_properties.push_back( _property );
}

//==============================================================================

shared_ptr<Property> PropertyRegister::FindProperty( id_t _id )
{
    std::size_t size = m_registered_properties.size();
    for( unsigned int i = 0; i < size; i++ )
    {
	if( m_registered_properties[i]->GetID() == _id )
	    return m_registered_properties[i];
    }
    
    // Assert instead...
    return shared_ptr<Property>();
}

//==============================================================================

shared_ptr<Property> PropertyRegister::FindProperty( const std::string& _name )
{
    std::size_t size = m_registered_properties.size();
    for( unsigned int i = 0; i < size; i++ )
    {
	if( m_registered_properties[i]->GetName() == _name )
	    return m_registered_properties[i];
    }
    
    // Assert instead...
    return shared_ptr<Property>();
}

//==============================================================================
	
}
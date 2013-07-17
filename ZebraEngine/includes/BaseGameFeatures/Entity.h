/**
* Base Class for Entities.
*
* @file BaseGameEntity.h
* @author Sebastian Salonen
* @date 20110615 - Initial Release
*/
#ifndef BASEGAMEENTITY_H
#define BASEGAMEENTITY_H

#include "../Core.h"
#include "../Data/Macros.h"
#include "../Data/TypeDefinitions.h"
#include "Property.h"
#include "Attribute.h"
#include "Asset.h"


namespace BaseGameFeatures
{
	
//==============================================================================

    class Property;
    class Attribute;
	class BaseGameAsset;

//==============================================================================

    class Entity
    {
    private:
		boost::uint32_t									m_id;
		boost::uint32_t									m_guid;
		std::string										m_name;
		std::vector< boost::shared_ptr<Property> >		m_properties;
		std::vector< boost::shared_ptr<Attribute> >		m_attributes;
		std::vector< boost::shared_ptr<BaseGameFeatures::BaseGameAsset> >	m_assets;

    public:
		// Constructors
		Entity();
		~Entity();

		// Set Functions
		void											SetID(const id_t _id);
		void											SetGUID(const id_t _guid);
		void											SetName(const std::string& _name);
		template<class TYPE> void						SetAttribute(const id_t _id, TYPE& _value);
		template<class TYPE> void						SetAttribute(const std::string& _name, TYPE& _value);
			
		// Add Functions	
		void											AddProperty(boost::shared_ptr<Property> _property);
		void											AddAttribute(boost::shared_ptr<Attribute> _attribute);

		// Get Functions
		const id_t										GetID();
		const id_t										GetGUID();
		const std::string&								GetName();
		template<class TYPE> TYPE&						GetAttribute(const id_t _id);
		template<class TYPE> TYPE&						GetAttribute(const std::string& _name);
		boost::shared_ptr<Attribute>					GetAttributeRef(const id_t _id);
		boost::shared_ptr<Attribute>					GetAttributeRef(const std::string& _name);
		boost::shared_ptr<Property>						FindProperty(const id_t _id);
		boost::shared_ptr<Property>						FindProperty(const std::string& _name);
		
		// Update
		virtual void									Update();
    };

//==============================================================================

}

#endif
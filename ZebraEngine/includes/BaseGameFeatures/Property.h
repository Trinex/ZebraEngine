/**
* Base Class for Properties.
*
* @file Property.h
* @author Sebastian Salonen
* @date 20111016 - Initial Release
*/
#ifndef PROPERTY_H
#define PROPERTY_H

#include "../Core/Types.h"
#include "../Data/Macros.h"

namespace BaseGameFeatures
{
	
//==============================================================================

    class Entity;

//==============================================================================

    class Property
    {
	protected:
		// Private vars
		id_t						m_id;
		rtti_t						m_rtti;
		std::string					m_name;
		EntityPtr					m_entity;

	public:
		// Constructors
		Property();
		~Property();
		
		// Init Property
		void						Init(EntityPtr _entity);

		// Update
		virtual void				OnActivate()=0;
		virtual void				OnFrame()=0;
		virtual void				OnDeactivate()=0;

		// Get RTTI
		virtual id_t				GetID();
		rtti_t						GetRTTI();
		const std::string&			GetName();

		// Set RTTI
		void						SetID(id_t _id);
		void						SetRTTI(rtti_t _rtti);
		void						SetName(const std::string& _name);
    };

//==============================================================================

}

#endif
/**
* Property Registry Class
*
* @file PropertyRegister.h
* @author Sebastian Salonen
* @date 20111126 - Initial Release
*/
#ifndef PROPERTYREGISTER_H
#define PROPERTYREGISTER_H

#include <vector>
#include <boost/shared_ptr.hpp>
#include "../BaseGameFeatures/Property.h"
#include "../Data/Macros.h"


namespace Managers
{

//==============================================================================

    class PropertyRegister
    {
	private:
		// Constructors
		PropertyRegister();
		PropertyRegister(const PropertyRegister&);
		PropertyRegister &operator=(const PropertyRegister&);

		// Object instance and registered properties
		static PropertyRegister*										mp_instance;
		std::vector< boost::shared_ptr<BaseGameFeatures::Property> >	m_registered_properties;
		std::vector< boost::shared_ptr<BaseGameFeatures::Property> >	m_onframe_properties;

	public:
		~PropertyRegister();

		static PropertyRegister*								Instance();
		void													Register(boost::shared_ptr<BaseGameFeatures::Property> _property, bool _on_frame);
		boost::shared_ptr<BaseGameFeatures::Property>			FindProperty(const id_t _id);
		boost::shared_ptr<BaseGameFeatures::Property>			FindProperty(const std::string& _name);
    };

//==============================================================================

}

#endif
//#ifndef TYPEDEFENITIONS_H
//#define TYPEDEFENITIONS_H

//#include "../BaseGameFeatures/Entity.h"
//#include "../BaseGameFeatures/Attribute.h"
//#include "../BaseGameFeatures/Property.h"
#include <boost/cstdint.hpp>
#include <boost/shared_ptr.hpp>


namespace BaseGameFeatures
{
    class Entity;
    class Attribute;
    class Property;
};
    
//==============================================================================

typedef boost::uint8_t rtti_t;
typedef boost::uint32_t id_t;
typedef boost::shared_ptr<BaseGameFeatures::Entity> EntityPtr;
typedef boost::shared_ptr<BaseGameFeatures::Attribute> AttrPtr;
typedef boost::shared_ptr<BaseGameFeatures::Property> PropertyPtr;

//==============================================================================

//#endif
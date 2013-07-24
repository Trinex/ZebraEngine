#ifndef TYPES_H
#define TYPES_H

#include <boost\cstdint.hpp>
#include <boost\shared_ptr.hpp>

//==============================================================================

/// Forward declaration

namespace Core
{
    class ZebraApplication;
    class GameWorld;
}

namespace Graphics
{
    class RenderModule;
    class DebugDrawer;
}

namespace Physics
{
    class PhysicsModule;
}

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

#endif
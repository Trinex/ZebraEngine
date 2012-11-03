#include <boost/cstdint.hpp>
#include <typeinfo>
#include "../Managers/FactoryManager.h"
#include "TypeDefinitions.h"

//------------------------------------------------------------------------------
/**
    Declaration macro. Put this into the class declaration.
*/
#define __DeclareProperty \
public: \
	static rtti_t RTTI;

//------------------------------------------------------------------------------
/**
    Implementation macro. Put this into the source file.
*/
#define __ImplementProperty(type, fourcc) \
	rtti_t type::RTTI = (rtti_t)fourcc;

//------------------------------------------------------------------------------
/**
    Register property macro.
*/
#define __RegisterProperty(register_property) \
	register_property->SetRTTI(register_property->RTTI); \
	register_property->SetName(typeid(register_property).name()); \
	Managers::FactoryManager::Instance()->RegisterProperty(register_property);
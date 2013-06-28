/**
 * Provides includes for Zebra Engine
 *
 * @file Core.h
 * @author Sebastian Salonen
 * @date 20110629 - Initial Release
 */
#ifndef   CORE_H
#define   CORE_H

/////////////////////////////////////////////////////////////////////////////
// Config
/////////////////////////////////////////////////////////////////////////////
#include "Core/Config.h"

/////////////////////////////////////////////////////////////////////////////
// Headers
/////////////////////////////////////////////////////////////////////////////

///SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>

///Box2D
#include <Box2D/Box2D.h>

///Boost
#include <boost/shared_ptr.hpp>
#include <boost/cstdint.hpp>

///Core
#include "Core/Types.h"
#include "Core/ZebraApplication.h"
#include "Core/GameWorld.h"

///Graphics
#include "Graphics/DebugDrawer.h"
#include "Graphics/RenderModule.h"

///Physics
#include "Physics/PhysicsModule.h"

#endif
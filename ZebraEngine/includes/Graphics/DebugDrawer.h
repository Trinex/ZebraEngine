/**
* This is a debug drawer for Box2D physic bodies.
*
* @file DebugDrawer.h
* @author Sebastian Salonen
* @date 20110630 - Initial Release
*/
#ifndef DEBUGDRAWER_H
#define DEBUGDRAWER_H

#include "../Core.h"


namespace Graphics
{

//==============================================================================

class DebugDrawer : public b2Draw
{
private:
	sf::RenderWindow*				m_window;
	sf::Color					B2SFColor(const b2Color&);

public:
	DebugDrawer(sf::RenderWindow* renderWindow);

	void						DrawPolygon(const b2Vec2*, int32, const b2Color&);
	void						DrawSolidPolygon(const b2Vec2*, int32, const b2Color&);
	void						DrawCircle(const b2Vec2&, float32, const b2Color&);
	void						DrawSolidCircle(const b2Vec2&, float32, const b2Vec2&, const b2Color&);
	void						DrawSegment(const b2Vec2&, const b2Vec2&, const b2Color&);
	void						DrawTransform(const b2Transform&);
};

//==============================================================================

}

#endif
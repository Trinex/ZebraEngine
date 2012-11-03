/**
* This is a debug drawer for Box2D physic bodies.
*
* @file DebugDrawer.cpp
* @author Sebastian Salonen
* @date 20110630 - Initial Release
*/
#include "../../includes/Graphics/DebugDrawer.h"
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>


namespace Graphics
{

//==============================================================================

DebugDrawer::DebugDrawer(sf::RenderWindow* _renderWindow)
{
	m_window = _renderWindow;
}

//==============================================================================

sf::Color DebugDrawer::B2SFColor(const b2Color& _color)
{
	sf::Color result((sf::Uint8)(_color.r*255), (sf::Uint8)(_color.g*255), (sf::Uint8)(_color.b*255));
	return result;
}

//==============================================================================

void DebugDrawer::DrawPolygon(const b2Vec2* _vertices, int32 _vertexCount, const b2Color& _color)
{
	sf::ConvexShape polygon;
	polygon.setPointCount(_vertexCount);
	polygon.setOutlineColor(B2SFColor(_color));
	for ( int32 i = 0; i < _vertexCount; i++ )
	{
		b2Vec2 vertex = _vertices[i];
		polygon.setPoint( i, sf::Vector2f(vertex.x, vertex.y) );
	}
	m_window->draw(polygon);
}

//==============================================================================

void DebugDrawer::DrawSolidPolygon(const b2Vec2* _vertices, int32 _vertexCount, const b2Color& _color)
{
	sf::ConvexShape polygon;
	polygon.setPointCount(_vertexCount);
	polygon.setFillColor(B2SFColor(_color));
	for ( int32 i = 0; i < _vertexCount; i++ )
	{
		b2Vec2 vertex = _vertices[i];
		//sf::Color sf_color = B2SFColor(_color);
		polygon.setPoint( i, sf::Vector2f(vertex.x, vertex.y) );
	}
	m_window->draw(polygon);
}

//==============================================================================

void DebugDrawer::DrawCircle(const b2Vec2& _center, float32 _radius, const b2Color& _color)
{
	sf::CircleShape circle;//(_center.x, _center.y, _radius, sf::Color(0, 0, 0, 0), 1.0f, B2SFColor(_color));
	circle.setRadius(_radius);
	circle.setPosition(_center.x, _center.y);
	//circle.SetOrigin(_center.x, _center.y);
	circle.setOutlineColor(B2SFColor(_color));
	//m_window->Draw(circle);
}

//==============================================================================

void DebugDrawer::DrawSolidCircle(const b2Vec2& _center, float32 _radius, const b2Vec2& _axis, const b2Color& _color)
{
	sf::CircleShape circle;//(_center.x, _center.y, _radius, B2SFColor(_color));
	circle.setRadius(_radius);
	circle.setPosition(_center.x-(_radius), _center.y-(_radius));
	//circle.SetOrigin(_center.x, _center.y);
	circle.setFillColor(B2SFColor(_color));
	//m_window->Draw(circle);
}

//==============================================================================

void DebugDrawer::DrawSegment(const b2Vec2& _p1, const b2Vec2& _p2, const b2Color& _color)
{
	// not implemented
}

//==============================================================================

void DebugDrawer::DrawTransform(const b2Transform& _xf)
{
	// not implemented
}

//==============================================================================

}
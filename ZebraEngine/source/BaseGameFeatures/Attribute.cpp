/**
* Base Class for Attributes.
*
* @file Attribute.cpp
* @author Sebastian Salonen
* @date 20111111 - Initial Release
*/

#include "../../includes/BaseGameFeatures/Attribute.h"
#include "../../includes/Data/TypeCast.h"
#include <boost/optional.hpp>


namespace BaseGameFeatures
{

//==============================================================================
//*************************Constructor/Destructor*******************************
//==============================================================================


Attribute::Attribute(id_t _id, std::string _name)
    : m_id(_id), m_name(_name)
{
    // Empty
    typeid(int);
}

//==============================================================================

Attribute::~Attribute()
{
    // Empty
}

//==============================================================================
//*****************************Set Functions************************************
//==============================================================================

void Attribute::SetID(const id_t _id)
{
    m_id = _id;
}

//==============================================================================

void Attribute::SetName(const std::string& _name)
{
    m_name = _name;
}

//==============================================================================

void Attribute::SetBool(const bool _value)
{
    m_value = _value;
}

//==============================================================================

void Attribute::SetChar(const char _value)
{
    m_value = _value;
}

//==============================================================================

void Attribute::SetInt(const boost::int32_t& _value)
{
    m_value = _value;
}

//==============================================================================

void Attribute::SetUint(const boost::uint32_t& _value)
{
    m_value = _value;
}

//==============================================================================

void Attribute::SetFloat(const float& _value)
{
    m_value = _value;
}

//==============================================================================

void Attribute::SetString(const std::string& _value)
{
    m_value = _value;
}

//==============================================================================

void Attribute::SetVector2f(const sf::Vector2f& _value)
{
    m_value = _value;
}

//==============================================================================

void Attribute::SetVector2i(const sf::Vector2i& _value)
{
    m_value = _value;
}

//==============================================================================

void Attribute::SetVector2u(const sf::Vector2u& _value)
{
    m_value = _value;
}

//==============================================================================
//*****************************Get Functions************************************
//==============================================================================

const id_t Attribute::GetID()
{
    return m_id;
}

//==============================================================================

const std::string& Attribute::GetName()
{
    return m_name;
}

//==============================================================================

const bool Attribute::GetBool()
{
    return boost::get<bool>(m_value);
}

//==============================================================================

const char Attribute::GetChar()
{
    return boost::get<char>(m_value);
}

//==============================================================================

const boost::int32_t& Attribute::GetInt()
{
    return boost::get<boost::int32_t>(m_value);
}

//==============================================================================

const boost::uint32_t& Attribute::GetUint()
{
    return boost::get<boost::uint32_t>(m_value);
}

//==============================================================================

const float& Attribute::GetFloat()
{
    return boost::get<float>(m_value);
}

//==============================================================================

const std::string& Attribute::GetString()
{
    return boost::get<std::string>(m_value);
}

//==============================================================================

const sf::Vector2f& Attribute::GetVector2f()
{
    return boost::get<sf::Vector2f>(m_value);
}

//==============================================================================

const sf::Vector2i& Attribute::GetVector2i()
{
    return boost::get<sf::Vector2i>(m_value);
}

//==============================================================================

const sf::Vector2u& Attribute::GetVector2u()
{
    return boost::get<sf::Vector2u>(m_value);
}

//==============================================================================

}
/**
* Base Class for Attributes.
*
* @file Attribute.h
* @author Sebastian Salonen
* @date 20111017 - Initial Release
*/
#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "../Core.h"
#include "../Data/TypeDefinitions.h"
#include <string>
#include <boost/cstdint.hpp>
#include <boost/variant.hpp>


namespace BaseGameFeatures
{

//==============================================================================

    typedef enum AttrType
    {
	    NONE,
	    BOOL,
	    CHAR,
	    INT,
	    UINT,
	    FLOAT,
	    STRING,
	    VEC2F,
	    VEC2I,
	    VEC2U
    } attr_t;

//==============================================================================

    class Attribute
    {
	private:
		id_t								m_id;
		std::string							m_name;
		AttrType							m_type;

		boost::variant<
				bool,
				char,
				boost::int32_t,
				boost::uint32_t,
				float,
				std::string,
				sf::Vector2f,
				sf::Vector2i,
				sf::Vector2u
			      >							m_value;
		
	public:
		Attribute(id_t _id, std::string _name);
		~Attribute();

		//Set Functions
		void								SetID(const id_t _id);
		void								SetName(const std::string& _name);
		template<class TYPE> void			SetValue(const TYPE& _value);

		void								SetBool(const bool);
		void								SetChar(const char);
		void								SetInt(const boost::int32_t&);
		void								SetUint(const boost::uint32_t&);
		void								SetFloat(const float&);
		void								SetString(const std::string&);
		void								SetVector2f(const sf::Vector2f&);
		void								SetVector2i(const sf::Vector2i&);
		void								SetVector2u(const sf::Vector2u&);

		//Get Functions
		const id_t						GetID();
		const std::string&					GetName();
		template<class TYPE> const TYPE&	GetValue();

		const bool							GetBool();
		const char							GetChar();
		const boost::int32_t&				GetInt();
		const boost::uint32_t&				GetUint();
		const float&						GetFloat();
		const std::string&					GetString();
		const sf::Vector2f&					GetVector2f();
		const sf::Vector2i&					GetVector2i();
		const sf::Vector2u&					GetVector2u();
    };

//==============================================================================

	template<class TYPE>
	void Attribute::SetValue(const TYPE& _value)
	{
		m_value = _value;
	}

//==============================================================================

	template<class TYPE>
	const TYPE& Attribute::GetValue()
	{
		return boost::get<TYPE>(m_value);
	}

//==============================================================================

}

#endif
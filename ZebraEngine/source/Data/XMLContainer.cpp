/**
* XMLParser for entity creation.
*
* @file XMLParser.cpp
* @author Sebastian Salonen
* @date 20111116 - Initial Release
*/

#include "../../includes/Data/XMLContainer.h"


namespace Data
{

//==============================================================================

XMLContainer::XMLContainer()
    : m_name("root"), m_parent(NULL), m_tag_value("")
{
    //Empty
}

//==============================================================================

XMLContainer::XMLContainer(std::string _name)
    : m_name(_name), m_parent(NULL), m_tag_value("")
{
    //Empty
}

//==============================================================================

XMLContainer::~XMLContainer()
{
    if(m_parent != NULL)
		delete m_parent;
}

//==============================================================================

void XMLContainer::SetParent(XMLContainer* _parent)
{
    m_parent = _parent;
}

//==============================================================================

void XMLContainer::AddValue(std::string _key, std::string _value)
{
    m_values[_key] = _value;
}

//==============================================================================

void XMLContainer::AddTagValue(std::string _value)
{
    m_tag_value = _value;
}

//==============================================================================

XMLContainer* XMLContainer::AddChild(std::string _name)
{
    XMLContainer* new_container = new XMLContainer(_name);
    m_children.push_back(new_container);
    return new_container;
}

//==============================================================================

std::string& XMLContainer::GetName()
{
	return m_name;
}

//==============================================================================

XMLContainer* XMLContainer::GetParent()
{
    return m_parent;
}

//==============================================================================

std::vector<XMLContainer*>& XMLContainer::GetChildren()
{
	return m_children;
}

//==============================================================================

std::map<std::string, std::string>& XMLContainer::GetValues()
{
	return m_values;
}

//==============================================================================

std::string& XMLContainer::GetTagValue()
{
	return m_tag_value;
}

//==============================================================================

std::string XMLContainer::GetValue(const std::string& _key)
{
	std::map<std::string, std::string>::iterator it = m_values.find(_key);
	if( it != m_values.end() )
		return it->second;

	return "";
}

//==============================================================================


bool XMLContainer::FindTag(const std::string& _name, XMLContainer*& _tag)
{
	std::size_t children_size = m_children.size();
	for( unsigned int i = 0; i < children_size; i++ )
	{
		if( _name.compare(m_children[i]->GetName()) == 0 )
		{
			_tag = m_children[i];
			return true;
		}
	}

	return false;
}

//==============================================================================

bool XMLContainer::FindTagRecursive(const std::string& _name, XMLContainer*& _tag)
{
	if( this->FindTag(_name, _tag) )
		return true;
	else
	{
		std::size_t children_size = m_children.size();
		for( unsigned int i = 0; i < children_size; i++ )
		{
			if( m_children[i]->FindTagRecursive(_name, _tag) )
			{
				return true;
			}
		}
	}

	return false;
}

//==============================================================================

bool XMLContainer::FindTagByValue(const std::string& _name, const std::string& _key, const std::string& _value, XMLContainer*& _tag)
{
	std::size_t children_size = m_children.size();
	for( unsigned int i = 0; i < children_size; i++ )
	{
		if( _name.compare(m_children[i]->GetName()) == 0 )
		{
			std::map<std::string, std::string>& values = m_children[i]->GetValues();
			std::map<std::string, std::string>::iterator it = values.find(_key);
			if(it != values.end())
			{
				if( _value.compare(it->second) == 0 )
				{
					_tag = m_children[i];
					return true;
				}
			}
		}
	}

	return false;
}

//==============================================================================

bool XMLContainer::FindAllTags(const std::string& _name, std::vector<XMLContainer*>& _tags)
{
	std::size_t children_size = m_children.size();
	for( unsigned int i = 0; i < children_size; i++ )
	{
		if( _name.compare(m_children[i]->GetName()) == 0 )
		{
			_tags.push_back(m_children[i]);
		}
	}

	return !_tags.empty();
}

//==============================================================================

bool XMLContainer::FindAllTagsRecursive(const std::string& _name, std::vector<XMLContainer*>& _tags)
{
	this->FindAllTags(_name, _tags);

	std::size_t children_size = m_children.size();
	for( unsigned int i = 0; i < children_size; i++ )
		m_children[i]->FindAllTagsRecursive(_name, _tags);

	return !_tags.empty();
}

//==============================================================================

}
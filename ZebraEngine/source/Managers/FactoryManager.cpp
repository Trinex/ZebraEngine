/**
* Factory Manager Class.
*
* @file FactoryManager.cpp
* @author Sebastian Salonen
* @date 20120428 - Initial Release
*/
#include "../../includes/Managers/FactoryManager.h"
#include "../../includes/BaseGameFeatures/Entity.h"
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>


namespace Managers
{
  
//==============================================================================

FactoryManager* FactoryManager::mp_instance = NULL;

//==============================================================================

FactoryManager::FactoryManager()
	: mp_app(NULL)
{
	//Empty
}

//==============================================================================

FactoryManager::~FactoryManager()
{
    std::size_t size = m_property_templates.size();
    for( unsigned int i = 0; i < size; i++ )
		delete m_property_templates[i];
}

//==============================================================================

FactoryManager* FactoryManager::Instance()
{
    if(mp_instance == NULL)
		mp_instance = new FactoryManager();
    
    return mp_instance;
}

//==============================================================================

void FactoryManager::RegisterApplication(Core::ZebraApplication* _app)
{
    mp_app = _app;
}

//==============================================================================

void FactoryManager::RegisterProperty( BaseGameFeatures::Property* _property )
{
    m_property_templates.push_back(_property);
}

//==============================================================================

EntityPtr FactoryManager::CreateEntity( id_t _id )
{
    std::size_t size = m_entity_templates.size();
    for(unsigned int i = 0; i < size; i++)
    {
		if( m_entity_templates[i].GetID() == _id )
		{
			BaseGameFeatures::Entity* raw_entity = new BaseGameFeatures::Entity();
			memcpy(raw_entity, &m_entity_templates[i], sizeof(raw_entity));
			EntityPtr new_entity(raw_entity);
			EntityManager::Instance()->RegisterEntity(new_entity);
		    
			return new_entity;
		}
    }
    
    // Assert instead
    return EntityPtr();
}

//==============================================================================

EntityPtr FactoryManager::CreateEntity( std::string _name )
{
    std::size_t size = m_entity_templates.size();
    for(unsigned int i = 0; i < size; i++)
    {
		if( m_entity_templates[i].GetName() == _name )
		{
			BaseGameFeatures::Entity* raw_entity = new BaseGameFeatures::Entity();
			memcpy(raw_entity, &m_entity_templates[i], sizeof(raw_entity));
			EntityPtr new_entity(raw_entity);
			EntityManager::Instance()->RegisterEntity(new_entity);
		    
			return new_entity;
		}
    }
    
    // Assert instead
    return EntityPtr();
}

//==============================================================================

std::vector<BaseGameFeatures::AssetTemplate>& FactoryManager::GetAssetTemplates()
{
	return m_asset_templates;
}

//==============================================================================

void FactoryManager::LoadEntityBlueprints( std::string _path )
{
    // Load XML data
    m_xml_parser.LoadXML(_path);
    Data::XMLContainer* xml_data = m_xml_parser.GetXMLData();
    
    // Find all entity tags
    std::vector<Data::XMLContainer*> entity_tags;
    xml_data->FindAllTags("Entity", entity_tags);
    
    std::size_t tags = entity_tags.size();
    for(unsigned int i = 0; i < tags; i++)
    {
		EntityPtr entity_template(new BaseGameFeatures::Entity);
		
		std::vector<Data::XMLContainer*>& entity_children = entity_tags[i]->GetChildren();
		std::size_t children = entity_children.size();
		for(unsigned int j = 0; j < children; j++)
		{
			Data::XMLContainer* child_tag = entity_children[j];
			if( child_tag->GetName() == "Attribute" )
			{
				// Fetch data
				std::string name 		 = child_tag->GetValue("name");
				std::string rtti_string  = child_tag->GetValue("rtti");
				std::string type_string  = child_tag->GetValue("type");
				std::string value_string = child_tag->GetTagValue();
				
				// Check if valid
				if( name.empty() || rtti_string.empty() || type_string.empty() )
					break; // Assert instead
				    
				// Convert data
				rtti_t rtti = boost::lexical_cast<rtti_t>(rtti_string);
				

				// *********** Create and set attribute ************** //

				// Bool
				if(type_string.compare("bool") == 0)
				{
					bool bool_value = boost::lexical_cast<bool>(value_string);
					AttrPtr new_attr(new BaseGameFeatures::Attribute(rtti, name));
					new_attr->SetValue<bool>(bool_value);
					entity_template->AddAttribute(new_attr);
				}

				// Char
				else if(type_string.compare("char") == 0)
				{
					boost::uint8_t char_value = boost::lexical_cast<boost::uint8_t>(value_string);
					AttrPtr new_attr(new BaseGameFeatures::Attribute(rtti, name));
					new_attr->SetValue<boost::uint8_t>(char_value);
					entity_template->AddAttribute(new_attr);
				}

				// Int
				else if(type_string.compare("int") == 0)
				{
					boost::int32_t int_value = boost::lexical_cast<boost::int32_t>(value_string);
					AttrPtr new_attr(new BaseGameFeatures::Attribute(rtti, name));
					new_attr->SetValue<boost::int32_t>(int_value);
					entity_template->AddAttribute(new_attr);
				}

				// Uint
				else if(type_string.compare("uint") == 0)
				{
					boost::uint32_t uint_value = boost::lexical_cast<boost::uint32_t>(value_string);
					AttrPtr new_attr(new BaseGameFeatures::Attribute(rtti, name));
					new_attr->SetValue<boost::uint32_t>(uint_value);
					entity_template->AddAttribute(new_attr);
				}

				// Float
				else if(type_string.compare("float") == 0)
				{
					float float_value = boost::lexical_cast<float>(value_string);
					AttrPtr new_attr(new BaseGameFeatures::Attribute(rtti, name));
					new_attr->SetValue<float>(float_value);
					entity_template->AddAttribute(new_attr);
				}

				// String
				else if(type_string.compare("string") == 0)
				{
					AttrPtr new_attr(new BaseGameFeatures::Attribute(rtti, name));
					new_attr->SetValue<std::string>(value_string);
					entity_template->AddAttribute(new_attr);
				}

				// Vector (float)
				else if(type_string.compare("vectorf") == 0)
				{
					sf::Vector2f vector_value;
					std::vector<std::string> vector_values;
					boost::split(vector_values, value_string, boost::is_any_of(" "));

					if(vector_values.size() < 2)
						continue; // warning message

					vector_value.x = boost::lexical_cast<float>(vector_values[0]);
					vector_value.y = boost::lexical_cast<float>(vector_values[1]);
					AttrPtr new_attr(new BaseGameFeatures::Attribute(rtti, name));
					new_attr->SetValue<sf::Vector2f>(vector_value);
					entity_template->AddAttribute(new_attr);
				}

				// Vector (int)
				else if(type_string.compare("vectori") == 0)
				{
					sf::Vector2i vector_value;
					std::vector<std::string> vector_values;
					boost::split(vector_values, value_string, boost::is_any_of(" "));

					if(vector_values.size() < 2)
						continue; // warning message

					vector_value.x = boost::lexical_cast<boost::int32_t>(vector_values[0]);
					vector_value.y = boost::lexical_cast<boost::int32_t>(vector_values[1]);
					AttrPtr new_attr(new BaseGameFeatures::Attribute(rtti, name));
					new_attr->SetValue<sf::Vector2i>(vector_value);
					entity_template->AddAttribute(new_attr);
				}

				// Vector (uint)
				else if(type_string.compare("vectoru") == 0)
				{
					sf::Vector2u vector_value;
					std::vector<std::string> vector_values;
					boost::split(vector_values, value_string, boost::is_any_of(" "));

					if(vector_values.size() < 2)
						continue; // warning message

					vector_value.x = boost::lexical_cast<boost::uint32_t>(vector_values[0]);
					vector_value.y = boost::lexical_cast<boost::uint32_t>(vector_values[1]);
					AttrPtr new_attr(new BaseGameFeatures::Attribute(rtti, name));
					new_attr->SetValue<sf::Vector2u>(vector_value);
					entity_template->AddAttribute(new_attr);
				}

				// ************************************************* //

			}
			else if( entity_children[j]->GetName() == "Property" )
			{
				std::string property_name = entity_children[j]->GetValue("name");
				std::size_t number_of_properties = m_property_templates.size();
				for(unsigned int i = 0; i < number_of_properties; i++)
				{
					if(m_property_templates[i]->GetName() == property_name)
					{
						BaseGameFeatures::Property* add_property = NULL;
						memcpy(add_property, m_property_templates[i], sizeof(1)); // FIX
						entity_template->AddProperty(PropertyPtr());
						break;
					}
				}
			}
		}
    }
}

//==============================================================================

void FactoryManager::LoadAssetBlueprint( std::string _path )
{
	// Load XML data
	m_xml_parser.LoadXML(_path);
	Data::XMLContainer* xml_data = m_xml_parser.GetXMLData();

	// Find all entity tags
	std::vector<Data::XMLContainer*> asset_tags;
	xml_data->FindAllTags("Asset", asset_tags);

	std::size_t tags = asset_tags.size();
	for(unsigned int i = 0; i < tags; i++)
	{
		if(asset_tags[i]->GetValue("type").compare("sprite") == 0)
		{
			std::string texture_path = asset_tags[i]->GetValue("src");
			boost::uint32_t asset_group = boost::lexical_cast<boost::uint32_t>( asset_tags[i]->GetValue("group") );
			m_asset_templates.push_back( BaseGameFeatures::AssetTemplate(BaseGameFeatures::AssetSprite, texture_path, asset_group) );
		}
	}

	// Tell asset manager to load default group
	Managers::AssetManager::Instance()->LoadAssets(0, false);
}

//==============================================================================

}
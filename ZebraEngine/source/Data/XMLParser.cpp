/**
* XMLParser for entity creation.
*
* @file XMLParser.cpp
* @author Sebastian Salonen
* @date 20111115 - Initial Release
*/

#include "../../includes/Data/XMLParser.h"
#include <iostream>
#include <fstream>


namespace Data
{

//==============================================================================

XMLParser::XMLParser()
    : m_current_container(&m_xml_data)
{
	//Empty
}

//==============================================================================

XMLParser::~XMLParser()
{
	//Empty
}

//==============================================================================

bool XMLParser::LoadXML(std::string _filepath)
{
    // Load file
    std::ifstream xml_file( _filepath.c_str() );
    if( !xml_file.is_open() )
    {
		std::cout << "Couldn't open XML file!" << std::endl;
		return false;
    }
    
    // Prepare variables needed
    int  stack			= 0; 
    bool open_tag 		= false;
    bool open_value		= false;
	bool open_tag_value	= false;
    std::string line  	= "";
    std::string cache 	= "";
    std::string var 	= "";
    CurrentParseType current_type = HEAD;
    
    // Parse the file
    while( xml_file.good() )
    {
		getline(xml_file, line);
		for( unsigned int i = 0; i < line.length(); i++ )
		{
			// End of object
			if( current_type == END )
			{
				unsigned int j = i;
				for( ; j < line.length(); j++ )
				{
					if( line.compare(j,1,">") == 0 )
					{
						stack--;
						open_tag = false;
						XMLContainer* old_container = m_current_container->GetParent();
						m_current_container = old_container;
						break;
					}
				}
				i = j;
				current_type = HEAD;
				continue;
			}
		    
			// Start tag
			if( line.compare(i,1,"<") == 0 )
			{
				open_tag_value = false;

				if( line.compare((i+1),1,"/") == 0 )
					continue;

				stack++;
				open_tag = true;
				this->ProcessCache(cache, var, current_type);
				current_type = HEAD;
				continue;
			}
		    
			// End tag
			if( line.compare(i,1,">") == 0 )
			{
				if( open_tag )
					open_tag_value = true;

				open_tag = false;
				this->ProcessCache(cache, var, current_type);
				current_type = TAGVALUE;
				continue;
			}
		    
			// No open object
			if( stack < 1 )
				continue;
		    
			// Prepare to set variable
			if( line.compare(i,1,"=") == 0 )
			{
				this->ProcessCache(cache, var, current_type);
				current_type = VALUE;
				continue;
			}

			// Start reading value
			if( line.compare(i,1,"\"") == 0 )
			{
				open_value = !open_value;
				continue;
			}

			// Start ending object
			if( line.compare(i,1,"/") == 0 )
			{
				this->ProcessCache(cache, var, current_type);
				current_type = END;
				continue;
			}
		    
			// Next element
			if( line.compare(i,1," ") == 0 && !open_tag_value && !open_value )
			{
				this->ProcessCache(cache, var, current_type);
				continue;
			}

			// Ignore tabs
			if( line.compare(i,1,"	") == 0 )
				continue;

			// Add to cache
			cache += line[i];
		}
    }
    xml_file.close();

	return true;
}

//==============================================================================


void XMLParser::ProcessCache(std::string& cache, std::string& var, CurrentParseType& current_type )
{
    if( !cache.empty() && cache.compare(0,1, "") != 0 )
    {
		switch( current_type )
		{
			case HEAD:
			{
				XMLContainer* child = m_current_container->AddChild(cache);
				child->SetParent(m_current_container);
				m_current_container = child;
				current_type = VAR;
				break;
			}
			case VAR:
			{
				var = cache;
				break;
			}
			case VALUE:
			{
				m_current_container->AddValue(var, cache);
				current_type = VAR;
				break;
			}
			case TAGVALUE:
			{
				m_current_container->AddTagValue(cache);
				break;
			}
			default:
			{
				break;
			}
		}
		
		cache.clear();
    }
}

//==============================================================================

XMLContainer* XMLParser::GetXMLData()
{
	return &m_xml_data;
}

//==============================================================================

}
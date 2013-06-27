/**
* XMLWriter for writing entities/level to xml file.
*
* @file XMLWriter.cpp
* @author Sebastian Salonen
* @date 20121217 - Initial Release
*/

#include "../../includes/Data/XMLWriter.h"
#include <iostream>
#include <fstream>


namespace Data
{

//==============================================================================

XMLWriter::XMLWriter()
	: m_tab_count(0)
{
	//Empty
}

//==============================================================================

XMLWriter::~XMLWriter()
{
	//Empty
}

//==============================================================================

bool XMLWriter::WriteXMLFile(XMLContainer* _data)
{
	std::string xml_string;
	this->CreateXMLString(_data, xml_string);
	return true;
}

//==============================================================================

void XMLWriter::CreateXMLString(XMLContainer* _data, std::string& _xml_string)
{
	bool has_tag_value = (_data->GetTagValue().compare("") == 0);
	bool has_children = !_data->GetChildren().empty();

	// Process Start Tag
	_xml_string = "<";
	_xml_string.append(_data->GetName());

	std::map<std::string, std::string>::iterator iter;
	std::map<std::string, std::string>& values = _data->GetValues();
	for(iter = values.begin(); iter != values.end() ; ++iter)
	{
		_xml_string.append(" "   + iter->first);
		_xml_string.append("=\"" + iter->second + "\"");
	}

	if(has_children || has_tag_value)
		_xml_string.append(">");
	else
	{
		_xml_string.append("/>");
		return;
	}
	
	// Process Tag Content
	if(has_tag_value)
		_xml_string.append(_data->GetTagValue());
	else
	{
		m_tab_count++;

		_xml_string.append("\n");
		for(int i = 0; i < m_tab_count; i++)
			_xml_string.append("\t");

		std::vector<XMLContainer*>& children = _data->GetChildren();
		std::size_t children_count = children.size();
		for(int i = 0; i < children_count; i++)
		{
			CreateXMLString(children[i], _xml_string);
		}

		m_tab_count--;
	}

	// Process End Tag
	if(!has_tag_value)
	{
		_xml_string.append("\n");
		for(int i = 0; i < m_tab_count; i++)
			_xml_string.append("\t");
	}

	_xml_string = "</";
	_xml_string.append(_data->GetName());
	_xml_string.append(">");
}

//==============================================================================

XMLContainer* XMLWriter::GetXMLData()
{
	return &m_xml_data;
}

//==============================================================================

}
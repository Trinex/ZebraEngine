/**
* XMLContainer contains parsed XML data.
*
* @file XMLContainer.h
* @author Sebastian Salonen
* @date 20111116 - Initial Release
*/
#ifndef XMLCONTAINER_H
#define XMLCONTAINER_H

#include <vector>
#include <map>
#include <string>


namespace Data
{

//==============================================================================

	class XMLContainer
	{
	private:
		// XMLContainer vars
		std::string					m_name;
		XMLContainer*					m_parent;
		std::vector<XMLContainer*>			m_children;
		std::map<std::string, std::string>		m_values;
		std::string					m_tag_value;

	public:
		// Constructors/Destructor
		XMLContainer();
		XMLContainer(std::string);
		~XMLContainer();

		// Set/Add functions
		void						SetParent(XMLContainer*);
		void						AddValue(std::string, std::string);
		void						AddTagValue(std::string);
		XMLContainer*					AddChild(std::string);

		// Get functions
		std::string&					GetName();
		XMLContainer*					GetParent();
		std::vector<XMLContainer*>&			GetChildren();
		std::map<std::string, std::string>&		GetValues();
		std::string&					GetTagValue();
		std::string					GetValue(const std::string& _key);

		// Find functions
		bool						FindTag(const std::string& _name, XMLContainer*& _tag);
		bool						FindTagRecursive(const std::string& _name, XMLContainer*& _tag);
		bool						FindTagByValue(const std::string& _name, const std::string& _key, const std::string& _value, XMLContainer*& _tag);
		bool						FindAllTags(const std::string& _name, std::vector<XMLContainer*>& _tags);
		bool						FindAllTagsRecursive(const std::string& _name, std::vector<XMLContainer*>& _tags);
	};

//==============================================================================

}

#endif
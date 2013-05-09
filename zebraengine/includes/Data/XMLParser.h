/**
* XMLParser for entity creation and more.
*
* @file XMLParser.h
* @author Sebastian Salonen
* @date 20111115 - Initial Release
*/
#ifndef XMLPARSER_H
#define XMLPARSER_H

#include "XMLContainer.h"


namespace Data
{

//==============================================================================

    enum CurrentParseType
    {
		HEAD,
		VAR,
		VALUE,
		TAGVALUE,
		END
    };
    
//==============================================================================

    class XMLParser
    {
    private:
		XMLContainer			m_xml_data;
		XMLContainer*			m_current_container;

    public:
		XMLParser();
		~XMLParser();

		bool					LoadXML(std::string);
		void 					ProcessCache(std::string&, std::string&, CurrentParseType&);
		XMLContainer*			GetXMLData();
    };

//==============================================================================

}

#endif
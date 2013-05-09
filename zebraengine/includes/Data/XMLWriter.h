/**
* XMLWriter for entity creation and more.
*
* @file XMLWriter.h
* @author Sebastian Salonen
* @date 20130216 - Initial Release
*/
#ifndef XMLWRITER_H
#define XMLWRITER_H

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

	class XMLWriter
	{
	private:
		XMLContainer			m_xml_data;
		XMLContainer*			m_current_container;
		int						m_tab_count;

	public:
		XMLWriter();
		~XMLWriter();

		bool					WriteXMLFile(XMLContainer*);
		void 					CreateXMLString(XMLContainer*, std::string&);
		XMLContainer*			GetXMLData();
	};

	//==============================================================================

}

#endif
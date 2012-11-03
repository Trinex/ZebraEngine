/**
* My Game World
*
* @file MyWorld.h
* @author Sebastian Salonen
* @date 20110928 - Initial Release
*/
#ifndef MYWORLD_H
#define MYWORLD_H

#include "Core.h"
#include "Data/XMLParser.h"


namespace MyGame
{

//==============================================================================
	
	class MyWorld : public Core::GameWorld
	{
	private:
		Data::XMLParser				xml_parser;
		
	public:
		MyWorld();
		~MyWorld();

		// Register
		void						RegisterProperties();
		void						RegisterEvents();
		
		// Routine
		void						Update();
		void						InitGameWorld();
		void						CleanGameWorld();
	};
	
//==============================================================================

}

#endif
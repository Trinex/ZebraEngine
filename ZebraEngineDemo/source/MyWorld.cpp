/**
* My Game World
*
* @file MyWorld.h
* @author Sebastian Salonen
* @date 20110928 - Initial Release
*/

#include "../include/MyWorld.h"


namespace MyGame
{

//==============================================================================

MyWorld::MyWorld()
{
	// Empty
}

//==============================================================================	

MyWorld::~MyWorld()
{
	// Empty
}

//==============================================================================

void MyWorld::Update()
{
	// UPDATE STUFF HERE
	
	GameWorld::Update();
}

//==============================================================================

void MyWorld::InitGameWorld()
{
	// INIT STUFF HERE
	
	xml_parser.LoadXML("D:/Seb/Programming/Projects/Zebra Engine/Zebra Engine/data.xml");
	GameWorld::InitGameWorld();
}

//==============================================================================

void MyWorld::CleanGameWorld()
{
	// CLEAN STUFF HERE
	
	GameWorld::CleanGameWorld();
}

//==============================================================================

void MyWorld::RegisterProperties()
{
	// REGISTER CUSTOM PROPERTIES HERE

	GameWorld::RegisterProperties();
}

//==============================================================================

void MyWorld::RegisterEvents()
{
	// REGISTER CUSTOM EVENTS HERE

	GameWorld::RegisterEvents();
}

//==============================================================================
	
}
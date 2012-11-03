/**
* This is MAIN!
*
* @author Sebastian Salonen
* @date 20110629 - Initial Release
*/
#include "Core.h"
#include "include/MyWorld.h"

//==============================================================================

int main()
{
	Core::GameWorld* my_world = new MyGame::MyWorld();
    Core::ZebraApplication app("My Game - Zebra Application", my_world);
    return app.Execute();
}

//==============================================================================
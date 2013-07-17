/**
* Asset Manager Class.
*
* @file AssetManager.cpp
* @author Sebastian Salonen
* @date 20130630 - Initial Release
*/

#include "../../includes/Managers/AssetManager.h"


namespace Managers
{
  
//==============================================================================

AssetManager* AssetManager::mp_instance = NULL;

//==============================================================================

AssetManager::AssetManager()
	: mp_app(NULL), m_id_count(0)
{
	//Empty
}

//==============================================================================

AssetManager::~AssetManager()
{
	//Empty
}

//==============================================================================

AssetManager* AssetManager::Instance()
{
    if(mp_instance == NULL)
		mp_instance = new AssetManager();
    
    return mp_instance;
}

//==============================================================================

void AssetManager::RegisterApplication(Core::ZebraApplication* _app)
{
    mp_app = _app;
}

//==============================================================================

}
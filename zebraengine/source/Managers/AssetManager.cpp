/**
* Asset Manager Class.
*
* @file AssetManager.cpp
* @author Sebastian Salonen
* @date 20130630 - Initial Release
*/

#include "../../includes/Managers/AssetManager.h"
#include "../../includes/Managers/FactoryManager.h"

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

void AssetManager::LoadAssets(unsigned int _group, bool _background_flag)
{
	//if(_background_flag)
	//	m_background_loading = true;

	std::vector<BaseGameFeatures::AssetTemplate> assets_to_load;
	std::vector<BaseGameFeatures::AssetTemplate>& asset_templates = Managers::FactoryManager::Instance()->GetAssetTemplates();

	for(unsigned int i = 0; i < asset_templates.size(); i++)
	{
		if(asset_templates[i].asset_group == _group)
			assets_to_load.push_back( asset_templates[i] );
	}

	for(unsigned int i = 0; i < assets_to_load.size(); i++)
	{
		switch (assets_to_load[i].asset_type)
		{
			case BaseGameFeatures::AssetSprite:
			{
				BaseGameFeatures::SpritePtr sprite_ptr( new BaseGameFeatures::SpriteAsset(assets_to_load[i].asset_path) );
				m_sprites.push_back( sprite_ptr );
				break;
			}
			default:
				break;
		}
	}
}

//==============================================================================

}
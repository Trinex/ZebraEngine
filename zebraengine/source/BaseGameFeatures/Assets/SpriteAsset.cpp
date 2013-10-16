/**
* SpriteAsset for nice graphics
*
* @file SpriteAsset.cpp
* @author Sebastian Salonen
* @date 20130501 - Initial Release
*/

#include "../../../includes/BaseGameFeatures/Assets/SpriteAsset.h"


namespace BaseGameFeatures
{

	//==============================================================================

	SpriteAsset::SpriteAsset(const std::string _filename)
		: BaseGameAsset(_filename, AssetSprite)
	{
		// Empty
	}

	//==============================================================================

	bool SpriteAsset::LoadAsset()
	{
		bool loaded = m_texture.loadFromFile(m_filename);
		if(loaded)
			m_sprite.setTexture(m_texture);
		return loaded;
	}

	//==============================================================================

	bool SpriteAsset::UnloadAsset()
	{
		// TODO
		return true;
	}

	//==============================================================================

	sf::Sprite* SpriteAsset::GetSprite()
	{
		return &m_sprite;
	}

	//==============================================================================

}
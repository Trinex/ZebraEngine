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

	void SpriteAsset::LoadAsset()
	{
		m_texture.loadFromFile(m_filename);
		m_sprite.setTexture(m_texture);
	}

	//==============================================================================

	sf::Sprite* SpriteAsset::GetSprite()
	{
		return &m_sprite;
	}

	//==============================================================================

}
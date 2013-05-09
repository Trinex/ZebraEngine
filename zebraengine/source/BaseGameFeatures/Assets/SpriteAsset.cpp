/**
* SpriteAsset for nice graphics
*
* @file SpriteAsset.cpp
* @author Sebastian Salonen
* @date 20130501 - Initial Release
*/

#include "../../../includes/BaseGameFeatures/Assets/SpriteAsset.h"


namespace BaseGameFeature
{

	//==============================================================================

	SpriteAsset::SpriteAsset(const std::string _filename)
		: BaseGameAsset(_filename)
	{
		//m_filename = _filename
	}

	//==============================================================================

	sf::Sprite* SpriteAsset::GetSprite()
	{
		return &m_sprite;
	}

	//==============================================================================

}
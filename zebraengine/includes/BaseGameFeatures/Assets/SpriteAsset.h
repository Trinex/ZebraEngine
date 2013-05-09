/**
* Sprite Asset
*
* @file SpriteAsset.h
* @author Sebastian Salonen
* @date 20130501 - Initial Release
*/
#ifndef SPRITEASSET_H
#define SPRITEASSET_H

#include <assert.h>
#include <string>
#include "../Asset.h"


namespace BaseGameFeature
{

	//==============================================================================

	class SpriteAsset : public BaseGameFeature::BaseGameAsset
	{
	private:
		sf::Texture										m_texture;
		sf::Sprite										m_sprite;

		SpriteAsset(const SpriteAsset&);
		SpriteAsset& operator=(const SpriteAsset&);

	public:
		SpriteAsset(std::string _filename);
		virtual ~SpriteAsset();

		sf::Sprite*										GetSprite();
	};

	//==============================================================================

}

#endif
/**
* SpriteAsset for nice graphics
*
* @file SpriteAsset.cpp
* @author Sebastian Salonen
* @date 20130501 - Initial Release
*/

#include "../../includes/BaseGameFeatures/Asset.h"


namespace BaseGameFeature
{

	BaseGameAsset::BaseGameAsset()
	{


	}

	//==============================================================================

	BaseGameAsset::BaseGameAsset(const std::string _filename, AssetType _type)
		: m_filename(_filename), m_asset_type(_type)
	{
		//m_filename = _filename
	}

	//==============================================================================

}
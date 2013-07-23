/**
* Base Class for Assets.
*
* @file BaseGameAsset.h
* @author Sebastian Salonen
* @date 20110615 - Initial Release
*/
#ifndef BASEGAMEASSET_H
#define BASEGAMEASSET_H

#include <assert.h>
#include <string>
#include "../Core.h"


namespace BaseGameFeatures
{

//==============================================================================

	enum AssetType 
	{
		FirstStandardAsset  = 0,  ///< First Standard Asset Type Value
		AssetSprite			= 1,
		LastStandardAsset,        ///< Last Standard Asset Type Value

		// The following can be used for custom assets
		FirstCustomAsset    = 10, ///< First Custom Asset Type value
		AssetCustom1        = 11, ///< Custom Asset Type 1
		AssetCustom2        = 12, ///< Custom Asset Type 2
		AssetCustom3        = 13, ///< Custom Asset Type 3
		AssetCustom4        = 14, ///< Custom Asset Type 4
		AssetCustom5        = 15, ///< Custom Asset Type 5
		LastCustomAsset,          ///< Last Custom Asset Type Value
	};

//==============================================================================

	class BaseGameAsset
	{
	private:
	    BaseGameAsset(const BaseGameAsset&);
		BaseGameAsset& operator=(const BaseGameAsset&);

	protected:
		id_t							m_id;
		std::string						m_name;
		AssetType						m_asset_type;
		int								m_references;
		Core::ZebraApplication*			mp_app;
		const std::string				m_filename;
		bool							m_loaded;

	public:
		BaseGameAsset();
		BaseGameAsset(const std::string _filename, AssetType _type);
		virtual ~BaseGameAsset();

		void							RegisterApp(Core::ZebraApplication* _app);
		bool							IsLoaded() const;
		void							AddReference();
		const int						GetReferences() const;
		void							DropReference(bool _remove_flag = true);
		virtual bool					LoadAsset()=0;
		virtual bool					UnloadAsset()=0; // if public, it has to be handled.


	};

//==============================================================================

	struct AssetTemplate
	{
		AssetTemplate(AssetType _type, std::string _path, unsigned int _group) 
			: asset_type(_type), asset_path(_path), asset_group(_group) 
		{ 
			/*Empty*/ 
		}

		AssetType asset_type;
		std::string asset_path;
		unsigned int asset_group;
	};

//==============================================================================

}

#endif
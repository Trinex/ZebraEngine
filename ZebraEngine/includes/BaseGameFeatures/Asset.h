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


namespace BaseGameFeature
{

//==============================================================================

	template<class TYPE>
	class BaseGameAsset
	{
	private:
		// number of references to this asset
		int								m_references;

	    BaseGameAsset(const BaseGameAsset&);
		BaseGameAsset& operator=(const BaseGameAsset&);

	protected:
		Core::ZebraApplication*			mp_app;
		const std::string				m_filename;
		Core::AssetLoadingStyle			m_loading_style;
		TYPE*							m_asset;
		bool							m_loaded;

		virtual void					UnloadAsset()=0;

	public:
		BaseGameAsset(std::string _filename, Core::AssetLoadingStyle _style = AssetLoadStyleBackground);
		virtual ~BaseGameAsset();

		void							RegisterApp(Core::ZebraApplication* _app);
		bool							IsLoaded() const;
		Core::AssetLoadingStyle			GetLoadingStyle() const;
		void							SetLoadingStyle(Core::AssetLoadingStyle _style);
		void							AddReference();
		const int						GetReferences() const;
		void							DropReference(bool _remove_flag = true);
		TYPE*							GetAsset();
		virtual void					LoadAsset()=0;


	};

//==============================================================================

}

#endif
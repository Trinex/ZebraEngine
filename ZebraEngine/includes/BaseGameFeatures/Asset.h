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

	class BaseGameAsset
	{
	private:
	    BaseGameAsset(const BaseGameAsset&);
		BaseGameAsset& operator=(const BaseGameAsset&);

	protected:
		id_t							m_id;
		int								m_references;
		Core::ZebraApplication*			mp_app;
		const std::string				m_filename;
		bool							m_loaded;

		virtual void					UnloadAsset()=0;

	public:
		BaseGameAsset();
		BaseGameAsset(const std::string _filename);
		virtual ~BaseGameAsset();

		void							RegisterApp(Core::ZebraApplication* _app);
		bool							IsLoaded() const;
		void							AddReference();
		const int						GetReferences() const;
		void							DropReference(bool _remove_flag = true);
		virtual void					LoadAsset()=0;


	};

//==============================================================================

}

#endif
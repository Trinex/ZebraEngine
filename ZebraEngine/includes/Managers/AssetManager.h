/**
* Asset Manager Class.
*
* @file AssetManager.h
* @author Sebastian Salonen
* @date 20110615 - Initial Release
*/
#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "../Core.h"


namespace Managers
{

//==============================================================================

	class AssetManager
	{
	private:
		Core::ZebraApplication*                   mp_app;
		bool                                      m_background_loading;
		sf::Thread*                               mp_background_thread;
		sf::Mutex                                 m_background_mutex;
		std::vector<SpriteAsset*>				  m_sprites;
		/*
		std::map<const typeAssetID, ConfigAsset*> m_configs;
		std::map<const typeAssetID, FontAsset*>   m_fonts;
		std::map<const typeAssetID, ImageAsset*>  m_images;
		std::map<const typeAssetID, SoundAsset*>  m_sounds;
		std::map<const typeAssetID, MusicAsset*>  m_music;
		*/

		AssetManager(const AssetManager&);
		AssetManager& operator=(const AssetManager&);

		static void BackgroundLoop(void* theAssetManager);
		void DeleteSprites();
		void LoadSprites();
		/*
		void DeleteConfigs(void);
		void LoadConfigs(AssetLoadingStyle theStyle);
		void DeleteFonts(void);
		void LoadFonts(AssetLoadingStyle theStyle);
		void DeleteImages(void);
		void LoadImages(AssetLoadingStyle theStyle);
		void DeleteMusic(void);
		void LoadMusic(AssetLoadingStyle theStyle);
		void DeleteSounds(void);
		void LoadSounds(AssetLoadingStyle theStyle);
		*/

	public:
		AssetManager();
		virtual ~AssetManager();

		void RegisterApp(Core::ZebraApplication* _app);
		void LoadAssetBlueprints(std::string _path, bool _theBackgroundFlag = false);
		bool IsLoading(void);

		bool LoadSpriteAsset(const id_t _id, SpriteAsset* _sprite);
		bool LoadSpriteAsset(const std::string& _name, SpriteAsset* _sprite);
		/*
		ConfigAsset* AddConfig(
			const typeAssetID theAssetID,
			const std::string theFilename = "",
			AssetLoadingStyle theStyle = AssetLoadStyleBackground);

		void UnloadConfig(const typeAssetID theAssetID);
		ConfigAsset* GetConfig(const typeAssetID theAssetID);

		FontAsset* AddFont(
			const typeAssetID theAssetID,
			const std::string theFilename = "",
			AssetLoadingStyle theStyle = AssetLoadStyleBackground);

		void UnloadFont(const typeAssetID theAssetID);
		FontAsset* GetFont(const typeAssetID theAssetID);

		ImageAsset* AddImage(
			const typeAssetID theAssetID,
			const std::string theFilename = "",
			AssetLoadingStyle theStyle = AssetLoadStyleBackground);

		ImageAsset* GetImage(const typeAssetID theAssetID);
		sf::Sprite* GetSprite(const typeAssetID theAssetID);
		void UnloadImage(const typeAssetID theAssetID);

		MusicAsset* AddMusic(
			const typeAssetID theAssetID,
			const std::string theFilename = "",
			AssetLoadingStyle theStyle = AssetLoadStyleBackground);

		MusicAsset* GetMusic(const typeAssetID theAssetID);
		void UnloadMusic(const typeAssetID theAssetID);

		SoundAsset* AddSound(
			const typeAssetID theAssetID,
			const std::string theFilename = "",
			AssetLoadingStyle theStyle = AssetLoadStyleBackground);

		SoundAsset* GetSound(const typeAssetID theAssetID);
		sf::Sound* GetSoundPlayer(const typeAssetID theAssetID);
		void UnloadSound(const typeAssetID theAssetID);
		*/
	};

//==============================================================================

}

#endif
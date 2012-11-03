/**
* Base Class for States.
*
* @file BaseGameState.h
* @author Sebastian Salonen
* @date 20110615 - Initial Release
*/
#ifndef BASEGAMESTATE_H
#define BASEGAMESTATE_H

#include <assert.h>
#include "../Core.h"


namespace BaseGameFeature
{

//==============================================================================

	/// Provides the base class interface for all game states
	class BaseGameState
	{
	private:
		/// The State ID
		const int					m_id;
		/// Boolean that indicates that DoInit has been called
		bool						m_init;
		/// State is currently paused (not active)
		bool						m_paused;
		/// State needs to be cleaned up at the end of the next game loop
		bool						m_cleanup;
		/// Clock will help us keep track of running and paused elapsed time
		sf::Clock					m_elapsed_clock;
		/// Total elapsed time since DoInit was called
		float						m_elapsed_time;
		/// Clock will help us keep track of time paused
		sf::Clock					m_paused_clock;
		/// Total elapsed time paused since DoInit was called
		float						m_paused_time;

		BaseGameState(const BaseGameState&);
		BaseGameState& operator=(const BaseGameState&);

	protected:
		BaseGameState(const int _id, Core::ZebraApplication* _app);

		/// Pointer to the App class
		Core::ZebraApplication*		mp_app;
		virtual void				Cleanup();

	public:
 
		virtual ~BaseGameState();
 
		const int					GetID() const;
		virtual void				DoInit();
		virtual void				ReInit()=0;
		void						DeInit();
		bool						IsInitComplete();
		bool						IsPaused();
		virtual void				Pause();
		virtual void				Resume();

		virtual void				HandleEvents(sf::Event _event)=0;
		virtual void				Update()=0;
		virtual void				Draw()=0;
 
		void						HandleCleanup();

		/**
		 * GetElapsedTime will return one of the following:
		 * 1) If this state is not paused: total elapsed time since DoInit was called
		 * 2) If this state is paused: total elapsed time since Pause was called
		 * 3) If this state is not initialized: total elapsed time from DoInit to DeInit
		 * @return total elapsed time as described above.
		 */
		float						GetElapsedTime() const;
  };

//==============================================================================

};

#endif // BASEGAMESTATE_H
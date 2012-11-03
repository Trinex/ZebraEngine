#ifndef CONFIG_H
#define CONFIG_H

// if running windows, include sfml lib & box2d lib
#if defined _WIN32 || _WIN64

	#if defined _DEBUG
		#pragma comment(lib,"glu32.lib")
		#pragma comment(lib,"opengl32.lib")
		#pragma comment(lib,"sfml-system-s-d.lib")
		#pragma comment(lib,"sfml-window-s-d.lib")
		#pragma comment(lib,"sfml-graphics-s-d.lib")
	#else
		#pragma comment(lib,"glu32.lib")
		#pragma comment(lib,"opengl32.lib")
		#pragma comment(lib,"sfml-system-s.lib")
		#pragma comment(lib,"sfml-window-s.lib")
		#pragma comment(lib,"sfml-graphics-s.lib")
	#endif
	
	#if defined _DEBUG
		#pragma comment(lib,"Box2D-d.lib")
	#else
		#pragma comment(lib,"Box2D.lib")
	#endif
#endif

#endif
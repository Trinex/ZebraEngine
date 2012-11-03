#########################################################################
#cmake version required
cmake_minimum_required(VERSION 2.6)

#project information
set(project_name ZebraEngine)
set(ZebraEngine_VERSION_MAJOR 0)
set(ZebraEngine_VERSION_MINOR 1)
get_filename_component(parent_dir CMAKE_CURRENT_SOURCE_DIR PATH)

#project name
project(${project_name})

#########################################################################

#dependencies unix
if(UNIX)
	include_directories(/usr/local/include/ /usr/local/include/Box2D/)
	link_directories(/usr/local/lib/ /usr/lib/)
endif(UNIX)

#dependencies windows
if(WIN32)
	include_directories(${parent_dir}/include/)
	link_directories(${parent_dir}/lib/)
endif(WIN32)

#########################################################################

#setting the external libraries unix
if(UNIX)
	set(external_libs libsfml-window.so libsfml-graphics.so libsfml-system.so libXrandr.so libBox2D.a)
endif(UNIX)

#setting the external libraries windows
if(WIN32)
	set(external_libs optimized sfml-window-s.lib debug sfml-window-s-d.lib optimized sfml-graphics-s.lib debug sfml-graphics-s-d.lib optimized sfml-system-s.lib debug sfml-system-s-d.lib optimized Box2D.lib debug Box2D-d.lib)
endif(WIN32)

#########################################################################

#add the .cpp files
FILE(GLOB main "*.cpp")
FILE(GLOB_RECURSE includes "includes/*.h")
FILE(GLOB_RECURSE sources "source/*.cpp")

#------ Directory Fix (for retard MVS) ------#
if(WIN32)
	# Base Game Features
	FILE(GLOB BaseGameFeatures_H "includes/BaseGameFeatures/*.h")
	SOURCE_GROUP("Header Files\\BaseGameFeatures" FILES ${BaseGameFeatures_H})
	FILE(GLOB BaseGameFeatures_S "source/BaseGameFeatures/*.cpp")
	SOURCE_GROUP("Source Files\\BaseGameFeatures" FILES ${BaseGameFeatures_S})
	
		# Properties
		FILE(GLOB Properties_H "includes/BaseGameFeatures/Properties/*.h")
		SOURCE_GROUP("Header Files\\BaseGameFeatures\\Properties" FILES ${Properties_H})
		FILE(GLOB Properties_S "source/BaseGameFeatures/Properties/*.cpp")
		SOURCE_GROUP("Source Files\\BaseGameFeatures\\Properties" FILES ${Properties_S})

	# Core
	FILE(GLOB Core_H "includes/Core/*.h")
	SOURCE_GROUP("Header Files\\Core" FILES ${Core_H})
	FILE(GLOB Core_S "source/Core/*.cpp")
	SOURCE_GROUP("Source Files\\Core" FILES ${Core_S})

	# Data
	FILE(GLOB Data_H "includes/Data/*.h")
	SOURCE_GROUP("Header Files\\Data" FILES ${Data_H})
	FILE(GLOB Data_S "source/Data/*.cpp")
	SOURCE_GROUP("Source Files\\Data" FILES ${Data_S})

	# Graphics
	FILE(GLOB Graphics_H "includes/Graphics/*.h")
	SOURCE_GROUP("Header Files\\Graphics" FILES ${Graphics_H})
	FILE(GLOB Graphics_S "source/Graphics/*.cpp")
	SOURCE_GROUP("Source Files\\Graphics" FILES ${Graphics_S})

	# Managers
	FILE(GLOB Managers_H "includes/Managers/*.h")
	SOURCE_GROUP("Header Files\\Managers" FILES ${Managers_H})
	FILE(GLOB Managers_S "source/Managers/*.cpp")
	SOURCE_GROUP("Source Files\\Managers" FILES ${Managers_S})

	# Physics
	FILE(GLOB Physics_H "includes/Physics/*.h")
	SOURCE_GROUP("Header Files\\Physics" FILES ${Physics_H})
	FILE(GLOB Physics_S "source/Physics/*.cpp")
	SOURCE_GROUP("Source Files\\Physics" FILES ${Physics_S})
endif(WIN32)
#---------------------------#

#adding the project's exe
add_definitions( -DSFML_STATIC )
add_library(${project_name} ${main} ${sources} ${includes} )

#########################################################################

#linking in libraries from other sources
#foreach(lib ${${project_name}_external_libs})
target_link_libraries(${project_name} ${external_libs})
#endforeach()

#########################################################################
#########################################################################
#cmake version required
cmake_minimum_required(VERSION 2.6)

#project information
set(project_name ZebraEngineDemo)
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
	set(external_libs optimized ZebraEngine.lib debug ZebraEngine.lib)
endif(WIN32)

#########################################################################

#add the .cpp files
FILE(GLOB main "*.cpp")
FILE(GLOB_RECURSE includes "include/*.h")
FILE(GLOB_RECURSE sources "source/*.cpp")

#adding the project's exe
add_executable(${project_name} ${main} ${sources} ${includes} )

#########################################################################

#linking in libraries from other sources
#foreach(lib ${${project_name}_external_libs})
target_link_libraries(${project_name} ${external_libs})
#endforeach()

#########################################################################
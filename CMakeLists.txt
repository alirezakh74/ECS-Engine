cmake_minimum_required(VERSION 3.7)

#[[
set( CMAKE_CXX_COMPILER "D:/ModernCpp/Compilers/mingw64/bin" )
set( CMAKE_C_COMPILER "D:/ModernCpp/Compilers/mingw64/bin" )
]]

# set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME "ECS-Engine")
project(ECS-Engine #[[LANGUAGES CXX]])


#find_package(ImGui-SFML REQUIRED)

#set(CMAKE_PREFIX_PATH C:/SFML-2.6.0/)
#set(SFML2_DIR C:/libraries/SFML-2.6.0/lib/cmake/SFML)
#[[find_package(SFML2 REQUIRED)]]

#include_directories(
#     C:/libraries/SFML-2.6.0/include
#     D:/ModernCpp/GameDevs/SFML/ECS-Engine/src/imgui/imgui
#     D:/ModernCpp/GameDevs/SFML/ECS-Engine/src/imgui/imgui-sfml
#)
#link_directories(C:/libraries/SFML-2.6.0/lib)

include_directories(
     ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui
     ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui-sfml
)


#target_include_directories(ECS-Engine
 #                   PUBLIC 
 #                   ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui-sfml
 #                   ${CMAKE_CURRENT_SOURCE_DIR}/include/imgui
 #                   )


# automatically add .h and .cpp files
file(GLOB source_codes
     "*.h"
     "*.cpp"
     "src/*.h"
     "src/*.cpp"
     #"src/imgui/imgui/*.h"
     #"src/imgui/imgui/*.cpp"
     #"src/imgui/imgui-sfml/*.h"
     #"src/imgui/imgui-sfml/*.cpp"
)

add_executable(ECS-Engine main.cpp ${source_codes})
target_link_libraries(ECS-Engine ${SFML2_LIBRARIES} -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio)
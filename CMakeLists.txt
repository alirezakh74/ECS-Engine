cmake_minimum_required(VERSION 3.7)

#[[
set( CMAKE_CXX_COMPILER "D:/ModernCpp/Compilers/mingw64/bin" )
set( CMAKE_C_COMPILER "D:/ModernCpp/Compilers/mingw64/bin" )
]]

# set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

project(ECS-Engine #[[LANGUAGES CXX]])




set(CMAKE_PREFIX_PATH C:/SFML-2.6.0/)
set(SFML2_DIR C:/libraries/SFML-2.6.0/lib/cmake/SFML)
#[[find_package(SFML2 REQUIRED)]]

include_directories(C:/libraries/SFML-2.6.0/include)
link_directories(C:/libraries/SFML-2.6.0/lib)

# automatically add .h and .cpp files
file(GLOB source_codes
     "*.h"
     "*.cpp"
     "src/*.h"
     "src/*.cpp"
)

add_executable(ECS-Engine main.cpp ${source_codes})
target_link_libraries(ECS-Engine ${SFML2_LIBRARIES} -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio)
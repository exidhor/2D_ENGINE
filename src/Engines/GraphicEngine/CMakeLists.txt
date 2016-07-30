# Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-06-18
cmake_minimum_required(VERSION 3.1)

# Setting Flags
# -DMOD_SHARED to build modules dynamic Libraries
# -DENGINE_SHARED to build engines dynamic Libraries
# -DBUILD_MOD to enable the build of modules dll
# -DBUILD_ENGINE  to enable the build of engines dll
set (CMAKE_CXX_FLAGS "-Wall -std=c++11 -g -DENGINE_SHARED -DBUILD_ENGINE -DMOD_SHARED")

# Engine include directory
include_directories(
        "${CMAKE_SOURCE_DIR}/include/Engines/GraphicEngine"
        "${SFML_PATH}/include")

# Setting sources and includes path
set(MODULE_PATH ${CMAKE_SOURCE_DIR}/include/Engines)
set(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/Engines/GraphicEngine)
set(HEADER_PATH ${CMAKE_SOURCE_DIR}/include/Engines/GraphicEngine)

# Setting output libraries directories
# /bin for all .dll
# /lib/Engines for all archive
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/lib/Engines)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Getting dependency
set(SOURCE_FILES
        "${SOURCE_PATH}/Drawable.cpp"
        "${SOURCE_PATH}/Animation.cpp"
        "${SOURCE_PATH}/Engine.cpp"
        "${SOURCE_PATH}/QuadVertices.cpp"
        "${SOURCE_PATH}/RessourceManager.cpp"
        "${SOURCE_PATH}/Sprite.cpp"
        "${SOURCE_PATH}/TextureCharacteristics.cpp"
        "${SOURCE_PATH}/TextureCharacteristicsManager.cpp"
        "${SOURCE_PATH}/TextureVertices.cpp"
        "${SOURCE_PATH}/TileCharacteristics.cpp"
        "${SOURCE_PATH}/Tileset.cpp"
        "${SOURCE_PATH}/TilesetManager.cpp"
        "${SOURCE_PATH}/TilesetDisplayer.cpp")

set(HEADER_FILES
        "${MODULE_PATH}/Config.hpp"
        "${HEADER_PATH}/Drawable.hpp"
        "${HEADER_PATH}/Animation.hpp"
        "${HEADER_PATH}/Engine.hpp"
        "${HEADER_PATH}/QuadVertices.hpp"
        "${HEADER_PATH}/Ressource.hpp"
        "${HEADER_PATH}/RessourceManager.hpp"
        "${HEADER_PATH}/Sprite.hpp"
        "${HEADER_PATH}/TextureCharacteristics.hpp"
        "${HEADER_PATH}/TextureCharacteristicsManager.hpp"
        "${HEADER_PATH}/TextureVertices.hpp"
        "${HEADER_PATH}/TileCharacteristics.hpp"
        "${HEADER_PATH}/Tileset.hpp"
        "${HEADER_PATH}/TilesetManager.hpp"
        "${HEADER_PATH}/TilesetDisplayer.hpp")

# Creating the shared library
add_library(graphic SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(graphic
        "${SFML_PATH}/lib/libsfml-graphics-d.a"
        "${SFML_PATH}/lib/libsfml-window-d.a"
        "${SFML_PATH}/lib/libsfml-system-d.a"
        "${CMAKE_SOURCE_DIR}/lib/Modules/libmod-utils.dll.a")
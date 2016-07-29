# Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-06-18
cmake_minimum_required(VERSION 3.1)

# Setting Flags
# -DMOD_SHARED to build modules dynamic Libraries
# -DENGINE_SHARED to build engines dynamic Libraries
# -DBUILD_MOD to enable the build of modules dll
# -DBUILD_ENGINE  to enable the build of engines dll
set (CMAKE_CXX_FLAGS "-Wall -std=c++11 -pthread -g -DENGINE_SHARED -DMOD_SHARED")

# Engine include directory
include_directories(
        "${CMAKE_SOURCE_DIR}/include/Engines/GameEngine"
        "${SFML_PATH}/include")

# Setting sources and includes path
set(MODULE_PATH ${CMAKE_SOURCE_DIR}/include/Engines)
set(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/Engines/GameEngine)
set(HEADER_PATH ${CMAKE_SOURCE_DIR}/include/Engines/GameEngine)

# Bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Getting dependency
set(SOURCE_FILES
        "${SOURCE_PATH}/GameEngine.cpp"
        "${SOURCE_PATH}/Main.cpp")

set(HEADER_FILES
        "${HEADER_PATH}/GameEngine.hpp"
        "${HEADER_PATH}/Object.hpp")

# Creating executable
add_executable(game ${SOURCE_FILES} ${HEADER_FILES})

# Linking engines
target_link_libraries(game
        "-lpthread"
        "${CMAKE_SOURCE_DIR}/lib/Engines/libgraphic.dll.a"
        "${CMAKE_SOURCE_DIR}/lib/Engines/libphysic.dll.a")


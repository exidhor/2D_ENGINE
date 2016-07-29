# Windfall Engine project
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
include_directories("${CMAKE_SOURCE_DIR}/include/Engines/PhysicEngine")

# Setting sources and includes path
set(MODULE_PATH ${CMAKE_SOURCE_DIR}/include/Engines)
set(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/Engines/PhysicEngine)
set(HEADER_PATH ${CMAKE_SOURCE_DIR}/include/Engines/PhysicEngine)

# Setting output libraries directories
# /bin for all .dll
# /lib/Engines for all archive
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/lib/Engines)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Getting dependency
set(SOURCE_FILES
        "${SOURCE_PATH}/CollisionBox.cpp"
        "${SOURCE_PATH}/PhysicEngine.cpp"

        "${SOURCE_PATH}/Geometry/Point.cpp"
        "${SOURCE_PATH}/Geometry/Rectangle.cpp"
        "${SOURCE_PATH}/Geometry/Shape.cpp"
        "${SOURCE_PATH}/Geometry/Size.cpp")

set(HEADER_FILES
        "${MODULE_PATH}/Config.hpp"
        "${HEADER_PATH}/CollisionBox.hpp"
        "${HEADER_PATH}/PhysicEngine.hpp"

        "${HEADER_PATH}/Geometry/Point.hpp"
        "${HEADER_PATH}/Geometry/Rectangle.hpp"
        "${HEADER_PATH}/Geometry/Shape.hpp"
        "${HEADER_PATH}/Geometry/Size.hpp")

# Creating the shared library
add_library(physic SHARED ${SOURCE_FILES} ${HEADER_FILES})
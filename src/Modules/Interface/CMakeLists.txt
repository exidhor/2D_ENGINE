# Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-06-18
cmake_minimum_required(VERSION 3.1)

# Setting Flags
# -DMOD_SHARED to build modules dynamic Libraries
# -DENGINE_SHARED to build engines dynamic Libraries
# -DBUILD_MOD to enable the build of modules dll
# -DBUILD_ENGINE  to enable the build of engines dll
set (CMAKE_CXX_FLAGS "-Wall -std=c++11 -g -DMOD_SHARED -DBUILD_MOD")

# Interface include directory
include_directories(${CMAKE_SOURCE_DIR}/include/Modules/Interface)

# Setting sources and includes path
set(MODULE_PATH ${CMAKE_SOURCE_DIR}/include/Modules)
set(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/Modules/Interface)
set(HEADER_PATH ${CMAKE_SOURCE_DIR}/include/Modules/Interface)

# Setting output libraries directories
# /bin for all .dll
# /lib/Modules for all archive
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/lib/Modules)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Getting dependency
set(SOURCE_FILES
        "${SOURCE_PATH}/Drawable.cpp")

set(HEADER_FILES
        "${HEADER_PATH}/Interface.hpp"
        "${HEADER_PATH}/Drawable.hpp"
        "${MODULE_PATH}/ModConfig.hpp")

# Creating the shared library
add_library(mod-gui SHARED ${SOURCE_FILES} ${HEADER_FILES})



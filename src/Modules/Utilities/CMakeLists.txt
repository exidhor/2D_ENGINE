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

# Utilities include directory
include_directories(${CMAKE_SOURCE_DIR}/include/Modules/Utilities)

# Setting sources and includes path
set(MODULE_PATH ${CMAKE_SOURCE_DIR}/include/Modules)
set(SOURCE_PATH ${CMAKE_SOURCE_DIR}/src/Modules/Utilities)
set(HEADER_PATH ${CMAKE_SOURCE_DIR}/include/Modules/Utilities)

# Setting output libraries directories
# /bin for all .dll
# /lib/Modules for all archive
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/lib/Modules)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Getting dependency
set(SOURCE_FILES
        "${SOURCE_PATH}/HashTable.cpp"
        "${SOURCE_PATH}/AssociativeArray.cpp"
        "${SOURCE_PATH}/Timer.cpp"
        "${SOURCE_PATH}/MemoryGestion/PoolAllocator.cpp"
        "${SOURCE_PATH}/MemoryGestion/MemoryManager.cpp"
        "${SOURCE_PATH}/MemoryGestion/StaticMemoryAllocator.cpp")

set(HEADER_FILES
        "${MODULE_PATH}/ModConfig.hpp"
        "${HEADER_PATH}/Utilities.hpp"
        "${HEADER_PATH}/HashTable.hpp"
        "${HEADER_PATH}/AssociativeArray.hpp"
        "${HEADER_PATH}/Vector2.hpp"
        "${HEADER_PATH}/Timer.hpp"
        "${HEADER_PATH}/MemoryGestion/PoolAllocator.hpp"
        "${HEADER_PATH}/MemoryGestion/MemoryManager.hpp"
        "${HEADER_PATH}/MemoryGestion/StaticMemoryAllocator.hpp")

# Creating the shared library
add_library(mod-utils SHARED ${SOURCE_FILES} ${HEADER_FILES})
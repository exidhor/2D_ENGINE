# Windfall Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-06-18
cmake_minimum_required(VERSION 3.1)

# The version number.
set(ENGINE_VERSION_MAJOR 0)
set(ENGINE_VERSION_MINOR 1)
set(ENGINE_VERSION_PATCH 0)

# Writing default message
message(STATUS "WINDFALL ENGINE ${ENGINE_VERSION_MAJOR}.${ENGINE_VERSION_MINOR}.${ENGINE_VERSION_PATCH}")

# Compilation Flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -g")

# Getting properties
# -> SFML_PATH
file(STRINGS "CMakeConfig.txt" SFML_PATH)
message(STATUS ${SFML_PATH})

# include search path
include_directories(include)

# Adding sub directories
# Sources directories
add_subdirectory(src)

# Adding sub Test
add_subdirectory(test)



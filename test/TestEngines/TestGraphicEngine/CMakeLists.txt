# Windfall Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-06-18
cmake_minimum_required(VERSION 3.1)

# Required for Google Test
add_definitions(-std=gnu++0x)

# gtest directory
include_directories(
        "${gtest_SOURCE_DIR}/include"
        "${gtest_SOURCE_DIR}"
        "${SFML_PATH}/include")

# Set output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/Test")

# Creating unit Test executable
add_executable(graphicEngineUnitTest
        TileSetUnitTest.cpp)

# Linking libraries
target_link_libraries(graphicEngineUnitTest
        gtest
        gtest_main
        "${SFML_PATH}/lib/libsfml-graphics-d.a")
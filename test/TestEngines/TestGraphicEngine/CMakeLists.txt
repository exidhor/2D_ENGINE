# Windfall Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-06-18
cmake_minimum_required(VERSION 3.1)

# Required for Google Test
add_definitions(-std=gnu++0x)

# gtest directory
include_directories(
        "${CMAKE_SOURCE_DIR}/include/Extern"
        "${SFML_PATH}/include")

# Set output dir
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib/Test")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Creating unit Test executable
add_executable(graphicEngineUnitTest
        TileSetUnitTest.cpp)

# Linking libraries
target_link_libraries(graphicEngineUnitTest
        "${CMAKE_SOURCE_DIR}/lib/Test/libgtest.a"
        "${CMAKE_SOURCE_DIR}/lib/Test/libgtest_main.a"
        "${CMAKE_SOURCE_DIR}/lib/Engines/libgraphic.dll.a")
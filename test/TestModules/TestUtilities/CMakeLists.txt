# Windfall Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-06-18
cmake_minimum_required(VERSION 3.1)

# Required for Google Test
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")

# gtest directory
include_directories(
        "${CMAKE_SOURCE_DIR}/include/Extern"
        "${SFML_PATH}/include")

# Set output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Creating unit Test executable
add_executable(runUtilitiesModuleTests
        TimerUnitTest)

# Linking libraries
target_link_libraries(runUtilitiesModuleTests
        "${CMAKE_SOURCE_DIR}/lib/Test/libgtest.a"
        "${CMAKE_SOURCE_DIR}/lib/Test/libgtest_main.a"
        "${CMAKE_SOURCE_DIR}/lib/Test/libgmock.a")

# Linking libraries
target_link_libraries(runUtilitiesModuleTests
        "${CMAKE_SOURCE_DIR}/lib/Modules/libmod-utils.dll.a")
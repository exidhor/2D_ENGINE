# Engine project
# Author : Aredhele, Exidhor
# Date   : 2016-06-18
cmake_minimum_required(VERSION 3.1)

# Getting different Engine
# Graphic Engine
#        |       Physic Engine
#        |             |
#        v             v
#          Game Engine

# Graphic Engine
add_subdirectory(GraphicEngine)

# Physic Engine
add_subdirectory(PhysicEngine)

# Game Engine
add_subdirectory(GameEngine)
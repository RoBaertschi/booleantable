cmake_minimum_required(VERSION 3.28)
# IMPORTANT: The project name needs to have the same name as the executable target. See ./dependencies/sdl/CMakeLists.txt
project(booleantable)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(dependencies)
add_subdirectory(src)
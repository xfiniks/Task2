cmake_minimum_required(VERSION 3.20)
project(Task_2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_ASAN "-g -fsanitize=address"
        CACHE STRING "Compiler flags in asan build"
        FORCE)

set(CMAKE_CXX_FLAGS_UBSAN "-g -fsanitize=undefined"
        CACHE STRING "Compiler flags in ubsan build"
        FORCE)

add_executable(Task_2 Source/main.cpp Source/container.cpp Source/container.h Source/plant.cpp Source/plant.h Source/flower.cpp Source/flower.h Source/shrub.cpp Source/shrub.h Source/rnd.cpp Source/rnd.h Source/tree.cpp Source/tree.h)

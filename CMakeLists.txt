cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SRE2)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Add executable
# add_executable(SRE2 src/main.cpp src/Engine.cpp src/Sprite.cpp)

#Add library
add_library(SRE2 SHARED src/Engine.cpp)

#Include directories
include_directories(include)
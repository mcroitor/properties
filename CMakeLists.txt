cmake_minimum_required(VERSION 3.0)

# project name
project(properties VERSION 1.0.0)

# set c++ standard version
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# list of library sources
set(SOURCE_LIB properties.cpp)

 # build 'properties' static library
add_library(properties STATIC ${SOURCE_LIB})

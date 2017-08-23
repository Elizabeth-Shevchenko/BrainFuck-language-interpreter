cmake_minimum_required(VERSION 2.8.9)

project(BrainF_Language_Interpreter)

# Set support for c++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# The headers will be included into the project
include_directories(include)

# There are 2 ways to detect source files:
# The first: file(GLOB SOURCES "src/*.cpp"), the second: 
aux_source_directory(src SOURCES)

# Generate the shared library from the sources
add_library(Interpreter SHARED ${SOURCES})
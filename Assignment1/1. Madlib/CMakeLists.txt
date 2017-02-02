cmake_minimum_required(VERSION 3.6)
project(Madlib)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES madlib.cpp)
add_executable(Madlib ${SOURCE_FILES})
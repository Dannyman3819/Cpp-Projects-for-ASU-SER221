cmake_minimum_required(VERSION 3.6)
project(RockPaperScissors)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES rpc.cpp)
add_executable(RockPaperScissors ${SOURCE_FILES})
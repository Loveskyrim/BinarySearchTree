cmake_minimum_required(VERSION 2.8)
project(proj1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(SOURCE_FILES  include/BinarySearchTree.h sourse/BinarySearchTree.cpp)
add_executable(proj1 ${SOURCE_FILES} examples/main.cpp)

cmake_minimum_required(VERSION 3.3)
project(first)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/ /tests/)

set(SOURCE_FILES main.cpp BinarySearchTree.cpp BinarySearchTree.h size.cpp catch.cpp)
add_executable(first ${SOURCE_FILES} examples/main.cpp)
add_executable(first ${SOURCE_FILES} tests/size.cpp tests/main.cpp)

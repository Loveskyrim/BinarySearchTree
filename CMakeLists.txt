cmake_minimum_required(VERSION 2.8.7)
project(proj1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(proj1 STATIC ${CMAKE_CURRENT_SOURCE_DIR}/source/BinarySearchTree.cpp)

add_executable(Examples ${CMAKE_CURRENT_SOURCE_DIR} examples/main.cpp)
add_executable(Tests ${TESTS_SOURCE} tests/catch.hpp tests/size.cpp tests/main.cpp tests/insert.cpp tests/find.cpp)

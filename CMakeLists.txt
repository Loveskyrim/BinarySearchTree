cmake_minimum_required(VERSION 2.8.7)
project(first)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/ /tests/)

set(SOURCE_FILES examples/main.cpp sourse/BinarySearchTree.cpp)
add_executable(examples ${SOURCE_FILES} examples/main.cpp)
add_executable(tests ${SOURCE_FILES} tests/size.cpp tests/main.cpp tests/find.cpp tests/insert.cpp)

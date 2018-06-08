cmake_minimum_required(VERSION 3.5)
project(cpp_linked_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES main.cpp Node.cpp LinkedList.cpp)
add_executable(cpp_linked_list ${SOURCE_FILES})
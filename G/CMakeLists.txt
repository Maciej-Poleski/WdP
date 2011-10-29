cmake_minimum_required(VERSION 2.8.5 FATAL_ERROR)
project(G)
if(DEBUG)
    add_definitions(-DDEBUG)
endif(DEBUG)
add_executable(g main.c)

set(CMAKE_CXX_FLAGS "-std=c++0x")

add_executable(wzor main.cxx)
add_executable(find_test find.cxx)

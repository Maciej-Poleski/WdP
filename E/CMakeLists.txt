cmake_minimum_required(VERSION 2.8.5 FATAL_ERROR)
project(E)
if(DEBUG)
    add_definitions(-DDEBUG)
endif(DEBUG)
if(TWEAK_BS)
    add_definitions(-DTWEAK_BS)
endif(TWEAK_BS)
add_executable(e main.c)

set(CMAKE_CXX_FLAGS "-std=c++0x")

add_executable(wzor main.cxx)
add_executable(find_test find.cxx)

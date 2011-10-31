cmake_minimum_required(VERSION 2.8.5 FATAL_ERROR)
project(H)
if(DEBUG)
    add_definitions(-DDEBUG)
endif(DEBUG)

if(COVERAGE)
    set(CMAKE_C_FLAGS "-fprofile-arcs -ftest-coverage")
endif(COVERAGE)

add_executable(h main.c)

if(COVERAGE)
    set_target_properties(h PROPERTIES LINK_FLAGS "-coverage")
endif(COVERAGE)

set(CMAKE_CXX_FLAGS "-std=c++0x")

add_executable(wzor main.cxx)
add_executable(find_test find.cxx)

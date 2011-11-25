cmake_minimum_required(VERSION 2.8.5 FATAL_ERROR)

set(PROBLEM l)

project(${PROBLEM})
if(DEBUG)
    add_definitions(-DDEBUG)
endif(DEBUG)

if(COVERAGE)
    set(CMAKE_C_FLAGS "-fprofile-arcs -ftest-coverage -Wall -Wextra")
endif(COVERAGE)

add_executable(${PROBLEM} main.c)

if(COVERAGE)
	set_target_properties(${PROBLEM} PROPERTIES LINK_FLAGS "-coverage")
endif(COVERAGE)

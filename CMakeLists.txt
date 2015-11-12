project(knuth)

cmake_minimum_required( VERSION 3.0 )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/src )

set( CMAKE_C_FLAGS   "-march=native -fpic -Wall -pedantic -pipe" )
set( CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++14 -Wfatal-errors" )

set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g2 -O2")

add_subdirectory(src)
add_subdirectory(test)


cmake_minimum_required(VERSION 3.0)
project(CPP_TP2_EUGE_NATH)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

file(MAKE_DIRECTORY output) # Create directory for outputs

set(sources
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/Vehicule.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(CPP_TP2_EUGE_NATH ${sources})
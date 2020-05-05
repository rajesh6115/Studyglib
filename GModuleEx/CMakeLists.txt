cmake_minimum_required (VERSION 3.10)

project (GModuleEx VERSION 1.0.0 LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)

include_directories(include)

add_subdirectory(src)
add_subdirectory(example)
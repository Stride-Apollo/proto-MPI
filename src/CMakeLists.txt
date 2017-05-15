cmake_minimum_required(VERSION 2.8)

project(MPI_test)

add_executable(MPI_test main.cpp)
set (CMAKE_CXX_STANDARD 11)
add_compile_options(-std=c++11)

# Require MPI for this project:
find_package(MPI REQUIRED)
set(CMAKE_CXX_COMPILE_FLAGS ${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS})
set(CMAKE_CXX_LINK_FLAGS ${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS})
include_directories(MPI_INCLUDE_PATH)
target_link_libraries(MPI_test ${MPI_LIBRARIES})

cmake_minimum_required(VERSION 3.1)

project(examples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(BUILD_SHARED_LIBS ON)

add_executable(example example.cpp)
target_link_libraries(example)

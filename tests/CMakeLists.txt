cmake_minimum_required(VERSION 3.1)

project(tests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall  -Wextra")
set(BUILD_SHARED_LIBS ON)

add_executable(tests tests.cpp)

target_link_libraries(tests gtest)

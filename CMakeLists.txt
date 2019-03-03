cmake_minimum_required(VERSION 3.4.3)
project(trie)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# Try always use dll
set(BUILD_SHARED_LIBS ON)
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(BUILD_TYPE ${CMAKE_BUILD_TYPE})
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3dparty)
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Directory where exe,dll and static libraries saved
set(BINARY_DIR ${PROJECT_BINARY_DIR}/bin-${BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_DIR})

# Include
include_directories(
    ${THIRD_PARTY_DIR}
    ${THIRD_PARTY_DIR}/googletest/googletest/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

#GTest
add_subdirectory(${THIRD_PARTY_DIR}/googletest/googletest ${BINARY_DIR}-gtest EXCLUDE_FROM_ALL)

#Examples
add_subdirectory(examples)

#Tests
add_subdirectory(tests)

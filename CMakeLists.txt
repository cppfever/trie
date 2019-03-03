cmake_minimum_required(VERSION 3.1)
project(trie)

include(cmake/submodules.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# Try always use dll
set(BUILD_SHARED_LIBS ON)
#set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(BUILD_TYPE ${CMAKE_BUILD_TYPE})
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3dparty)
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Directory where exe,dll and static libraries saved
set(BINARY_DIR ${CMAKE_BINARY_DIR}/bin-${BUILD_TYPE})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BINARY_DIR})

#GTest
add_subdirectory(${THIRD_PARTY_DIR}/googletest/googletest)
set_target_properties(gtest
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${BINARY_DIR}"
  LIBRARY_OUTPUT_DIRECTORY "${BINARY_DIR}"
  ARCHIVE_OUTPUT_DIRECTORY "${BINARY_DIR}"
  PDB_OUTPUT_DIRECTORY "${BINARY_DIR}")

set_target_properties(gtest_main
  PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${BINARY_DIR}"
  LIBRARY_OUTPUT_DIRECTORY "${BINARY_DIR}"
  ARCHIVE_OUTPUT_DIRECTORY "${BINARY_DIR}"
  PDB_OUTPUT_DIRECTORY "${BINARY_DIR}")

# Include
include_directories(
    ${THIRD_PARTY_DIR}
    ${THIRD_PARTY_DIR}/googletest/googletest/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Examples
add_subdirectory(examples)

#Tests
add_subdirectory(tests)

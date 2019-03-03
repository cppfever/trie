find_package(Git QUIET)

include(cmake/submodule_directory.cmake)
include(cmake/submodule_init.cmake)
include(cmake/submodule_update.cmake)

# gogletest
message(STATUS "\nGoogle test submodule checking.")
submodule_directory(googletest)
submodule_init(googletest CMakeLists.txt)
submodule_update(googletest CMakeLists.txt)

message(STATUS "\n")

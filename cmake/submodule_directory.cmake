function(submodule_directory DIRECTORY_NAME)

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/3dparty/${DIRECTORY_NAME})
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/3dparty/${DIRECTORY_NAME})
else()
    message(STATUS "${DIRECTORY_NAME} directory exists.")
endif()

endfunction(submodule_directory)

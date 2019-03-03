function(submodule_init SUBMODULE_NAME FILE_NAME)

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/3dparty/${SUBMODULE_NAME}/${FILE_NAME})
    execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule init 3dparty/${SUBMODULE_NAME}
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

    if(result)
        message(STATUS "${SUBMODULE_NAME} submodule IS NOT initilized.")
    else()
        message(STATUS "${SUBMODULE_NAME} submodule is initilized.")
    endif()

endif()

endfunction(submodule_init)

function(submodule_update SUBMODULE_NAME FILE_NAME)

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/3dparty/${SUBMODULE_NAME}/${FILE_NAME})
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init -- 3dparty/${SUBMODULE_NAME}
                    RESULT_VARIABLE result
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

    if(result)
        message(STATUS "${SUBMODULE_NAME} submodule IS NOT updated.")
    else()
        message(STATUS "${SUBMODULE_NAME} submodule is updated.")
    endif()

else()
    message(STATUS "${SUBMODULE_NAME} submodule exists.")
endif()

endfunction(submodule_update)

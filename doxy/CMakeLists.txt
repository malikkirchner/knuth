if(NOT DOXYGEN_EXECUTABLE)
    # try default search for doxygen
    find_package(Doxygen 1.8.8)
else()
    set(DOXYGEN_FOUND True)
endif(NOT DOXYGEN_EXECUTABLE)


# add build doc target if we found appropriate doxygen
if( DOXYGEN_FOUND )
    #if( ${MAKE_DOC} )

        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doxy.conf ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

        add_custom_target(doc ALL
            ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/
            COMMENT "Generating API documentation with Doxygen" VERBATIM
        )

    #endif( ${MAKE_DOC} )
endif( DOXYGEN_FOUND )

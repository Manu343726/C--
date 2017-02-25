# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
        )
    
else (DOXYGEN_FOUND)
    message(FATAL_ERROR "Doxygen need to be installed to generate the doxygen documentation")
endif ()

# Parse Doxygen configuration file
configure_file(${CMAKE_SOURCE_DIR}/doc/Doxyfile.in Doxyfile)

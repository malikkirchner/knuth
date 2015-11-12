# For building all tests within a loop, a stackoverflow post was used (can't remember which one).

# get all cpp files from this directory and store them in ${tests} variable
file(GLOB tests RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

set(Boost_USE_STATIC_LIBS   OFF)

# run through each source
foreach(file ${tests})

        message(STATUS "Setting up test: " ${file})

        # get filename without an extension (NAME_WE)
        get_filename_component(name ${file} NAME_WE)

        # create variable binary name to be used
        set(name test-${name})

        # add compile target
        add_executable(${name} ${file})

        # link to Boost libraries AND your targets and dependencies
        target_link_libraries(${name} ${Boost_LIBRARIES} )

        # move testing binaries into a test binary directory
        set_target_properties(${name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

        # finally add it to test execution
        add_test(NAME ${name} COMMAND ${name} --show_progress=yes)

        # append the binary name to a list for running all tests at once
        list(APPEND test_executables ${name})
endforeach(file)

# create a target that runs all compiled tests
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS ${test_executables})

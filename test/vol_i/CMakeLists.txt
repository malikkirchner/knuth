#**************************************************************************************#
#     Copyright (C) 2014 Malik Kirchner "malik.kirchner@gmx.net"                       #
#                                                                                      #
#     This program is free software: you can redistribute it and/or modify             #
#     it under the terms of the GNU General Public License as published by             #
#     the Free Software Foundation, either version 3 of the License, or                #
#     (at your option) any later version.                                              #
#                                                                                      #
#     This program is distributed in the hope that it will be useful,                  #
#     but WITHOUT ANY WARRANTY; without even the implied warranty of                   #
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    #
#     GNU General Public License for more details.                                     #
#                                                                                      #
#     You should have received a copy of the GNU General Public License                #
#     along with this program.  If not, see <http://www.gnu.org/licenses/>.            #
#                                                                                      #
#     Dieses Programm ist Freie Software: Sie können es unter den Bedingungen          #
#     der GNU General Public License, wie von der Free Software Foundation,            #
#     Version 3 der Lizenz oder (nach Ihrer Option) jeder späteren                     #
#     veröffentlichten Version, weiterverbreiten und/oder modifizieren.                #
#                                                                                      #
#     Dieses Programm wird in der Hoffnung, dass es nützlich sein wird, aber           #
#     OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite               #
#     Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.       #
#     Siehe die GNU General Public License für weitere Details.                        #
#                                                                                      #
#     Sie sollten eine Kopie der GNU General Public License zusammen mit diesem        #
#     Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.       #
#                                                                                      #
#**************************************************************************************#

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

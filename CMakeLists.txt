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

project(knuth)

cmake_minimum_required( VERSION 3.0 )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/src )

set( CMAKE_C_FLAGS   "-march=native -fpic -Wall -pedantic -pipe" )
set( CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++14 -Wfatal-errors" )

set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g2 -O2")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(doxy)

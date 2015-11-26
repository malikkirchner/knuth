// clang-format disable
//**************************************************************************************//
//     Copyright (C) 2014 Malik Kirchner "malik.kirchner@gmx.net"                       //
//                                                                                      //
//     This program is free software: you can redistribute it and/or modify             //
//     it under the terms of the GNU General Public License as published by             //
//     the Free Software Foundation, either version 3 of the License, or                //
//     (at your option) any later version.                                              //
//                                                                                      //
//     This program is distributed in the hope that it will be useful,                  //
//     but WITHOUT ANY WARRANTY; without even the implied warranty of                   //
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                    //
//     GNU General Public License for more details.                                     //
//                                                                                      //
//     You should have received a copy of the GNU General Public License                //
//     along with this program.  If not, see <http://www.gnu.org/licenses/>.            //
//                                                                                      //
//     Dieses Programm ist Freie Software: Sie können es unter den Bedingungen          //
//     der GNU General Public License, wie von der Free Software Foundation,            //
//     Version 3 der Lizenz oder (nach Ihrer Option) jeder späteren                     //
//     veröffentlichten Version, weiterverbreiten und/oder modifizieren.                //
//                                                                                      //
//     Dieses Programm wird in der Hoffnung, dass es nützlich sein wird, aber           //
//     OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite               //
//     Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.       //
//     Siehe die GNU General Public License für weitere Details.                        //
//                                                                                      //
//     Sie sollten eine Kopie der GNU General Public License zusammen mit diesem        //
//     Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.       //
//                                                                                      //
//**************************************************************************************//
// clang-format enable


/*!
 * @file  prime.hpp
 * @brief Contains implementations of prime number algorithms.
 *
 * @author Malik Kirchner <malik.kirchner@gmx.net>
 */


#pragma once

#include <cassert>
#include <type_traits>
#include <array>

namespace knuth {

namespace detail {


}

/*!
 * @brief Finds the first N prime numbers [(i)1.3.2:P]
 *
 * @return first N prime numbers
 */
template < typename T, size_t N > std::array<T, N> primes() noexcept {
    static_assert( std::is_integral<T>::value, "There are only integral prime numbers." );
    static_assert( N > 0, "Let me calculate at least one prime number, please!" );

    std::array<T, N> result;
    result[0]     = 2;
    result[1]     = 3;

    T       next  = 3;
    size_t  j     = 1;

    while ( j < N ) {
        next += 2;
        for ( size_t k = 1; k <= j; ++k ) {
            const T q = next / result[k];
            const T r = next - q * result[k];
            if ( r == 0 ) { break; }
            if ( q <= result[k] ) {
                ++j;
                result[j] = next;
                break;
            }
        }
    }

    return result;
}


}

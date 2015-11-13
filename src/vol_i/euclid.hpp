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

#pragma once


#include <type_traits>
#include <cmath>
#include <tuple>

namespace knuth {

namespace detail {

    template < typename T > constexpr T __euclid( const T& m, const T& n ) noexcept {
        const T r = m % n;
        if ( r == 0 )
            return n;
        return __euclid< T >( n, r );
    }

    template < typename T > constexpr std::tuple< T, T, T > __extended_euclid( const T& m, const T& n ) noexcept {
        const T r = m % n;
        if ( r == 0 )
            return n;
        return __extended_euclid< T >( n, r );
    }
}

/*!
 * Euclids algorithm [(i)1.1:E]
 */
template < typename T > constexpr T euclid( const T& m, const T& n ) noexcept {
    static_assert( std::is_integral< T >::value, "Integer required." );

    if ( std::is_unsigned< T >::value ) {
        if ( ( m == 0 ) || ( n == 0 ) )
            return m < n ? n : m;

        if ( m < n )
            return detail::__euclid< T >( n, m );
        else
            return detail::__euclid< T >( m, n );
    } else {
        const T a = std::abs( m );
        const T b = std::abs( n );

        if ( ( a == 0 ) || ( b == 0 ) )
            return a < b ? b : a;

        if ( a < b )
            return detail::__euclid< T >( b, a );
        else
            return detail::__euclid< T >( a, b );
    }
}

/*!
 * Extended Euclids algorithm [(i)1.2.1:E]
 */
template < typename T > constexpr std::tuple< T, T, T > extended_euclid( const T& m, const T& n ) noexcept {
    static_assert( std::is_integral< T >::value, "Integer required." );
    static_assert( std::is_unsigned< T >::value, "Unsigned value required." );

    if ( ( m == 0 ) || ( n == 0 ) )
        return m < n ? n : m;

    if ( m < n )
        return detail::__extended_euclid< T >( n, m );
    else
        return detail::__extended_euclid< T >( m, n );
}
}

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
 * @file  euclid.hpp
 * @brief Contains implementations of Euclids algorithm.
 *
 * @author Malik Kirchner <malik.kirchner@gmx.net>
 */


#pragma once

#include <cassert>
#include <type_traits>
#include <cmath>
#include <tuple>

namespace knuth {

namespace detail {

    template < typename T > constexpr T __euclid( const T& m, const T& n ) noexcept {
        const T r = m % n;
        if ( r == 0 ) return n;
        return __euclid< T >( n, r );
    }

    template < typename T > std::tuple< T, T, T > __extended_euclid( const T& m, const T& n ) noexcept {
        // [initialize]
        T a  = 0;
        T b  = 1;
        T aa = 1;
        T bb = 0;
        T c  = m;
        T d  = n;

        while ( true ) {
            // [divide]
            T q = c / d;
            T r = c - q * d;

            assert( a * m + b * n == d );
            assert( aa * m + bb * n == c );
            assert( ( 0 <= r ) && ( r < d ) );

            // [remainder zero?]
            if ( r == 0 ) break;

            // [recycle]
            c   = d;
            d   = r;
            T t = aa;
            aa  = a;
            a   = t - q * a;
            t   = bb;
            bb  = b;
            b   = t - q * b;
        }

        assert( a * m + b * n == d );

        return std::make_tuple< T, T, T >( std::move( a ), std::move( b ), std::move( d ) );
    }
}

/*!
 * @brief Euclids algorithm [(i)1.1:E]
 *
 * @param m integer
 * @param n integer
 *
 * @return greatest common divisor gcd(m,n)
 */
template < typename T > constexpr T euclid( const T& m, const T& n ) noexcept {
    static_assert( std::is_integral< T >::value, "Integer required." );

    if ( std::is_unsigned< T >::value ) {
        if ( ( m == 0 ) || ( n == 0 ) ) return m < n ? n : m;

        if ( m < n )
            return detail::__euclid< T >( n, m );
        else
            return detail::__euclid< T >( m, n );
    } else {
        const T a = std::abs( m );
        const T b = std::abs( n );

        if ( ( a == 0 ) || ( b == 0 ) ) return a < b ? b : a;

        if ( a < b )
            return detail::__euclid< T >( b, a );
        else
            return detail::__euclid< T >( a, b );
    }
}

/*!
 * @brief Extended Euclids algorithm [(i)1.2.1:E]
 *
 * @param m integer m > 0
 * @param n integer n > 0
 *
 * @return (a,b,d) that a*m + b*n = d
 */
template < typename T > std::tuple< T, T, T > extended_euclid( const T& m, const T& n ) noexcept {
    static_assert( std::is_integral< T >::value, "Integer required." );
    static_assert( std::is_signed< T >::value, "Signed type required." );

    assert( m > 0 );
    assert( n > 0 );

    return detail::__extended_euclid< T >( m, n );
}
}

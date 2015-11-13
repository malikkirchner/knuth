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

#include <iostream>
#include <random>

#include <vol_i/euclid.hpp>

// Link to Boost
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE "Euclids Algorithm"

// VERY IMPORTANT - include this last
#include <boost/test/unit_test.hpp>


const unsigned primes[] = {
        2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,
        83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
        197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317,
        331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457,
        461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601,
        607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743,
        751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887};


BOOST_AUTO_TEST_CASE( test_euclid ) {
    using namespace knuth;

    static_assert( euclid< unsigned >( 100, 45 ) == 5, "Check for constexpr-ness" );
    static_assert( euclid< int >( 100, -45 ) == 5, "Check for constexpr-ness" );

    BOOST_CHECK( euclid< int >( 0, 2 ) == 2 );
    BOOST_CHECK( euclid< int >( 2, 0 ) == 2 );
    BOOST_CHECK( euclid< int >( 10, 4 ) == 2 );
    BOOST_CHECK( euclid< int >( 4, 10 ) == 2 );
    BOOST_CHECK( euclid< int >( 5, 4 ) == 1 );
    BOOST_CHECK( euclid< int >( 1000, 3332 ) == 4 );

    BOOST_CHECK( euclid< int >( 0, -2 ) == 2 );
    BOOST_CHECK( euclid< int >( 2, 0 ) == 2 );
    BOOST_CHECK( euclid< int >( 10, -4 ) == 2 );
    BOOST_CHECK( euclid< int >( -4, -10 ) == 2 );
    BOOST_CHECK( euclid< int >( 5, -4 ) == 1 );
    BOOST_CHECK( euclid< int >( 1000, -3332 ) == 4 );

    const size_t number_tries = 1000;

    std::mt19937_64 generator;
    generator.seed( std::random_device{}() );
    std::uniform_int_distribution< size_t > distribution( 0, 5 );

    for ( size_t k = 0; k < number_tries; ++k ) {
        const uint64_t d = primes[ 5 + distribution( generator ) ];
        const uint64_t m = d * primes[ distribution( generator ) ];
        const uint64_t n = d * primes[ sizeof( primes ) - distribution( generator ) - 1 ];

        const uint64_t ggt = euclid< uint64_t >( m, n );
        std::cout << m << ", " << n << ", " << d << ", " << ggt << std::endl;
        BOOST_CHECK( ( ggt == ( m == n ? m : d ) ) || ( m == ggt ) || ( n == ggt ) );
    }
}

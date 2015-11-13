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
#define BOOST_TEST_MODULE "Extended Euclids Algorithm"

// VERY IMPORTANT - include this last
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE( test_extended_euclid ) {
    using namespace knuth;

    // static_assert( euclid< unsigned >( 100, 45 ) == 5, "Check for constexpr-ness" );
    // static_assert( euclid< int >( 100, -45 ) == 5, "Check for constexpr-ness" );

    const size_t number_tries = 1000;

    std::mt19937_64 generator;
    generator.seed( std::random_device{}() );
    std::uniform_int_distribution< int > distribution( 0, 1e+6 );

    int a, b, d, m, n;

    for ( size_t k = 0; k < number_tries; ++k ) {
        m = distribution( generator );
        n = distribution( generator );
        std::tie( a, b, d ) = extended_euclid< int >( m, n );
        std::cout << "(" << a << ") * " << m << " + (" << b << ") * " << n << " = " << d << std::endl;
        BOOST_CHECK( a * m + b * n == d );
    }
}

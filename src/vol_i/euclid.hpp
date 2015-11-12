#pragma once

#include <type_traits>
#include <cmath>

namespace knuth {

    namespace detail {

        template<typename T>
        constexpr T __euclid( const T& m, const T&n ) noexcept {
            const T r = m % n;
            if ( r == 0 ) return n;
            return __euclid<T>( n, r );
        }

    }

    /*!
     * Euclids algorithm [(i)1.1:E]
     */
    template<typename T>
    constexpr T euclid( const T& m, const T&n ) noexcept {
        static_assert( std::is_integral<T>::value, "Integer required." );

        if ( std::is_unsigned<T>::value ) {
            if ( (m == 0) || (n == 0) ) return m < n ? n : m;

            if ( m < n )
                return detail::__euclid<T>( n, m );
            else
                return detail::__euclid<T>( m, n );
        } else {
            const T a = std::abs(m);
            const T b = std::abs(n);

            if ( (a == 0) || (b == 0) ) return a < b ? b : a;

            if ( a < b )
                return detail::__euclid<T>( b, a );
            else
                return detail::__euclid<T>( a, b );
        }
    }

}

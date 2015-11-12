#pragma once


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
        if ( (m == 0) || (n == 0) ) return m < n ? n : m;

        if ( m < n )
            return detail::__euclid<T>( n, m );
        else
            return detail::__euclid<T>( m, n );
    }

}

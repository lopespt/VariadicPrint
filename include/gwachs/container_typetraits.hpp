//
// Created by Guilherme Wachs on 13/01/16.
//

#ifndef VARIADICPRINT_CONTAINER_TYPETRAITS_HPP
#define VARIADICPRINT_CONTAINER_TYPETRAITS_HPP


#include <type_traits>


template<typename T, typename _ = void>
struct is_container : std::false_type {};

template<typename... Ts>
struct is_container_helper {};

template<typename T>
struct is_container<
        T,
        typename std::conditional<
        false,
        is_container_helper<
                typename T::value_type,
                typename T::size_type,
                typename T::allocator_type,
                typename T::iterator,
                typename T::const_iterator,
                decltype(std::declval<T>().size()),
                decltype(std::declval<T>().begin()),
                decltype(std::declval<T>().end()),
                decltype(std::declval<T>().cbegin()),
                decltype(std::declval<T>().cend())
        >,
        void
>::type
> : public std::true_type {};

#endif //VARIADICPRINT_CONTAINER_TYPETRAITS_HPP

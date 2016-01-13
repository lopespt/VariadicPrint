//
// Created by Guilherme Wachs on 13/01/16.
//

#ifndef VARIADICPRINT_VARIADIC_PRINT_HPP
#define VARIADICPRINT_VARIADIC_PRINT_HPP

#include <iostream>
#include <type_traits>
#include "container_typetraits.hpp"

namespace gwl {
    namespace iostream {

        template<char sep = ' ', typename T>
        typename std::enable_if<!std::is_arithmetic<T>::value>::type
        print(T f) {
            std::cout << f;
        };

        template<char sep = ' ', typename T>
        typename std::enable_if<std::is_arithmetic<T>::value>::type
        print(T f) {
            std::cout << f;
        };

//Prototypes
        template<char sep = ' ', typename T, typename ... ARGS>
        typename std::enable_if<std::is_arithmetic<T>::value>::type
                print(T f, ARGS ... args);

        template<char sep = ' ', typename T, typename ... ARGS>
        typename std::enable_if<!std::is_arithmetic<T>::value && !is_container<T>::value >::type
                print(T f, ARGS ... args);

//Non arithmetic behavior
        template<char sep, typename T, typename ... ARGS>
        typename std::enable_if<!std::is_arithmetic<T>::value && !is_container<T>::value >::type
        print(T f, ARGS ... args) {
            std::cout << f;
            print<sep, ARGS ...>(args...);
        };

//Arithmetic behavior
        template<char sep, typename T, typename ... ARGS>
        typename std::enable_if<std::is_arithmetic<T>::value>::type
        print(T f, ARGS ... args) {
            if (sep != '\0')
                std::cout << f << sep;
            else
                std::cout << f;

            print<sep, ARGS ...>(args...);
        };


        //Type Traits for containers
        template<char c = ' ', typename T, typename ... ARGS>
        typename std::enable_if<is_container<T>::value>::type
        print(T f, ARGS ... args){
            for(const auto &i : f){
                print(i, c);
            }
        };




        template<char c = ' ', typename ... ARGS>
        void printl(ARGS ... args) {
            print<c, ARGS...>(args ...);
            printf("\n");
        }
    }
}

#endif //VARIADICPRINT_VARIADIC_PRINT_HPP

cmake_minimum_required(VERSION 3.4)
project(VariadicPrint)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp variadic_print.hpp container_typetraits.hpp)
add_executable(VariadicPrint ${SOURCE_FILES})
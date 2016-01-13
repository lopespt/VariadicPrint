cmake_minimum_required(VERSION 3.4)
project(VariadicPrint)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(./include/)

set(SOURCE_FILES main.cpp include/gwachs/variadic_print.hpp include/gwachs/container_typetraits.hpp)
add_executable(VariadicPrint ${SOURCE_FILES})

INSTALL(DIRECTORY ./include/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
install(FILES variadicprint-config.cmake DESTINATION lib/gwachs)


set(CPACK_PACKAGE_NAME "VariadicPrint Library")
set(CPACK_PACKAGE_VENDOR "GWachs")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Variadic Print Library")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")

INCLUDE(CPack)

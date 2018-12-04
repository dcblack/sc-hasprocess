#!cmake .
#
# See ABOUT_CMAKE.md for instructions.
#

cmake_minimum_required( VERSION 3.11 )

project( hasprocess CXX )
set( TARGET_NAME hasprocess.x )

set( default_build_type "Debug" )
include( cmake/SystemC.cmake )

add_compile_definitions( SC_INCLUDE_FX SC_INCLUDE_DYNAMIC_PROCESSES )

add_executable( ${TARGET_NAME}
 hasprocess.cpp
)

# Uncomment the following only if specifically needed
#> target_compile_definitions( hasprocess PRIVATE MYEXAMPLE )
#> target_link_libraries( hasprocess yaml-cpp )
#> target_compile_features( hasprocess.x PUBLIC cxx_std_11 )
#> target_include_directories( hasprocess.x includes )

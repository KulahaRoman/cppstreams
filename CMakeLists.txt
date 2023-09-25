cmake_minimum_required(VERSION 3.15)

project(lib-cppstreams)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPPSTREAMS_INSTALL_BIN ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CPPSTREAMS_INSTALL_LIB ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CPPSTREAMS_INSTALL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(NOT TARGET gtest)
	add_subdirectory(libs/gtest)
endif()
if(NOT TARGET cpputils)
	add_subdirectory(libs/cpputils)
endif()

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME ON)

find_package(Boost REQUIRED)

if(NOT TARGET cppstreams)
	add_subdirectory(src)
	add_subdirectory(test)
endif()
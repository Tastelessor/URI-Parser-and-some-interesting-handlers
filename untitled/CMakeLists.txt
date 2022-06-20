cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled checkFiles/checkSSH.cpp checkFiles/Check.h Main.cpp URI/URIParser.h URI/URIParser.cpp)
add_subdirectory(Google_tests)
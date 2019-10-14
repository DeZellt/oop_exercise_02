cmake_minimum_required(VERSION 3.10.2)
project(lab2)
set(CMAKE_CXX_STANDARD 14)
add_executable(lab2
	lab2.cpp
	bitstring.cpp)

set(CMAKE_CXX_FLAGS
	"${CMAKE_CXX_FLAGS} -Wall -Wextra")

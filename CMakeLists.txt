project(Graphics)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic --std=c++17 -g")

include_directories(framework/ sierpinski/)

set(SRC_FILES framework/application.cpp 
              sierpinski/sierpinski.cpp
	      sierpinski/square.cpp
	      sierpinski/squares.cpp
	      sierpinski/main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

link_libraries( sfml-graphics sfml-window sfml-system)

add_executable(sierpinski ${SRC_FILES})


set(SRC_FILES framework/application.cpp 
              sierpinski-triangle/sierpinski_triangle.cpp
	      sierpinski-triangle/triangle.cpp
	      sierpinski-triangle/triangles.cpp
	      sierpinski-triangle/main.cpp)
link_libraries( sfml-graphics sfml-window sfml-system)

add_executable(sierpinski-triangle  ${SRC_FILES})

project(Graphics)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "-Wextra -Wall -pedantic --std=c++17 -O2")

include_directories(framework/ menger/)

set(SRC_FILES ../main.cpp
              framework/application.cpp 
              menger/menger.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

link_libraries( sfml-graphics sfml-window sfml-system)

add_executable(menger ${SRC_FILES})

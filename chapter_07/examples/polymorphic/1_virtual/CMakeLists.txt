cmake_minimum_required(VERSION 3.28)

project(polymorphic_w_virtual CXX)
set(CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set(Headers Point.hh Shape.hh Polygon.hh Triangle.hh Circle.hh)
add_executable(${PROJECT_NAME} Point.cc Triangle.cc Circle.cc main.cc ${Headers})


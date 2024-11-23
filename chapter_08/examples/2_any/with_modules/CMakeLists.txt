cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(polymorphic_with_any)

add_executable(polyany)
target_sources(polyany
    PUBLIC
    main.cc
)
target_sources(polyany
  PUBLIC
    FILE_SET geometry_modules TYPE CXX_MODULES FILES
    Point.ixx
    Circle.ixx
    Polygon.ixx
    Triangle.ixx
)


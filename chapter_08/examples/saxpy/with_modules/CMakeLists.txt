cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(use_saxpy-example)

add_executable(use_saxpy)
target_sources(use_saxpy
    PUBLIC
    usesaxpy.cc
)
target_sources(use_saxpy
  PUBLIC
    FILE_SET saxpy_module TYPE CXX_MODULES FILES
    saxpy.ixx
)


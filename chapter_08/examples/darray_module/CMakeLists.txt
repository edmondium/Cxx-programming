cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(darray_modules)

add_executable(darray_w_modules)
target_sources(darray_w_modules
    PUBLIC
    main.cc
)
target_sources(darray_w_modules
  PUBLIC
    FILE_SET own_modules TYPE CXX_MODULES FILES
    mymodule.ixx
)


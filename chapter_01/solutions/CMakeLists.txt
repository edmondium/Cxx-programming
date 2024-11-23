cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(cxx2023_d1_solutions CXX)


FILE (GLOB sources ./ *.cc)
foreach(source ${sources})
    get_filename_component(withoutext "${source}" NAME_WE)
    add_executable("${withoutext}" "${source}")
endforeach()



cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(cxx_course_solutions CXX)


FILE (GLOB sources ./ *.cc)
foreach(source ${sources})
    get_filename_component(withoutext "${source}" NAME_WE)
    add_executable("${withoutext}" "${source}")
endforeach()



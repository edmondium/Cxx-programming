# Compile:

## hello.cc
g++ hello.cc
clang++ hello.cc

## hello_c++23.cc
g++ -std=c++23 hello_c++23.cc 
clang++ -std=c++23 -stdlib=libc++ hello_c++23.cc 

## hello_m.cc

With gcc:
g++ -std=c++23 -fmodules-ts -xc++-system-header print
g++ -std=c++23 -fmodules-ts hello_m.cc

with clang:
clang++ -std=c++23 -stdlib=libc++ -fmodules hello_m.cc

## hello_c++23_m.cc

With gcc:
g++ -std=c++23 -fmodules-ts -xc++-system-header concepts
g++ -std=c++23 -fmodules-ts -xc++-system-header iostream
g++ -std=c++23 -fmodules-ts hello_c++23_m.cc

With clang:
clang++ -std=c++23 -stdlib=libc++ -fmodules hello_c++23_m.cc



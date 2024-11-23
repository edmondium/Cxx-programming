# Programming in C++ 2022

Course material for the course "Programming in C++", 9 --13 May 2022,
organized by the Jülich Supercomputing Centre,
Forschungszentrum Jülich, Germany.


# cxx2022

You will need to pull from this repository periodically during this course.

If your computer does not have "git", you will need to use the download
button to the left of the "Clone" button in the gitlab page.

## Recommended way of working with this material

The downloaded or cloned material from this repository will be updated
during the course days. You should keep one copy of the examples and
exercises in the pristine form, and work on your own duplicates.
For example, to work on the examples in Chapter1 of the companion book,
do as follows:

```bash
    cd Book/chapter1
    cp -r examples mine
    cd mine
    clang++ -std=c++20 math_functions.cc
    ./a.out
```

Only examples (which includes some exercises) and solutions need to
be duplicated. You don't need to clone the entire material as that
includes the PDFs of the book, course slides and other utillities.


## Testing your set up

To work with this material, you will need to have a fairly up-to-date
C++ compiler. GCC version 11.2 or Clang version 13.0 is recommended.
Microsoft's Visual C++ compiler has excellent support for C++20, if
you have the latest version installed. During the course, we will focus
on using open source tools, which are available to everyone, rather
than proprietary tools.

To test your setup, proceed as follows:

```bash
    cd wherever_you_downloaded_or_cloned_this_thing
    cd test_your_setup
    g++ hello.cc -o hello.gcc
    ./hello.gcc
    clang++ hello.cc -o hello.clang
    ./hello.clang
    g++ -std=c++20 hello_c++20.cc -o hello_cxx20.gcc
    ./hello_cxx20.gcc
    clang++ -std=c++20 hello_c++20.cc -o hello_cxx20.clang
    ./hello_cxx20.clang
```

And finally to test if your compiler can at least partially
handle C++20 modules, try the two remaining examples:

```bash
    clang++ -std=c++20 -stdlib=libc++ -fmodules hello_m.cc -o hello_m.clang
    ./hello_m.clang
    clang++ -std=c++20 -stdlib=libc++ -fmodules hello_c++20_m.cc -o hello_cxx20_m.clang
    ./hello_cxx20_m.clang

    g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
    g++ -std=c++20 -fmodules-ts -xc++-system-header concepts
    g++ -std=c++20 -fmodules-ts hello_m.cc -o hello_m.gcc
    g++ -std=c++20 -fmodules-ts hello_m.cc -o hello_cxx20_m.gcc
    ./hello_m.gcc
    ./hello_cxx20_m.gcc
```

# Using aliases to save some typing

As the above examples show, we will often need to type a
lot of options to compile our programs during this course,
since we want to use C++20, which is not the default
standard for the compilers yet. A vew convenient aliases
have been prepared which you can use to shorten the
above compilation steps. To use them, do as follows:

```bash
source course_material_dir/code/bash/aliases.sh
```

Once you have done that, you can shorten the above 
steps to the following: 

```bash 
C hello.cc 
C hello_c++20.cc 

Cm hello_m.cc
Cm hello_c++20_m.cc 

Gh iostream 
Gh concepts 
Gm hello_m.cc 
Gm hello_c++20_m.cc



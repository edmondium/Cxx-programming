# Programming in C++ (2024)

Course material for the course "Programming in C++", 13 -- 17 May 2024,
organized by the Juelich Supercomputing Centre,
Forschungszentrum Juelich, Germany.


# cxx2024

You will need to pull from this repository periodically during this course.

If your computer does not have "git", you will need to use the download
button to the left of the "Clone" button in the gitlab page.

## Recommended way of working with this material

The downloaded or cloned material from this repository will be updated
during the course days. You should keep one copy of the examples and
exercises in the pristine form, and work on your own duplicates.
For example, to work on the examples in chapter 1,
do as follows:

```bash
    cd chapter1
    cp -r examples mine
    cd mine
    g++ -std=c++23 math_functions.cc
    ./a.out
```

Only examples (which includes some exercises) and solutions need to
be duplicated. You don't need to clone the entire material as that
includes the PDFs of the book, course slides and other utillities.


## Testing your set up

To work with this material, you will need to have a fairly up-to-date
C++ compiler. GCC version 14.1 or Clang version 18.1 is recommended.
These will be available for you in the course room.
Microsoft's Visual C++ compiler has excellent support for C++23, if
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
    g++ -std=c++23 hello_c++23.cc -o hello_cxx23.gcc
    ./hello_cxx23.gcc
    clang++ -std=c++23 hello_c++23.cc -o hello_cxx23.clang
    ./hello_cxx23.clang
```

# Using aliases to save some typing

As the above examples show, we will often need to type a
lot of options to compile our programs during this course,
since we want to use C++23, which is not the default
standard for the compilers yet. A few convenient aliases
have been prepared which you can use to shorten the
above compilation steps. These aliases are available as
soon as you log in to your account in the course room.
Example use, for clang is as follows. To use gcc instead,
replace C with G.

```bash 
C hello.cc 
C hello_c++23.cc 
```

In case you wish to use them on another system, for instance,
on your own laptop, do as follows:

```bash
source course_material_dir/code/bash/aliases.sh
```


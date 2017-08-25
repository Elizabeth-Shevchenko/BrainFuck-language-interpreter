### BrainFuck-language-interpreter

## Project contains:
- Interpreter library
- Unit test for the Interpreter library (using google test framework)

## Platforms:
- Linux
- Windows

## Requirements:
# Linux requirements:
- A C++03-standard-compliant compiler (C++11 is supported)

# Windows requirements:
- Microsoft Visual C++ 2012 or newer

## Build and Run

It is necessary to have CMake (used to generate native makefiles or build projects that can be used in the compiler environment of your choice).
You can download it for free from http://www.cmake.org/.

#Using CMake

- To build only Interpreter library:

cmake [from the main folder]
make

- To build and run unit tests:

cmake [from the test folder]
make
./example
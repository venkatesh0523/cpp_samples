# C++ Sample Program Framework

A small workspace to write, build, and run sample C++ programs.

## Structure

- `src/` : place your `.cpp` sample files here
- `bin/` : compiled sample binaries are created here
- `Makefile` : build and run helpers

## Usage

Build all samples:

    make

List available sample names:

    make list

Run a sample by name:

    make run NAME=hello

Create a new sample skeleton:

    make new NAME=my_sample

Clean compiled binaries:

    make clean

## Example

Open `src/hello.cpp`, modify it, then run:

    make run NAME=hello

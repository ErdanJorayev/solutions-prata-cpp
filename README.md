# C++ Solutions (Stephen Prata)

This repository contains my solutions to the exercises at the end of each chapter in Stephen Prata's book, *C++ Primer Plus*.

## Repository Structure
* **Single-file exercises:** Simple tasks are kept within a single `.cpp` file.
* **Multi-file exercises:** Exercises that require code separation are organized into their own dedicated folders containing all the necessary `.cpp` and `.h` files.

## Requirements
A compiler with support for at least the **C++11** standard is required.

## Building and Running in Linux (Ubuntu)
I compile these exercises manually in the terminal using `g++`. I don't use CMake here because these are individual educational exercises rather than a single large-scale project.

### 1. Single-file exercises:
Compile the file and specify the output program name using the `-o` flag:
```bash
g++ main.cpp -o new_prog
```
Run the program:
```bash
./new_prog
```

### 2. Multi-file exercises:
Simply list all the source files sequentially after the `g++` command:
```bash
g++ main.cpp functions.cpp -o new_prog
```
Run the program exactly the same way:
```bash
./new_prog
```

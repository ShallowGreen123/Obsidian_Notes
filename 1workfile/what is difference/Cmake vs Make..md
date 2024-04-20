## What Is Compilation?

A compiler is a program that translates source code into [machine code](https://earthly.dev/blog/compiling-containers-dockerfiles-llvm-and-buildkit). The compilation of code consists of a few steps, including preprocessing, compiling, and linking, to create either a library or an executable that can be directly run by the computer it was made for.

![[../tool/zimg/Pasted image 20230407152402.png]]

This compilation process is also known as the **build process** and is where CMake and [Make](https://earthly.dev/blog/using-cmake) enter the picture. `Source code -> Preprocessing -> Compiler -> Assembler -> Linker -> Executable code`

## How CMake and Make Work

CMake and Make are especially helpful when it comes to automation and save you time by putting all the commands required to build the program in either a [Makefile](https://earthly.dev/blog/using-cmake) or `CMakeLists.txt` file without having to type them out every time.

Make is a tool that controls the generation of executables and other non–source files of a program from the program’s source files. It obtains the instructions on how to build the program from a file called the [Makefile](https://makefiletutorial.com/).

On the other hand, CMake requires a `CMakeLists.txt` file and is a cross-platform Make. This means that it works on different operating systems. It allows **compiler-independent builds**, testing, packaging, and installation of software. It’s important to note that CMake produces build files for other systems; however, it’s not a build system itself. CMake can generate a Makefile, and then the generated Makefile can be used with Make in the platform being worked on:

![[../tool/zimg/Pasted image 20230407152030.png]]

To use Make, you have to manually create the Makefile, but with CMake, the Makefile is automatically created.

In the following sections, you’ll learn how to compile a simple program using both CMake and Make to better understand their differences.

## A Short Introduction to Makefile

- The make utility is a software tool for managing and maintaining computer programs consisting many component files. The make utility automatically determines which pieces of a large program need to be recompiled, and issues commands to recompile them. • Make reads its instruction from Makefile (called the descriptor file) by default. 

- Makefile sets a set of rules to determine which parts of a program need to be recompile, and issues command to recompile them. • Makefile is a way of automating software building procedure and other complex tasks with dependencies. • Makefile contains: dependency rules, macros and suffix(or implicit) rules.




cmake_minimum_required(VERSION 3.26)
project(simple_shell C)

set(CMAKE_C_STANDARD 99)

add_executable(simple_shell
        shell_2.cpp
        shell_2.cpp
        envshell.c
        processinput.cpp
        readline.c
        env.c
        execute.c
        ../../../../eroor.c
        eroor.c
        handlepath.c)

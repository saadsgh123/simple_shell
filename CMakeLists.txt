cmake_minimum_required(VERSION 3.26)
project(simple_shell C)

set(CMAKE_C_STANDARD 99)

add_executable(simple_shell
        shell.c
        shell.c
        envshell.c
        processinput.c
        readline.c
        env.c
        execute.c
        ../../../../eroor.c
        eroor.c
        handlepath.c)

cmake_minimum_required(VERSION 3.21)
project(commc C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(commc
        commc.c
        commc.h
        commc_port.h
        commc_port.c main.c)

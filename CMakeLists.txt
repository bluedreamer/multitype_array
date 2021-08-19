cmake_minimum_required(VERSION 3.16)
project(multitype_array C)

set(CMAKE_C_STANDARD 11)

add_executable(multitype_array main.c multiarray.c multiarray.h)

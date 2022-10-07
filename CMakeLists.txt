cmake_minimum_required(VERSION 3.23)
project(asesorias C)

set(CMAKE_C_STANDARD 99)

add_executable(asesorias main.c HatONames.c cmake-build-debug/HatONames.h)

cmake_minimum_required(VERSION 3.16)
project(21-1-HerreraOcampoMartin)
file(GLOB_RECURSE SOURCES "./src/*".c)
file(GLOB_RECURSE HEADERS "./src/*".h)
add_executable(base_project main.c ${SOURCES} ${HEADERS} ColaCircular.c ColaCircular.h)
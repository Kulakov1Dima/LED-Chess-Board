cmake_minimum_required(VERSION 3.23)
project(LED_Chess_Board C)

set(CMAKE_C_STANDARD 11)
add_compile_options(-g3 -O0)
add_compile_options(-pedantic -Wall -Wextra)

add_executable(LED_Chess_Board main.c matrix.c matrix.h)
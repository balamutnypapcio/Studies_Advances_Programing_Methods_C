cmake_minimum_required(VERSION 3.16)
set(PROJ_NAME "wizualizacja_bryl")
project(${PROJ_NAME} LANGUAGES CXX VERSION 1.0.0)

add_subdirectory(libQGLViewer)
add_subdirectory(serwer_zrodla)

cmake_minimum_required(VERSION 3.14)
project(Tree_project)

set(CMAKE_CXX_STANDARD 20)

set(FILES
    src/source.cpp
    src/BST.h
    src/BST.cpp
)

add_executable(Tree ${FILES})

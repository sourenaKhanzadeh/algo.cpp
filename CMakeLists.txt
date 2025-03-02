# Copyright (c) 2025 Author. All Rights Reserved.
cmake_minimum_required(VERSION "3.19.2")
project(algo_cpp
  VERSION 0.0.1
  DESCRIPTION "Algorithms done in C++"
  LANGUAGES CXX C
)
set(CMAKE_CXX_STANDARD 20)

message("algo.cpp Building SRC Files")
message("===========================")
add_subdirectory(src)

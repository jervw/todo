cmake_minimum_required(VERSION 3.11.0)
project(todo)

set(CMAKE_CXX_STANDARD 14)

add_executable(todo src/main.cc src/todo.cc src/todo.hh)
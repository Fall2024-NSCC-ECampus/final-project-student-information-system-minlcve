cmake_minimum_required(VERSION 3.10)
project(studentinformationsys)

set(CMAKE_CXX_STANDARD 20)


include_directories(include)

add_executable(studentinformationsys src/main.cpp src/functions.cpp)

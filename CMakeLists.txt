cmake_minimum_required(VERSION 3.15)
project(bang)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -pedantic -Wextra")

add_executable(bang src/main.cpp src/DataLoader.cpp src/DataLoader.h)
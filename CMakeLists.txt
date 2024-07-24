cmake_minimum_required(VERSION 3.0)

project(Main VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES *.cpp *.h)

add_executable(Main main.cpp)
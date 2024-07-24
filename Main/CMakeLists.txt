cmake_minimum_required(VERSION 3.0)

project(Main VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE MainFiles "*.cpp" "*.h")

add_executable(Main ${MainFiles})
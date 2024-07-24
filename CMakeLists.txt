cmake_minimum_required(VERSION 3.0)

project(Main VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE MainFiles "Main/*.cpp" "Main/*.h")

add_executable(Main ${MainFiles})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Main)

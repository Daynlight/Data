cmake_minimum_required(VERSION 3.0)

project(CPP-DATA VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE CPPDATAFiles "CPP-DATA/*.cpp" "CPP-DATA/*.h")

add_library(CPP-DATA STATIC ${CPPDATAFiles})

project(Main VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE MainFiles "Main/*.cpp" "Main/*.h")

target_link_libraries(Main PRIVATE CPP-DATA)

add_executable(Main ${MainFiles})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Main)

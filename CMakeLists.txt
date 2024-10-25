file(GLOB_RECURSE cpp_data_files 
    "Data/*.cpp" 
    "Data/*.h")
file(GLOB_RECURSE main_files
    "Main/*.cpp" 
    "Main/*.h")
file (GLOB_RECURSE lib_include_files 
    "vendor/include/")
file(GLOB_RECURSE mysqlcpp_lib_flies 
    "vendor/lib/mysqlcppconn-static"
    "vendor/lib/mysqlcppconnx-static")

cmake_minimum_required(VERSION 3.0)

# [Data]
project(Data VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

add_library(mysql_libs STATIC IMPORTED)
find_library(mysql_libs ${mysqlcpp_lib_flies} PATHS vendor/lib)

add_library(Data STATIC ${cpp_data_files} ${lib_include_files})

# [Main]
project(Main VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

add_executable(Main ${main_files})

target_link_libraries(Main PRIVATE Data)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Main)
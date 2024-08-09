cmake_minimum_required(VERSION 3.0)

project(CPP-DATA VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE CppDataFiles "CPP-DATA/*.cpp" "CPP-DATA/*.h")
file (GLOB_RECURSE LibIncludeFiles "vendor/include/")
file(GLOB_RECURSE LibFiles 
    "vendor/lib/mysqlcppconn-static"
    "vendor/lib/mysqlcppconnx-static")

add_library(Libs STATIC IMPORTED)
foreach(LibFile ${LibFiles})
    set_target_properties(Libs PROPERTIES IMPORTED_LOCATION ${LibFile})
    
endforeach()

add_library(CPP-DATA STATIC ${CppDataFiles} ${LibIncludeFiles})

project(Main VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE MainFiles "Main/*.cpp" "Main/*.h")

add_executable(Main ${MainFiles})

target_link_libraries(Main PRIVATE CPP-DATA)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Main)
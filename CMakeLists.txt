cmake_minimum_required(VERSION 3.0)

add_subdirectory(Main)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Main)

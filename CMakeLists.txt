cmake_minimum_required(VERSION 3.13)

project(raycaster CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

find_package(SDL2 REQUIRED)
include_directories(raycaster ${SDL2_INCLUDE_DIRS})

message(STATUS "SDL2 include dirs: ${SDL2_INCLUDE_DIRS}")
message(STATUS "SDL2 libraries: ${SDL2_LIBRARIES}")

add_compile_options(-Wall -Wextra -Wpedantic -Werror=return-type)

set(SOURCES 
    src/graphics.cc
    src/main.cc
    src/SDL_Manager.cc
)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(raycaster ${SOURCES})

target_link_libraries(raycaster SDL2::SDL2 -lm -lpthread)
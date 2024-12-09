cmake_minimum_required(VERSION 3.5)

project(raycaster CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(SDL2 REQUIRED)

file(GLOB SOURCES "src/*.cc")

add_executable(raycaster ${SOURCES})

target_link_libraries(raycaster SDL2::SDL2)
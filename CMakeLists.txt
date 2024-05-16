cmake_minimum_required(VERSION 3.29)

project(SubEngine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(src)
add_subdirectory(libs)

target_link_libraries(source PRIVATE libs)
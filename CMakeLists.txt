cmake_minimum_required(VERSION 3.29)

project(SubEngine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SubEngine_HEADERS "src/*.h" "src/*.hpp")
file(GLOB_RECURSE SubEngine_SOURCES "src/*.c" "src/*.cpp")

add_executable(${PROJECT_NAME} ${SubEngine_HEADERS} ${SubEngine_SOURCES})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)

add_subdirectory(libs)

target_link_libraries(${PROJECT_NAME} PRIVATE libs)
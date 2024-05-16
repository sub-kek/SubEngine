file(GLOB_RECURSE source_HEADERS "*.h" "*.hpp")
file(GLOB_RECURSE source_SOURCE "*.c" "*.cpp")

add_executable(source ${source_HEADERS} ${source_SOURCE})

target_compile_options(source PRIVATE -Wall -Wextra -Wpedantic)
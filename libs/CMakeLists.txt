add_library(libs INTERFACE)

add_subdirectory("vulkan-headers")
add_subdirectory("sdl")

target_link_libraries(libs INTERFACE Vulkan::Headers SDL3::SDL3)
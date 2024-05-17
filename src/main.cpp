#include <iostream>
#include <stdlib.h>
#include <stdexcept>

#include <SDL.h>
#include <SDL_vulkan.h>

#include <vulkan/vulkan_raii.hpp>

class Nocopyable {
public:
    Nocopyable() = default;

    Nocopyable(const Nocopyable&) = delete;
    const Nocopyable& operator = (const Nocopyable&) = delete;
};

class SDLException : private std::runtime_error, Nocopyable {
    const int code;
public:
    explicit SDLException(const char *message, const int code = 0) : runtime_error(message), code{code} {}

    [[nodiscard]] auto getCode() const noexcept {
        return code;
    }
};

class SDL : Nocopyable {
public:
    explicit SDL(SDL_InitFlags initFlags) {
        if (auto error_code = SDL_Init(initFlags))
            throw SDLException{SDL_GetError(), error_code};
    }

    ~SDL() {
        SDL_Quit();
    }
};

class VulkanLibrary {
public:
    explicit VulkanLibrary(const char *path = nullptr) {
        if (const auto error_code = SDL_Vulkan_LoadLibrary(path))
            throw SDLException{SDL_GetError(), error_code};
    }

    ~VulkanLibrary() {
        SDL_Vulkan_UnloadLibrary();
    }

    [[nodiscard]] auto get_instance_proc_addr() const {
        if (const auto get_instance_proc_addr = (PFN_vkGetInstanceProcAddr)SDL_Vulkan_GetVkGetInstanceProcAddr())
            return get_instance_proc_addr;
        else
            throw SDLException{"Couldn't load vkGetInstanceProcAddr function from the vulkan dynamic library"};
    }
};

int main() {
    SDL sdl{SDL_INIT_VIDEO};
    VulkanLibrary vulkan_library{};

    const vk::raii::Context context{};

    auto version = context.enumerateInstanceVersion();

    SDL_Log("Vulkan API: %d.%d", VK_API_VERSION_MAJOR(version), VK_API_VERSION_MINOR(version));

    return EXIT_SUCCESS;
}
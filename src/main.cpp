#include <iostream>
#include <stdlib.h>
#include <stdexcept>

#include <SDL.h>
#include <SDL_vulkan.h>

class SDLException : private std::runtime_error {
    const int code;
public:
    explicit SDLException(const char *message, const int code = 0) : runtime_error(message), code{code} {}
    [[nodiscard]] auto getCode() const noexcept {
        return code;
    }
};

class SDL {
public:
    explicit SDL(SDL_InitFlags initFlags) {
        if (auto error_code = SDL_Init(initFlags))
            throw SDLException{SDL_GetError(), error_code};
    }

    ~SDL() {
        SDL_Quit();
    }

    SDL(const SDL&) = delete;
    const SDL& operator = (const SDL&) = delete;
};

class VulkanLibrary {
    explicit VulkanLibrary(const char *path = nullptr) {
        if (const auto error_code = SDL_Vulkan_LoadLibrary(path))
            throw SDLException{SDL_GetError(), error_code};
    }

    ~VulkanLibrary() {

    }
};

int main() {
    SDL sdl{SDL_INIT_VIDEO};

    return EXIT_SUCCESS;
}
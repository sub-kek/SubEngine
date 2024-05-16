#include <iostream>
#include <stdlib.h>

#include <vulkan/vulkan.h>

int main() {
    VkApplicationInfo appInfo = {};

    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Test Game";
    appInfo.pEngineName = "SubEngine";

    VkInstanceCreateInfo instanseInfo = {};

    instanseInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instanseInfo.pApplicationInfo = &appInfo;

    VkInstance instance;

    VkResult result = vkCreateInstance(&instanseInfo, 0, &instance);
    if (result == VK_SUCCESS) {
        std::cout << "Successfully created VK instance.\n";
    }

    exit(EXIT_SUCCESS);
}
#include "client_app_platform.h"

#include <iostream>
#include <minecraft/ImagePickingCallback.h>
#include <minecraft/FilePickerSettings.h>
#include <minecraft/MinecraftGame.h>
#include <minecraft/legacy/AppPlatform.h>
#include <hybris/dlfcn.h>
#include <minecraft/Keyboard.h>
#include <mcpelauncher/minecraft_version.h>

const char* ClientAppPlatform::TAG = "ClientAppPlatform";

void ClientAppPlatform::initVtable(void* lib) {
    void** vt = &((void**) hybris_dlsym(lib, "_ZTV21AppPlatform_android23"))[2];
    void** vta = &((void**) hybris_dlsym(lib, "_ZTV19AppPlatform_android"))[2];

    PatchUtils::VtableReplaceHelper vtr (lib, vt, vta);
    vtr.replace("_ZN19AppPlatform_android13getFreeMemoryEv", &ClientAppPlatform::getFreeMemory); // legacy
    vtr.replace("_ZNK19AppPlatform_android13getFreeMemoryEv", &ClientAppPlatform::getFreeMemory);
    vtr.replace("_ZN19AppPlatform_android13getUsedMemoryEv", &ClientAppPlatform::getUsedMemory);
    vtr.replace("_ZN19AppPlatform_android18getAvailableMemoryEv", &ClientAppPlatform::getTotalPhysicalMemory);// legacy
    vtr.replace("_ZN19AppPlatform_android22getTotalPhysicalMemoryEv", &ClientAppPlatform::getTotalPhysicalMemory); // legacy
    vtr.replace("_ZNK19AppPlatform_android22getTotalPhysicalMemoryEv", &ClientAppPlatform::getTotalPhysicalMemory);
    vtr.replace("_ZN19AppPlatform_android14getMemoryLimitEv", &ClientAppPlatform::getMemoryLimit); // legacy
    vtr.replace("_ZNK19AppPlatform_android14getMemoryLimitEv", &ClientAppPlatform::getMemoryLimit);
}

long long ClientAppPlatform::getUsedMemory() {
    return 255 * 1024 * 1024;
}

long long ClientAppPlatform::getFreeMemory() {
    return 128 * 1024 * 1024;
}

long long ClientAppPlatform::getTotalPhysicalMemory() {
    return 384 * 1024 * 1024;
}

long long ClientAppPlatform::getMemoryLimit() {
    return 384 * 1024 * 1024;
}
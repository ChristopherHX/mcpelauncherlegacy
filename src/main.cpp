#include <mcpelauncher/app_platform.h>
#include <minecraft/symbols.h>
#include <dlfcn.h>
#include <log.h>
#include "client_app_platform.h"

extern "C" void mod_init() {
    auto mc = dlopen("libminecraftpe.so", RTLD_LAZY);
    Log::info("MINECRAFT FOUND AT ", "%d", (int)mc);
    Log::info("LOWMEM", "Patch vtable");
    ClientAppPlatform::initVtable(mc);
    Log::info("LOWMEM", "Vtable patched");
}
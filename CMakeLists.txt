cmake_minimum_required (VERSION 2.6)

project(lowmems LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

include(mod-ndk-gnustl/CMakeLists.txt)

add_subdirectory(mcpelauncher-core)
add_subdirectory(minecraft-symbols)
add_subdirectory(logger)

add_library(lowmem SHARED src/main.cpp src/client_app_platform.cpp)
target_include_directories(mcpelauncher-core PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(minecraft-symbols PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(lowmem PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(lowmem mcpelauncher-core minecraft-symbols)
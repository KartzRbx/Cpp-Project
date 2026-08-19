cmake_minimum_required(VERSION 3.20)
project(RmlUiGame CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

include(FetchContent)

# 1. Raylib
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)
FetchContent_MakeAvailable(raylib)

# 2. FreeType (Necessario para o RmlUi desenhar fontes)
FetchContent_Declare(
    freetype
    GIT_REPOSITORY https://github.com/freetype/freetype.git
    GIT_TAG VER-2-13-2
)
set(FT_DISABLE_HARFBUZZ ON CACHE BOOL "" FORCE)
set(FT_DISABLE_PNG ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(freetype)

# Cria o ALIAS que o RmlUi procura
if(NOT TARGET Freetype::Freetype)
    add_library(Freetype::Freetype ALIAS freetype)
endif()

# 3. RmlUi
FetchContent_Declare(
    RmlUi
    GIT_REPOSITORY https://github.com/mikke89/RmlUi.git
    GIT_TAG master
)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(BUILD_SAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(RmlUi)

# 4. Executavel
add_executable(RmlUiGame src/main.cpp)

target_link_libraries(RmlUiGame PRIVATE raylib RmlCore freetype)
target_include_directories(RmlUiGame PRIVATE include)
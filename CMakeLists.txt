cmake_minimum_required(VERSION 3.20)
project(EstudoCpp CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5 CACHE STRING "" FORCE)

include(FetchContent)

# Raylib - janela, input, render 2D e loop de jogo
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

add_executable(EstudoCpp
    src/main.cpp
    src/Classes/Player.cpp
    src/OGL3D/source/OGL3D/Window/OWindow.cpp
    src/OGL3D/source/Classes/Sounds.cpp
)

target_include_directories(EstudoCpp PRIVATE
    include
    src/OGL3D/include
)

target_link_libraries(EstudoCpp PRIVATE raylib)

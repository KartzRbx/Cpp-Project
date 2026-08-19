cmake_minimum_required(VERSION 3.20)
project(EstudoCpp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Inclui a pasta de headers
include_directories(include)

# Busca todos os arquivos .cpp na pasta src
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Gera o executável na pasta bin
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(${PROJECT_NAME} ${SOURCES})
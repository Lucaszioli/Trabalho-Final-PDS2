cmake_minimum_required(VERSION 3.10)
project(Monstrinhos)

file(GLOB GAME_SOURCES "../CPPs/*cpp")
set(SOURCES
    ${GAME_SOURCES}
    test.cpp
    Itens.test.cpp
    Ataques.test.cpp
    Monstrinhos.test.cpp
)

include_directories(../HPPs)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test ${SOURCES})
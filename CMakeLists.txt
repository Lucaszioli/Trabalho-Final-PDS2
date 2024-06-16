cmake_minimum_required(VERSION 3.10)
project(Monstrinhos)

file(GLOB GAME_SOURCES "CPPs/*cpp")

set(SOURCES
    ${GAME_SOURCES}
    principal/main.cpp
)

include_directories(HPPs)

add_executable(Monstrinhos ${SOURCES})
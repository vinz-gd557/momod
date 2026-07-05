cmake_minimum_required(VERSION 3.25)

# Daftarin modul Geode secara otomatis ke CMake
include($ENV{GEODE_SDK}/cmake/GeodeMod.cmake)

project(NovaClient)

add_geode_mod(
    ${PROJECT_NAME}
    src/main.cpp
    src/NovaMenu.cpp
    src/FloatingButton.cpp
)

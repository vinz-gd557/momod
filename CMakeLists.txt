cmake_minimum_required(VERSION 3.25)

find_package(Geode REQUIRED)

project(NovaClient)

add_geode_mod(
    ${PROJECT_NAME}
    src/main.cpp
    src/NovaMenu.cpp
    src/FloatingButton.cpp
)

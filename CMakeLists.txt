cmake_minimum_required(VERSION 3.25)

# Tembak prefix path langsung dari environment SDK bawaan runner Github
if(DEFINED ENV{GEODE_SDK})
    list(APPEND CMAKE_PREFIX_PATH $ENV{GEODE_SDK})
endif()

project(NovaClient)

find_package(Geode REQUIRED)

add_geode_mod(
    ${PROJECT_NAME}
    src/main.cpp
    src/NovaMenu.cpp
    src/FloatingButton.cpp
)

cmake_minimum_required(VERSION 3.25)

# 1. Wajib jalankan project() duluan biar toolchain compiler ke-load sempurna
project(NovaClient)

# 2. Cari package Geode bawaan GitHub runner SDK
find_package(Geode REQUIRED)

# 3. Daftarin file cpp lo ke mod-nya
add_geode_mod(
    ${PROJECT_NAME}
    src/main.cpp
    src/NovaMenu.cpp
    src/FloatingButton.cpp
)

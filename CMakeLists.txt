cmake_minimum_required(VERSION 3.25)

# Nama project wajib diset sebelum find_package
project(NovaClient VERSION 1.0.0)

# Paksa CMake baca SDK langsung dari path default Ubuntu Runner
# Karena environment variable GEODE_SDK selalu zonk di GitHub Actions
list(APPEND CMAKE_PREFIX_PATH "/home/runner/.local/share/Geode/sdk")

find_package(Geode REQUIRED)

# Standar Geode v5, otomatis nge-scan folder src/ kamu!
setup_geode_mod(${PROJECT_NAME})

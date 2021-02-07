cmake_minimum_required(VERSION 3.15)

# Project name
project(librespot-app)
# C++ version
set(CMAKE_CXX_STANDARD 17)

# C++ headers and generated headers frp, Rust
include_directories(${CMAKE_BINARY_DIR}/librespot-cpp)
include_directories(src)

# Major performance improvement, but doesn't work on all compilers
set(ENABLE_LTO OFF)

# Source file
add_executable(librespot-app src/main.cpp)

# librespot-cpp
add_subdirectory(librespot-cpp)
target_link_libraries(librespot-app librespot-cpp)
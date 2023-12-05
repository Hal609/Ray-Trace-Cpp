# For MacOS -> mkdir build && cd build && cmake -DCMAKE_C_COMPILER=gcc-13 -DCMAKE_CXX_COMPILER=g++-13 .. && cmake --build .

cmake_minimum_required(VERSION 3.10) # Specify the minimum version for CMake

# Set the project name and version
project(Ray Tracer v0.9)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# List of source files
set(SRCS
    src/light.cpp
    src/pixel_buffer.cpp
    src/ray.cpp
    src/renderer.cpp
    src/sdl_manager.cpp
    src/sphere.cpp
    src/color.cpp
    main.cpp
)

# Find the OpenMP package
find_package(OpenMP REQUIRED)

# Compiler options
add_compile_options(-g -O3 -Wall -Wextra -Wpedantic -Wno-unused-variable)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/src/include /usr/local/include)

# Add library directories
link_directories(
    src/lib
    /usr/local/lib
)

# Add the executable
add_executable(${PROJECT_NAME} ${SRCS})

# Linker options
target_link_directories(${PROJECT_NAME} PRIVATE /usr/local/lib)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 m pthread)

# Link the OpenMP library
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
endif()


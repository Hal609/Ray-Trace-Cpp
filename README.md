# C++ Raytrace Renderer using SDL2

A Raytrace Renderer implemented in C++ using the SDL2 library, designed to demonstrate real-time ray tracing rendering techniques.

### Features

- Near real-time ray tracing rendering.
- Support for multiple light sources.
- Scenes can be modified using external text files.
- Implementation of shadows, reflections, and specular highlights.
- Cross-platform compatibility with SDL2.

## Dependencies

To build and run the Raytrace Renderer, you need the following dependencies:

- C++ Compiler (GCC or Clang recommended)
- SDL2 Library
- CMake

### Installing dependencies on MacOS

1. Ensure Homebrew is installed
```
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
2. Install dependencies
```
brew install gcc sdl2 cmake
```

### Installing dependencies on Linux

```
sudo apt-get update
sudo apt-get install build-essential libsdl2-dev cmake
```

## Building Instructions

### Building for Linux and MacOS

Follow these steps to build the Raytrace Renderer:

1. Clone the repository:
```
git clone https://github.com/Hal609/Ray-Trace-Cpp.git
cd raytrace-renderer
```
2. Create a build directory and navigate to it:
```
mkdir build
cd build
```

3. Run CMake to configure the project and then build it:
```
cmake -DCMAKE_C_COMPILER=gcc-13 -DCMAKE_CXX_COMPILER=g++-13 ..
cmake --build .
```
4. To run the renderer, navigate to the root directory and execute:
```
./main
```

## Usage

After building the project, you can run the renderer and display a window with a rendered scene. To edit the scene simply modify sphereData.txt and lightData.txt.

Sphere data consists of: radius, x position, y position, z position, colour, specular exponent and reflection coefficient.

## Contributing

Contributions to the Raytrace Renderer are welcome! If you have suggestions for improvements or encounter any issues, please feel free to open an issue or submit a pr.

## License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE.md) file for details.
# Archon
Hobby OpenGL engine


# Build System & Dependency Management
This project utilises [CMake](https://cmake.org/) to orchestrate building. \
Dependencies are handled via [conan](https://conan.io/).
## Installing required dependencies & Initial build
Invoke `conan install . --build=missing` - this will download the required dependencies \
and the needed CMakeToolchain files to build the application. \
Once this has been called, change directory to `build` & invoke 
```
cmake .. -DCMAKE_TOOLCHAIN_FILE="Release\generators\conan_toolchain.cmake"
cmake --build . --config Release  // Release build
cmake --build . --config Debug // Debug build
```
to build the release / debug binaries. \
They will be located at: \
```
build/Release/Archon.exe
build/Debug/Archon.exe
```

One can also utilise Conan for the initial build by invoking: 
```
conan build . --build=missing -s build_type=<BUILD_TYPE>
```

Currently this has only been tested on my machine (64-bit Windows, MSVC).

Testing on other archs / OS's is planned.

# Repository Structure

## .vscode
Contains vscode config files for debugging & intellisense
## Assets
TBD
## build
Generated upon building the library. \
Holds built binaries.
## examples
### 0_link_example
Simple example to show that the project can be linked into an application & can be consumed via Conan. \
This example showcases the creation of a window of size 1000 x 1000 pixels. \
The main aim was to test that we could successfully create & consume the Archon conan package with CMake.
## include
Header files needed for Archon.
## src
Holds the implementation files for Archon.
## CMakeLists.txt
Instructs CMake how to compile the library.
## conanfile.py
Describes the dependenies needed by Conan & how to build / package the library.
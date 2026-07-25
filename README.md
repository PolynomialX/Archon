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
## conan_history
A history of the library's Conan packages.
Utilise `conan cache restore /path/to/conan_cache_save.tgz` to load this into the Conan Cache. \
Once loaded, the examples should be able to find and use them. \
Before running the examples, consult the `Conanfile.py` to see which package is needed.
# Release History
|Version|Date|Details|
|---|---|---|
|0.0.3|25 Jul 2026| Upgraded software design - changed to using a window factory instead of window manager class - still all WIP|
|0.0.2|08 Jul 2026| First usable Conan package. Functionality to open a window & rudimental render loop that keeps the window open until exit button is used.|

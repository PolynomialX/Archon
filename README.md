# Archon
Hobby OpenGL engine


# Build System & Dependency Management
This project utilises [CMake](https://cmake.org/) to orchestrate building. \
Dependencies are handled via [conan](https://conan.io/).
## Installing required dependencies
Invoke `conan install . --build=missing` - this will download the required dependencies \
and the needed CMakeToolchain files to build the application. \
Once this has been called, change directory to `build` & invoke 
```
cmake .. -DCMAKE_TOOLCHAIN_FILE="Release\generators\conan_toolchain.cmake"
cmake --build . --config Release  
```
to build the release binary which will be generated at: \
```build/Release/Archon.exe```
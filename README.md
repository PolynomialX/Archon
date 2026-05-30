# Archon
Hobby OpenGL engine


# Build System
This project utilises [CMake](https://cmake.org/) to orchestrate building.
## CMLs
The top-level CML file is located in the root directory of the project. This currently just dictates the minimum required version of CMake and informs CMake that we are infact building an application named 'Archon'. \
To generate the files necessary for building use \
```cmake -B build``` - this will generate the necessary files for building the application. \
To build the application run either \
```cmake --build build --config Debug``` \
```cmake --build build --config Release``` \
to generate either Debug / Release builds respectively. \
The resulting application can be found in \
```build/Archon/<CFG>``` \
where ```<CFG>``` is either ```Debug``` or ```Release```,
# GOAL 0

The first goal for this project is to get a reliable build system working. \
Following online tutorials it's a bit of a pain downloading the required deps, finding the right bins etc. \
So our first goal is to use Conan & CMake to handle downloading dependencies & building apps.

We also want our Conanfile to be able to bundle up the application so we could in theory host the binary \
and let people grab it! \


Checklist
- [ ] Conanfile
    - [x] Dependencies described
    - [ ] Project layout described
    - [ ] Build process described
    - [x] Metadata described
    - [ ] Package creation described
- [x] CMakeLists.txt

- [x] VSCode project files\
Had to add the c_cpp_properties.json & point to conan cache for intellisense to pick up external headers.

- [ ] Testing
    - [ ] Fresh clone, build & intellisense checked
    - [ ] Describe Archon as a dependency and see if we can build from source & pull in built binary.

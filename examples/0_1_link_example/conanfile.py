from conan import ConanFile
from conan.tools.cmake import CMakeToolchain
from conan.tools.cmake import CMakeDeps
from conan.tools.cmake import cmake_layout
from conan.tools.cmake import CMake

class example_0(ConanFile):
    name = "example_0"
    version = "1.0"
    description = """Example consumption of Archon"""
    author = "Robin Andrew Holt"
    settings = "os", "compiler", "arch", "build_type"
    package_type = "application"

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def layout(self):
        cmake_layout(self)
    
    def build_requirements(self):
        self.tool_requires("cmake/4.0.2")

    def requirements(self):
        self.requires("archon/0.0.3")

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
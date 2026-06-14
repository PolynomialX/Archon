from conan import ConanFile
from conan.tools.cmake import CMakeToolchain
from conan.tools.cmake import CMakeDeps
from conan.tools.cmake import cmake_layout
from conan.tools.cmake import CMake

class archon(ConanFile):
    name = "archon"
    description = """Archon - A C++ OpenGL Hobby Engine"""
    author = "Robin Andrew Holt"
    url = "https://github.com/PolynomialX/Archon"
    settings = "os", "compiler", "arch", "build_type"
    package_type = "application"

    def generate(self):
        # This was required for my machine...
        # Probably need to test this on other machines to see
        # what conditional logic is needed here.
        tc = CMakeToolchain(self,generator="Visual Studio 17 2022")
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def layout(self):
        cmake_layout(self)

    def build_requirements(self):
        self.tool_requires("cmake/4.0.2")

    def requirements(self):
        self.requires("glad/0.1.34") # Later versions of glad use gl.h? Want to follow tutorial so we use this earlier version
        self.requires("glfw/3.4")

    def configure(self):
        self.options['glad'].shared = False
        self.options['glad'].fPIC = True
        self.options['glad'].no_loader = False
        self.options['glad'].spec = 'gl'
        self.options['glad'].gl_profile = 'core'
    
    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

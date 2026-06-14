from conan import ConanFile
from conan.tools.cmake import CMakeToolchain
from conan.tools.cmake import cmake_layout
from conan.tools.cmake import CMake

class archon(ConanFile):
    name = "archon"
    description = """Archon - A C++ OpenGL Hobby Engine"""
    author = "Robin Andrew Holt"
    url = "https://github.com/PolynomialX/Archon"
    settings = "os", "arch", "build_type"

    generators = "CMakeToolchain", "CMakeDeps"
    def layout(self):
        cmake_layout(self)

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

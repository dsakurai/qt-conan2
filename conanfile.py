from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout, CMakeDeps, CMakeToolchain


class QtConan(ConanFile):
    name = "qt-conan2"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"
    
    exports_sources = "CMakeLists.txt"

    requires = ["qt/[>=6.11 <12]",
                ]
    default_options = {
        "qt/*:shared": True,
        "qt/*:gui": True,
        "qt/*:widgets": True,
        "qt/*:qtwebengine": True,
        "qt/*:qtdeclarative": True, # used for QtWebEngine
        "qt/*:qtwebchannel": True, # used for QtWebEngine
        "qt/*:with_pq": False,
        "&:tools.env.virtualenv:powershell": True, # Generate a PowerShell script that activates the virtual environment
        # "libiconv/*:tools.env.virtualenv:powershell": False,
    }

    def layout(self):
        cmake_layout(self)

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()

        tc = CMakeToolchain(self)
        # Ensure C++ standard is at least 17
        tc.variables["CMAKE_CXX_STANDARD"] = 17
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

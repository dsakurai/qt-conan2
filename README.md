# qt-conan2

## Conan Qt6 recipe

This project includes a `conanfile.py` that requests Qt6 with `widgets` and optionally `qtwebengine` enabled. WebEngine requires shared Qt builds and additional system build tools (nodejs, ninja, bison/flex on some platforms).

Make sure you have enabled long paths in Windows Settings.

Set the `CONAN_HOME` env var to some folder without a whitespace (because libiconv fails to build otherwise).

### Auto build on VSCode 

Press F5

### Manual build (using local conan executable):

```powershell
.\venv\Scripts\activate # Assuming you did `uv sync`
mkdir build
cd build
#
.\.venv\Scripts\conan.exe install .. --build=missing -s build_type=Release
```

Or, for a global config of the env var:
```
[Environment]::SetEnvironmentVariable("CONAN_HOME", "C:\NoWhitespace\conan-cache", "User")
```

Configure
```
cmake --preset conan-default
```

Build
```
cmake --build --preset conan-release
```

Run
```
& "build\generators\conanrun.ps1"
build\Release\example.exe
```

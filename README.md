# qt-conan2

## Conan Qt6 recipe

This project includes a `conanfile.py` that requests Qt6 with `widgets` and optionally `qtwebengine` enabled. WebEngine requires shared Qt builds and additional system build tools (nodejs, ninja, bison/flex on some platforms).

Make sure you have enabled long paths in Windows Settings.

Quick install (using local conan executable):

```powershell
.\venv\Scripts\activate # Assuming you did `uv sync`
mkdir build
cd build
$env:CONAN_HOME = "C:\NoWhitespace\conan-cache" # Need some dir without whitespaces due to a bug in dependencies.
#
#                                                                          PowerShell support
.\.venv\Scripts\conan.exe install .. --build=missing -s build_type=Release -c tools.env.virtualenv:powershell=pwsh
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

# qt-conan2

## Conan Qt6 recipe

This project includes a `conanfile.py` that requests Qt6 with `widgets` and optionally `qtwebengine` enabled. WebEngine requires shared Qt builds and additional system build tools (nodejs, ninja, bison/flex on some platforms).

Make sure you have enabled long paths in Windows Settings.

Quick install (using local conan executable):

```powershell
.\venv\Scripts\activate # Assuming you did `uv sync`
mkdir build
cd build
$env:CONAN_HOME = "C:\NoWhitespace\conan-cache"
.\.venv\Scripts\conan.exe install .. -s build_type=Release --build=missing
```

Or, for a global config of the env var:
```
[Environment]::SetEnvironmentVariable("CONAN_HOME", "C:\NoWhitespace\conan-cache", "User")
```
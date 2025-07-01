# MinesweeperCPP
This is my project for uni, using Conan and CMake

To build you need:
- Conan 2 (and make sure that you could access it through terminal)
- CMake (at least 3.24)
- Enter this to terminal in project's root directory:

```
mkdir build && cd build
conan install .. --output-folder=. --build=missing
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```
# MinesweeperCPP
This is my project for uni, using Conan and CMake

Warning! If you're just a lurker and don't have access to private server, remove dice_lib/1.0.0@sum1ko05 from conanfile.txt!

This line would be removed if teacher will accept my work

To build you need:
- Conan 2 (and make sure that you could access it through terminal)
- CMake (at least 3.24)
- Enter this to terminal in project's root directory:

```
mkdir build && cd build
conan install .. --output-folder=. --build=missing
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

You may add -DINCLUDE_DICE_LIB=On into configuring CMake line, but if you're just a lurker - just ignore it
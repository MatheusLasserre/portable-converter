 # Project

 A C++ file converter;

 ## Recommended Commands to build project

 ### CMake Setup

 ```bash
 cmake -B build
 ```
 ### CMake Build
 ```bash
 cmake --build build
 ```

### Fancy Terminal Alias

1. Config Build type to Debug, Compile and Run with fancy prints
 ```bash
echo '\033[1;32mBuild Logs:\033[0m' && 
cmake -B build -DCMAKE_BUILD_TYPE=Debug && 
echo '\033[1;32mCompile Logs:\033[0m' && 
cmake --build build && echo '\n\033[1;32mOutput:\033[0m' && 
./bin/Linux64/Debug/main
 ```
  Suggested alias - ccbuild
  
2. Config Build type to Debug, Compile and Run with fancy prints ()
 ```bash
echo '\033[1;32mBuild Logs:\033[0m' && 
cmake -B build -DCMAKE_BUILD_TYPE=Release && 
echo '\033[1;32mCompile Logs:\033[0m' && 
cmake --build build && echo '\n\033[1;32mOutput:\033[0m' && 
./bin/Linux64/Debug/main
 ```
 Suggested alias - ccrbuild

 All parameters are configured to Linux64 systems, so you may need to change for it to work as expected.
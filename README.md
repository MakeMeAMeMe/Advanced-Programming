# Advanced-Programming

### Install

```bash
./vcpkg/bootstrap-vcpkg.sh

# cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=./vcpkg/scripts/buildsystems/vcpkg.cmake 
cmake -B [build directory] -S . -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake 
# cmake --build build
cmake --build [build directory]
```

#### Adding Dependencies
```bash
vcpkg install [packages to install]
```

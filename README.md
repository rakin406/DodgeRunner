# Dodge Runner

A dodging game.

## Getting Started

### Dependencies

* Clang or GCC compiler
* Conan
* CMake
* Ninja

### Executing program

* The first command below uses git. You can also download zip version.
```bash
git clone https://github.com/rakin406/DodgeRunner.git && cd DodgeRunner
mkdir build && cd build
conan install .. --build=missing
cmake .. -G Ninja
ninja
./bin/DodgeRunner
```

## Author

Rakin Rahman

## License

This project is licensed under the MIT License - see the LICENSE.md file for details

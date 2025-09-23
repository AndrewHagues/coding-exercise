# Coding Exercise

This repository contains my coding exercise submission for the Dexory Senior C++ Software Engineer role.

This code has been built and tested on Ubuntu 24.04 LTS using the g++-14 compiler.

CMake is used as the build system and will automatically fetch and build the dependencies:
 - [LodePNG](https://lodev.org/lodepng/) - Used for generating the output PNG files.
 - [GTest](https://github.com/google/googletest) - Used for managing the test cases. 

After checking out this repositiory and navigating to the project root directory the code can be built by executing the following commands:

```
cmake -S . -B ./build
cmake --build ./build
```

This will the build the executable, named `solution` and the test cases. 

The executable can be found in the `build/src/` directory. By default the code assumes the input `test.txt` file is in the project root. The code can be run by executing the following command from the project root:

```
./build/src/solution
```

An alternative input file name or location can be passed as a command line argument:

```
./build/src/solution path/to/input/file.txt
```

To run the tests navigate to the bulid directory and run `ctest`.

Pre-generated output PNG files can be found in the `results/` directory.

Code documentation has been generated using Doxygen and can be viewed by opening the `docs/html/index.html` file in a browser.

Suggestions for part 4 (follow up question) can be found in the `discussion.txt` file.
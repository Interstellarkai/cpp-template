[![Actions Status](https://github.com/filipdutescu/modern-cpp-template/workflows/MacOS/badge.svg)](https://github.com/filipdutescu/modern-cpp-template/actions)
[![Actions Status](https://github.com/filipdutescu/modern-cpp-template/workflows/Windows/badge.svg)](https://github.com/filipdutescu/modern-cpp-template/actions)
[![Actions Status](https://github.com/filipdutescu/modern-cpp-template/workflows/Ubuntu/badge.svg)](https://github.com/filipdutescu/modern-cpp-template/actions)
[![codecov](https://codecov.io/gh/filipdutescu/modern-cpp-template/branch/master/graph/badge.svg)](https://codecov.io/gh/filipdutescu/modern-cpp-template)
[![GitHub release (latest by date)](https://img.shields.io/github/v/release/filipdutescu/modern-cpp-template)](https://github.com/filipdutescu/modern-cpp-template/releases)

# Modern C++ Template for Advent of Code

This is a modern C++ template project specifically designed for solving Advent of Code challenges. It provides a structured environment for implementing solutions with test-driven development (TDD) in mind.

## Features

- Modern C++17 support with std::filesystem for robust file handling
- GoogleTest integration for unit testing
- Organized project structure for multiple years and days
- Flexible build system with warning controls
- Input file management
- Test-driven development support

## Project Structure

```
.
├── src/
│   └── advent_of_code/
│       ├── 2015/
│       │   ├── day01/
│       │   │   ├── day01.cpp      # Implementation
│       │   │   ├── day01.hpp      # Header
│       │   │   ├── main.cpp       # Main executable
│       │   │   └── input.txt      # Puzzle input
│       │   └── ...
│       └── ...
├── test/
│   └── advent_of_code/
│       ├── 2015/
│       │   ├── day01_test.cpp
│       │   └── ...
│       └── ...
└── ...
```

## Getting Started

### Prerequisites

- CMake 3.31 or higher
- C++17 compatible compiler
- Make

### Building

The project uses a simple Make-based build system with the following commands:

```bash
# Build the project (warnings disabled by default)
make build

# Build with warnings enabled
make build WARNINGS=on

# Run all tests
make test

# Run tests with warnings enabled
make test WARNINGS=on

# Run a specific day's solution
make run day=2015_day01

# Clean build directory
make clean
```

### Input Files

Each day's solution requires an `input.txt` file containing the puzzle input. Place these files in the corresponding day's directory:

```
src/advent_of_code/YYYY/dayXX/input.txt
```

For example, for Day 1 of 2015:
```
src/advent_of_code/2015/day01/input.txt
```

### Development Workflow

1. Create a new day's solution:
   - Create directory: `src/advent_of_code/YYYY/dayXX/`
   - Add implementation files: `dayXX.cpp`, `dayXX.hpp`, `main.cpp`
   - Add input file: `input.txt`
   - Add test file: `test/advent_of_code/YYYY/dayXX_test.cpp`

2. Implement your solution:
   - Write tests first (TDD approach)
   - Implement the solution
   - Run tests: `make test`
   - Run solution: `make run day=YYYY_dayXX`

3. Build options:
   - Default build (no warnings): `make build`
   - Build with warnings: `make build WARNINGS=on`
   - Clean build: `make clean`

## Testing

The project uses GoogleTest for unit testing. Test files should be placed in the `test/advent_of_code/` directory, following the same year/day structure as the source files.

Example test file structure:
```cpp
#include <gtest/gtest.h>
#include "day01.hpp"

TEST(Day01Test, Part1) {
    // Your test cases here
}

TEST(Day01Test, Part2) {
    // Your test cases here
}
```

Run tests with:
```bash
make test
```

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- [Advent of Code](https://adventofcode.com/) for the programming challenges
- [GoogleTest](https://github.com/google/googletest) for the testing framework
- [Modern C++ Template](https://github.com/cpp-best-practices/cpp_starter_project) for the base project structure

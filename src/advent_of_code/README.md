# Advent of Code Solutions

This directory contains solutions for Advent of Code challenges, organized by year and day.

## Directory Structure

```
src/advent_of_code/
├── 2015/
│   ├── day01/
│   │   ├── day01.cpp      # Implementation
│   │   ├── day01.hpp      # Header
│   │   ├── main.cpp       # Main executable
│   │   └── input.txt      # Puzzle input
│   ├── day02/
│   │   └── ...
│   └── ...
├── 2016/
│   └── ...
└── ...
```

## Input Files

Each day's solution requires an `input.txt` file containing the puzzle input. The file should be placed in the corresponding day's directory:

```
src/advent_of_code/YYYY/dayXX/input.txt
```

For example, for Day 1 of 2015:
```
src/advent_of_code/2015/day01/input.txt
```

## Running Solutions

To run a solution:

1. Create the input file in the correct location
2. Build the project: `make build-advent`
3. Run the solution: `make run-day day=YYYY_dayXX`

Example:
```bash
# For Day 1 of 2015
make run-day day=2015_day01
```

## Testing

Test files are located in the `test/advent_of_code/` directory, following the same year/day structure:

```
test/advent_of_code/
├── 2015/
│   ├── day01_test.cpp
│   ├── day02_test.cpp
│   └── ...
└── ...
```

Run all tests with:
```bash
make test-advent
``` 
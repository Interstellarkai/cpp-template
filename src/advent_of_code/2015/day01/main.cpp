#include <advent_of_code/2015/day01/day01.hpp>
// #include "day01.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

auto main() noexcept -> int {
    // Try multiple possible locations for the input file
    const std::vector<std::filesystem::path> possible_paths = {
        "input.txt",  // For make run (executable in build/bin/Debug)
        "src/advent_of_code/2015/day01/input.txt"  // For direct execution from project root
    };

    std::ifstream input_file;
    std::filesystem::path used_path;
    
    // Try each possible path
    for (const auto& path : possible_paths) {
        input_file.open(path);
        if (input_file.is_open()) {
            used_path = path;
            break;
        }
    }

    if (!input_file.is_open()) {
        std::cerr << "Failed to open input file. Tried the following paths:\n";
        for (const auto& path : possible_paths) {
            std::cerr << "  - " << path << '\n';
        }
        return 1;
    }

    std::string input;
    std::getline(input_file, input);
    input_file.close();

    // Solve both parts
    const int part1_result = advent_of_code::year2015::day01::Solution::solve_part1(input);
    const int part2_result = advent_of_code::year2015::day01::Solution::solve_part2(input);

    // Print results
    std::cout << "Part 1: " << part1_result << '\n';
    std::cout << "Part 2: " << part2_result << '\n';

    return 0;
} 
#include <filesystem>
#include <iostream>
#include <vector>

#include "day02.hpp"

auto main() noexcept -> int
{
  // Try multiple possible locations for the input file
  const std::vector<std::filesystem::path> possible_paths = {
    "input.txt",                               // For make run (executable in build/bin/Debug)
    "src/advent_of_code/2015/day02/input.txt"  // For direct execution from project root
  };

  const std::vector<std::vector<int>> input = advent_of_code::year2015::day02::Solution::parse_input(possible_paths);

  // Solve both parts
  const int part1_result = advent_of_code::year2015::day02::Solution::solve_part1(input);
  const int part2_result = advent_of_code::year2015::day02::Solution::solve_part2(input);

  // Print results
  std::cout << "Part 1: " << part1_result << '\n';
  std::cout << "Part 2: " << part2_result << '\n';

  return 0;
}
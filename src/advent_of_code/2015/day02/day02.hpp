#pragma once

#include <filesystem>
#include <vector>

namespace advent_of_code::year2015::day02 {

class Solution {
public:
    // Part 1 solution
    static int solve_part1(const std::vector<std::vector<int>>& input);

    // Part 2 solution
    static int solve_part2(const std::vector<std::vector<int>>& input);

    // Helper functions
    static std::vector<std::vector<int>> parse_input(const std::vector<std::filesystem::path>& possible_paths);
};

} // namespace advent_of_code::year2015::day02
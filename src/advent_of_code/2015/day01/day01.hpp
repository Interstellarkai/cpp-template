#pragma once

#include <string>
#include <vector>

namespace advent_of_code::year2015::day01 {

class Solution {
public:
    // Part 1 solution
    static int solve_part1(const std::string& input);
    
    // Part 2 solution
    static int solve_part2(const std::string& input);
    
    // Helper functions
    static std::vector<std::string> parse_input(const std::string& input);
};

} // namespace advent_of_code::year2015::day01 
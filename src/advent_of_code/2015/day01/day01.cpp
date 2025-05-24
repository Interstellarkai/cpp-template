#include "day01.hpp"
#include <string>
#include <vector>
#include <sstream>

namespace advent_of_code::year2015::day01 {

int Solution::solve_part1(const std::string& input) {
    int floor = 0;
    for (const char chr : input) {
        if (chr == '(') {
            floor++;
        } else if (chr == ')') {
            floor--;
        }
    }
    return floor;
}

int Solution::solve_part2(const std::string& input) {
    int floor = 0;
    int position = 0;
    for (const char chr : input) {
        position++;
        if (chr == '(') {
            floor++;
        } else if (chr == ')') {
            floor--;
        }
        
        if (floor == -1) {
            return position;
        }
    }
    return -1; // Never entered basement
}

std::vector<std::string> Solution::parse_input(const std::string& input) {
    std::vector<std::string> lines;
    std::istringstream iss(input);
    std::string line;
    while (std::getline(iss, line)) {
        if (!line.empty()) {
            lines.push_back(line);
        }
    }
    return lines;
}

} // namespace advent_of_code::year2015::day01 
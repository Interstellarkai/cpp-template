#include "advent_of_code/2015/day02/day02.hpp"
#include <gtest/gtest.h>

using namespace advent_of_code::year2015::day02;

TEST(Day02Test, Part1Example) {
    EXPECT_EQ(Solution::solve_part1({{2,3,4}}), 58);
    EXPECT_EQ(Solution::solve_part1({{1,1,10}}), 43);
}

TEST(Day02Test, Part2Example) {
    EXPECT_EQ(Solution::solve_part2({{2, 3, 4}}), 34);
    EXPECT_EQ(Solution::solve_part2({{1,1,10}}), 14);
}

auto main(int argc, char** argv) -> int {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 
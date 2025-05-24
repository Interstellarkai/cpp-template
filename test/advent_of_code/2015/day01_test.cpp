#include "advent_of_code/2015/day01/day01.hpp"
#include <gtest/gtest.h>

using namespace advent_of_code::year2015::day01;

TEST(Day01Test, Part1Example) {
    EXPECT_EQ(Solution::solve_part1("(())"), 0);
    EXPECT_EQ(Solution::solve_part1("()()"), 0);
    EXPECT_EQ(Solution::solve_part1("((("), 3);
    EXPECT_EQ(Solution::solve_part1("(()(()("), 3);
    EXPECT_EQ(Solution::solve_part1("))((((("), 3);
    EXPECT_EQ(Solution::solve_part1("())"), -1);
    EXPECT_EQ(Solution::solve_part1("))("), -1);
    EXPECT_EQ(Solution::solve_part1(")))"), -3);
    EXPECT_EQ(Solution::solve_part1(")())())"), -3);
}

TEST(Day01Test, Part2Example) {
    EXPECT_EQ(Solution::solve_part2(")"), 1);
    EXPECT_EQ(Solution::solve_part2("()())"), 5);
}

auto main(int argc, char** argv) -> int {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 
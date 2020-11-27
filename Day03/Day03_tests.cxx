//
//  Advent of Code 2015 Tests: Day 3
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/07/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <sstream>

namespace AocDay03{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay03;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("2572", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("2631", solveb());
}

TEST(Example,Test1) {
    stringstream ss{">"};
	EXPECT_EQ(2,trackHouses(ss));
}

TEST(Example,Test2) {
    stringstream ss{"^>v<"};
    EXPECT_EQ(4,trackHouses(ss));
}

TEST(Example,Test3) {
    stringstream ss{"^v^v^v^v^v"};
    EXPECT_EQ(2,trackHouses(ss));
}

TEST(Example,Test1R) {
    stringstream ss{"^v"};
    EXPECT_EQ(3,trackHousesWRobo(ss));
}

TEST(Example,Test2R) {
    stringstream ss{"^>v<"};
    EXPECT_EQ(3,trackHousesWRobo(ss));
}

TEST(Example,Test3R) {
    stringstream ss{"^v^v^v^v^v"};
    EXPECT_EQ(11,trackHousesWRobo(ss));
}

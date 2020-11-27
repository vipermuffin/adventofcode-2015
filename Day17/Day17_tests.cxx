//
//  Advent of Code 2015 Tests: Day 17
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/20/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day17.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay17{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay17;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("1638", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("17", solveb());
}

TEST(Example,Test1) {
	vector<int> x {20,15,10,5,5};
	EXPECT_EQ(4,FindCombinations(x, 25));
}

TEST(Example,Test2) {
	vector<int> x {20,5};
	EXPECT_EQ(true,FitsLiquid(x, 25));
}

TEST(Example,Test3) {
    vector<int> x {25,5};
    EXPECT_EQ(false,FitsLiquid(x, 25));
}

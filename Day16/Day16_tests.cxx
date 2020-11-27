//
//  Advent of Code 2015 Tests: Day 16
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/19/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day16.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay16{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay16;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("373", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("260", solveb());
}

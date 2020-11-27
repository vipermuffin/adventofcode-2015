//
//  Advent of Code 2015 Tests: Day 24
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/28/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day24.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay24{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay24;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("10439961859", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("72050269", solveb());
}

TEST(Example,Test1) {
	int x = 0;
	EXPECT_EQ(0,x);
}

TEST(Example,Test2) {
	int x = 0;
	EXPECT_EQ(0,x);
}

TEST(Example,Test3) {
	int x = 0;
	EXPECT_EQ(0,x);
}

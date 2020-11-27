//
//  Advent of Code 2015 Tests: Day 23
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/28/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day23.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay23{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay23;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("255", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("334", solveb());
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

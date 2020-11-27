//
//  Advent of Code 2015 Tests: Day 9
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay09{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay09;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("141", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("736", solveb());
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



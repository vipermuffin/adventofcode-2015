//
//  Advent of Code 2015 Tests: Day 25
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/29/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day25.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay25{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay25;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("2650453", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("---", solveb());
}

TEST(Example,Test1) {
	auto x = calculateCode(20151125);
	EXPECT_EQ(31916031,x);
}

TEST(Example,Test2) {
	EXPECT_EQ(18749137,getCodeAt(1, 2));
    EXPECT_EQ(21629792,getCodeAt(2, 2));
    EXPECT_EQ(27995004,getCodeAt(6, 6));
}

TEST(Example,Test3) {
	int x = 0;
	EXPECT_EQ(0,x);
}

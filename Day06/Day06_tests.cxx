//
//  Advent of Code 2015 Tests: Day 6
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay06{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay06;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("400410", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("15343601", solveb());
}

TEST(Example,TestCount) {
    vector<vector<bool>> x {{true,false,true},{false,true,false},{true,false,true}};
	EXPECT_EQ(5,numLightsOn(x));
}

TEST(Example,Test2) {
	int x = 0;
	EXPECT_EQ(0,x);
}

TEST(Example,Test3) {
	int x = 0;
	EXPECT_EQ(0,x);
}

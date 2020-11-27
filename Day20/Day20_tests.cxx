//
//  Advent of Code 2015 Tests: Day 20
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/26/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day20.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay20{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay20;

TEST(SolvePartA, FinalSolution) {
    EXPECT_EQ("665280", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("705600", solveb());
}

TEST(Example,Test1) {
	int x = 31;
	EXPECT_EQ(3,findLowestHouseWithAtLeastXPresents(x,10,0));
}

TEST(Example,Test2) {
    int x = 60;
    EXPECT_EQ(4,findLowestHouseWithAtLeastXPresents(x,10,0));
}

TEST(Example,Test3) {
    int x = 150;
    EXPECT_EQ(8,findLowestHouseWithAtLeastXPresents(x,10,0));
}


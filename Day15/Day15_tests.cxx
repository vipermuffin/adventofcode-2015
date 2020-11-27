//
//  Advent of Code 2015 Tests: Day 15
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/19/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day15.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay15{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay15;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("18965440", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("15862900", solveb());
}

TEST(Example,Test1) {
    std::string input1 {"Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8"};
    std::string input2 {"Cinnamon: capacity 2, durability 3, flavor -2, texture -1, calories 3"};
    Ingredient i1{input1};
    Ingredient i2{input2};
    auto x = FindMaxScore(i1, i2);
	EXPECT_EQ(62842880,x.first);
}

TEST(Example,Test2) {
	int x = 0;
	EXPECT_EQ(0,x);
}

TEST(Example,Test3) {
	int x = 0;
	EXPECT_EQ(0,x);
}

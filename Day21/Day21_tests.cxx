//
//  Advent of Code 2015 Tests: Day 21
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/27/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day21.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay21{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay21;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("111", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("188", solveb());
}

TEST(Example,Test1) {
    Fighter p{8,5,5};
    Fighter b{12,7,2};
	EXPECT_EQ(true,simulateBattle(p, b));
}

TEST(Example,Test2) {
    Fighter p{8,5,5};
    Fighter b{12,7,2};
    Item sword{10,1,0};
    b += sword;
    
    EXPECT_EQ(false,simulateBattle(p, b));
}

TEST(Example,Test3) {
    Fighter p{8,5,5};
    auto combos = buildCombinations(p);
	EXPECT_EQ(660,combos.size());
}

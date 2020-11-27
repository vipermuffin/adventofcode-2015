//
//  Advent of Code 2015 Tests: Day 7
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay07{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay07;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("956", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("40149", solveb());
}

TEST(Example,Test1) {
    Component w{0x80};
    Component g{LogicGateType::Not,&w,nullptr};
	EXPECT_EQ(0xFF7F,g.value());
}

TEST(Example,Test2) {
    Component w{0x80};
    Component w1{0x08};
    Component g{LogicGateType::Or,&w,&w1};
    EXPECT_EQ(0x88,g.value());
}

TEST(Example,Test3) {
    Component w{0x80};
    Component w1{0x08};
    Component g{LogicGateType::lShift,&w,nullptr};
    EXPECT_EQ(0x0080,g.value());
    Component g1{LogicGateType::Or,&g,&w1};
    EXPECT_EQ(0x88, g1.value());
    g.setRhs(&w1);
    EXPECT_EQ(0x8000, g.value());
    EXPECT_EQ(0x8008,g1.value());
}

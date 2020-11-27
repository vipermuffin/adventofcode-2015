//
//  Advent of Code 2015 Tests: Day 10
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay10{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay10;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("252594", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("3579328", solveb());
}

TEST(Example,Test1) {
    string seq{"1"};
	EXPECT_EQ("11",LookAndSayTranslation(seq));
}

TEST(Example,Test2) {
    string seq{"11"};
    EXPECT_EQ("21",LookAndSayTranslation(seq));
}

TEST(Example,Test3) {
    string seq{"21"};
    EXPECT_EQ("1211",LookAndSayTranslation(seq));
}

TEST(Example,Test4) {
    string seq{"1211"};
    EXPECT_EQ("111221",LookAndSayTranslation(seq));
}

//
//  Advent of Code 2015 Tests: Day 4
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay04{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay04;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("346386", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("9958218", solveb());
}

TEST(Example,Test1) {
    string key{"abcdef"};
	EXPECT_EQ(609043,ProduceFiveZeroHash(key, 0).second);
}

TEST(Example,Test2) {
    string key{"pqrstuv"};
    EXPECT_EQ(1048970,ProduceFiveZeroHash(key, 0).second);
}

TEST(Example,Test3) {
    string key{"abcdef"};
    EXPECT_EQ(609043,ProduceXZeroHash(key, 0, 5));
}

TEST(Example,Test4) {
    string key{"pqrstuv"};
    EXPECT_EQ(1048970,ProduceXZeroHash(key, 0, 5));
}

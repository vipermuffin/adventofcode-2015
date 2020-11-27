//
//  Advent of Code 2015 Tests: Day 5
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day05.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay05{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay05;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("238", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("69", solveb());
}

TEST(Example,Test1) {
    string x{"ugknbfddgicrmopn"};
	EXPECT_EQ(true,isNiceString(x));
}

TEST(Example,Test2) {
    string x{"aaa"};
    EXPECT_EQ(true,isNiceString(x));
}

TEST(Example,Test3) {
    string x{"jchzalrnumimnmhp"};
    EXPECT_EQ(false,isNiceString(x));
}

TEST(Example,Test4) {
    string x{"haegwjzuvuyypxyu"};
    EXPECT_EQ(false,isNiceString(x));
}

TEST(Example,Test5) {
    string x{"dvszwmarrgswjxmb"};
    EXPECT_EQ(false,isNiceString(x));
}

TEST(Example,Test6) {
    string x{"qjhvhtzxzqqjkmpb"};
    EXPECT_EQ(true,isNiceStringB(x));
}

TEST(Example,Test7) {
    string x{"xxyxx"};
    EXPECT_EQ(true,isNiceStringB(x));
}

TEST(Example,Test8) {
    string x{"uurcxstgmygtbstg"};
    EXPECT_EQ(false,isNiceStringB(x));
}

TEST(Example,Test9) {
    string x{"ieodomkazucvgmuy"};
    EXPECT_EQ(false,isNiceStringB(x));
}

TEST(Example,Test10) {
    string x{"xxxxyx"};
    EXPECT_EQ(true,isNiceStringB(x));
}
TEST(Example,Test11) {
    string x{"xxxx"};
    EXPECT_EQ(true,isNiceStringB(x));
}

//
//  Advent of Code 2015 Tests: Day 11
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day11.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay11{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay11;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("cqjxxyzz", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("cqkaabcc", solveb());
}

TEST(Example,IncrementPassTest1) {
    string s{"xx"};
    incrementPassword(s);
	EXPECT_EQ("xy",s);
}

TEST(Example,IncrementPassTest2) {
    string s{"xz"};
    incrementPassword(s);
    EXPECT_EQ("ya",s);
}

TEST(Example,IncrementPassTest3) {
    string s{"zzz"};
    incrementPassword(s);
    EXPECT_EQ("aaa",s);
}

TEST(Example,Rule1Test1) {
    string s{"hijklmmn"};
    EXPECT_EQ(true,verifyThreeIncCharRule(s));
}

TEST(Example,Rule2Test1) {
    string s{"hijklmmn"};
    EXPECT_EQ(false,verifyIllegalCharRule(s));
}

TEST(Example,Rule3Test1) {
    string s{"hijklmmn"};
    EXPECT_EQ(false,verifyPairsRule(s));
}

TEST(Example,Rule1Test2) {
    string s{"abbceffg"};
    EXPECT_EQ(false,verifyThreeIncCharRule(s));
}

TEST(Example,Rule2Test2) {
    string s{"abbceffg"};
    EXPECT_EQ(true,verifyIllegalCharRule(s));
}

TEST(Example,Rule3Test2) {
    string s{"abbceffg"};
    EXPECT_EQ(true,verifyPairsRule(s));
}

TEST(Example,NextPasswordTest1) {
    string s{"abcdefgh"};
    EXPECT_EQ("abcdffaa",findNextPassword(s));
}

TEST(Example,NextPasswordTest2) {
    string s{"ghijklmn"};
    EXPECT_EQ("ghjaabcc",findNextPassword(s));
}

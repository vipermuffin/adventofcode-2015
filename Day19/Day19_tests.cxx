//
//  Advent of Code 2015 Tests: Day 19
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/22/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day19.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay19{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay19;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("518", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("200", solveb());
}

TEST(Example,Test1) {
    vector<pair<string, string>> x{
        {"H","HO"},
        {"H","OH"},
        {"O","HH"}
    };
    string s{"HOH"};
    auto list = performChemistry(x, s);
    for(const auto& i : list) {
        cout << i << endl;
    }
	EXPECT_EQ(4,list.size());
}

TEST(Example,Test2) {
    vector<pair<string, string>> x{
        {"H","HO"},
        {"H","OH"},
        {"O","HH"}
    };
    string s{"HOHOHO"};
    auto list = performChemistry(x, s);
    for(const auto& i : list) {
        cout << i << endl;
    }
    EXPECT_EQ(7,list.size());
}

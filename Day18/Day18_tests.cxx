//
//  Advent of Code 2015 Tests: Day 18
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/21/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day18.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay18{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay18;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("768", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("781", solveb());
}

TEST(Example,Test1) {
    vector<vector<bool>> grid{
        {false, true,   false,  true,   false,  true},
        {false, false,  false,  true,   true,   false},
        {true,  false,  false,  false,  false,  true},
        {false, false,  true,   false,  false,  false},
        {true,  false,  true,   false,  false,  true},
        {true,  true,   true,   true,   false,  false}
    };
	
    EXPECT_EQ(2,numLightsOn(grid, 1, 1));
	EXPECT_EQ(0,numLightsOn(grid, 1, 0));
    EXPECT_EQ(0,numLightsOn(grid, 5, 4));
    EXPECT_EQ(6,numLightsOn(grid, 1, 4));
}

TEST(Example,Test2) {
    vector<vector<bool>> grid{
        {false, true,   false,  true,   false,  true},
        {false, false,  false,  true,   true,   false},
        {true,  false,  false,  false,  false,  true},
        {false, false,  true,   false,  false,  false},
        {true,  false,  true,   false,  false,  true},
        {true,  true,   true,   true,   false,  false}
    };
    auto g2 = performAnimationStep(grid);
	EXPECT_EQ(11,numLightsOn(g2));
    
    grid = performAnimationStep(g2);
    EXPECT_EQ(8,numLightsOn(grid));
    
    g2 = performAnimationStep(grid);
    EXPECT_EQ(4,numLightsOn(g2));
    
    grid = performAnimationStep(g2);
    EXPECT_EQ(4,numLightsOn(grid));
}


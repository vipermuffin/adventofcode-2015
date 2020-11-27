//
//  Advent of Code 2015 Solutions: Day 18
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/21/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay18 {
//Function Definitions
    int numLightsOn(const std::vector<std::vector<bool>>&grid,const int xPos, const int yPos);
    int numLightsOn(const std::vector<std::vector<bool>>&grid);
    std::vector<std::vector<bool>> performAnimationStep(const std::vector<std::vector<bool>>& grid0, bool cornersStuck=false);
}

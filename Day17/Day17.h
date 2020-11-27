//
//  Advent of Code 2015 Solutions: Day 17
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/20/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay17 {
//Function Definitions
    bool FitsLiquid(const std::vector<int>& containers, int liters);
    int FindCombinations(const std::vector<int>& containers,int liters);
    int FindMinCombinations(const std::vector<int>& containers,int liters);
}

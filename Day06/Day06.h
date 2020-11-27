//
//  Advent of Code 2015 Solutions: Day 6
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <vector>

namespace AocDay06 {
    enum class LightAction {TurnOn,TurnOff,Toggle};
//Function Definitions
    int numLightsOn(const std::vector<std::vector<bool>>&);
    long numLightsOn(const std::vector<std::vector<int>>&grid);
    void performLightRoutine(std::vector<std::vector<bool>>& grid);
    void performDimmingLightRoutine(std::vector<std::vector<int>>& grid);
}

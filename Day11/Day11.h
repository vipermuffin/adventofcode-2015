//
//  Advent of Code 2015 Solutions: Day 11
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay11 {
//Function Definitions
    void incrementPassword(std::string& p);
    bool verifyThreeIncCharRule(const std::string&);
    bool verifyIllegalCharRule(const std::string&);
    bool verifyPairsRule(const std::string&);
    std::string findNextPassword(const std::string&);
}

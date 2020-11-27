//
//  Advent of Code 2015 Solutions: Day 4
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
namespace AocDay04 {
//Function Definitions
    std::pair<char,int> ProduceFiveZeroHash(const std::string& id,int startIndex);
    std::pair<char,int> ProduceSixZeroHash(const std::string& id,int startIndex);
    int ProduceXZeroHash(const std::string& id,int startIndex, const int numDigits);
}

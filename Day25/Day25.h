//
//  Advent of Code 2015 Solutions: Day 25
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/29/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay25 {
//Function Definitions

    static const long INITIAL_VALUE = 20151125;
    
    long calculateCode(const long prevValue, const long mult = 252533, const long mod = 33554393);
    long getCodeAt(const int row, const int col, const long initVal = INITIAL_VALUE);
}

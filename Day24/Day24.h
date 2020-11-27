//
//  Advent of Code 2015 Solutions: Day 24
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/28/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay24 {
//Function Definitions

    long long getEntanglement(const std::vector<int>& v);
    int getWeight(const std::vector<int>& v);
    bool isBalanced(const std::vector<int>& g1,const std::vector<int>& g2, const int factor = 1);
    bool isBalanced(const std::vector<int>& g1,const std::vector<int>& g2,const std::vector<int>& g3);
    void findBalancedConfigs(std::vector<std::pair<std::vector<int>,std::vector<int>>>&configs,const std::vector<int>&fullList,int weight, int factor = 1) ;
}

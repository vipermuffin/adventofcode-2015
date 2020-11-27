//
//  Advent of Code 2015 Solutions: Day 12
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <vector>
#include <string>

namespace AocDay12 {
//Function Definitions

    std::vector<int> GetAllNumbersInString(const std::string&);
    std::vector<std::string> GetAllRedObjectsInString(const std::string&);
    
    class Item {
    public:
        Item() = default;
        ~Item() = default;
        void PopulateItems(const std::string& s);
        int getSum() const;
    //private:
        std::vector<std::string> strs;
        std::vector<Item> items;
        std::vector<int> nums;
        bool isObject;
        bool isRed;
    };
}

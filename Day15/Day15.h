//
//  Advent of Code 2015 Solutions: Day 15
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/19/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay15 {
//Function Definitions
    enum IngredientProperties {capacity,durability,flavor,texture, calories,NUM_PROPERTIES};
    struct Ingredient {
        Ingredient(const std::string&);
        int ComputeScore(const int multiplier) const;
        
        std::string name;
        int properites[IngredientProperties::NUM_PROPERTIES];
    };
    
    std::pair<long,int> FindMaxScore(const Ingredient& i1,const Ingredient& i2);
    long FindMaxScore(const Ingredient& i1,const Ingredient& i2, const Ingredient& i3, const Ingredient& i4);
    long FindMaxScoreWithCal(const Ingredient& i1,const Ingredient& i2, const Ingredient& i3, const Ingredient& i4);
}

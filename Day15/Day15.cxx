//
//  Advent of Code 2015 Solutions: Day 15
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/19/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day15.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay15 {

	static const std::string InputFileName = "Day15.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<Ingredient> x{};
        for(const auto& line : input) {
            x.push_back(Ingredient{line});
        }
        long max = FindMaxScore(x[0], x[1], x[2], x[3]);
		return to_string(max);
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<Ingredient> x{};
        for(const auto& line : input) {
            x.push_back(Ingredient{line});
        }
        long max = FindMaxScoreWithCal(x[0], x[1], x[2], x[3]);
        return to_string(max);
	}

    Ingredient::Ingredient(const std::string& input) {
        auto x = parseLineForWords(input);
        if(x.size() == 11) {
            name = x[0];
            for(int i = 0; i < IngredientProperties::NUM_PROPERTIES;++i) {
                properites[i] = stoi(x[i*2+2]);
            }
        }
    }
    
    int Ingredient::ComputeScore(const int multiplier) const {
        int score = 0;
        for(int i = 0; i < IngredientProperties::calories; ++i) {
            score += multiplier*properites[i];
        }
        return score;
    }
    
    std::pair<long,int> FindMaxScore(const Ingredient& i1,const Ingredient& i2) {
        const int MAX_INGREDIENTS = 100;
        long max{0};
        long score = 0;
        int maxIndex = 0;
        for(int i = 0; i < MAX_INGREDIENTS; ++i) {
            score = 1;
            for(int j = 0;j < IngredientProperties::calories;++j) {
                int x = i*i1.properites[j] + (MAX_INGREDIENTS-i)*i2.properites[j];
                if(x < 0) {
                    x=0;
                }
                score *= x;
            }
            if(score > max) {
                max = score;
                maxIndex = i;
            }
        }
        return std::pair<long, int> {max,maxIndex};
    }
    
    long FindMaxScore(const Ingredient& i1,const Ingredient& i2, const Ingredient& i3, const Ingredient& i4) {
        const int MAX_INGREDIENTS = 100;
        long max{0};
        long score = 1;
        int maxIndex = 0;
        for(int i = 0; i < MAX_INGREDIENTS; ++i) {
            for(int y = 0; y < MAX_INGREDIENTS-i;++y) {
                for(int z = 0; z < MAX_INGREDIENTS-i-y;++z) {
                    score = 1;
                    for(int j = 0;j < IngredientProperties::calories;++j) {
                        int x = i*i1.properites[j] +
                                y*i2.properites[j] +
                                z*i3.properites[j] +
                        (MAX_INGREDIENTS-i-y-z)*i4.properites[j];
                        if(x < 0) {
                            score = 0;
                            break;
                        }
                        score *= x;
                    }
                    if(score > max) {
                        max = score;
                        maxIndex = i;
                    }
                }
            }
        }
        return max;
    }
    
    long FindMaxScoreWithCal(const Ingredient& i1,const Ingredient& i2, const Ingredient& i3, const Ingredient& i4) {
        const int MAX_INGREDIENTS = 100;
        const int FIXED_CALORIES = 500;
        long max{0};
        long score = 1;
        int maxIndex = 0;
        for(int i = 0; i < MAX_INGREDIENTS; ++i) {
            for(int y = 0; y < MAX_INGREDIENTS-i;++y) {
                for(int z = 0; z < MAX_INGREDIENTS-i-y;++z) {
                    score = 1;
                    int cals = i*i1.properites[IngredientProperties::calories] +
                    y*i2.properites[IngredientProperties::calories] +
                    z*i3.properites[IngredientProperties::calories] +
                    (MAX_INGREDIENTS-i-y-z)*i4.properites[IngredientProperties::calories];
                    if(cals == FIXED_CALORIES) {
                        for(int j = 0;j < IngredientProperties::calories;++j) {
                            int x = i*i1.properites[j] +
                            y*i2.properites[j] +
                            z*i3.properites[j] +
                            (MAX_INGREDIENTS-i-y-z)*i4.properites[j];
                            if(x < 0) {
                                score = 0;
                                break;
                            }
                            score *= x;
                        }
                        if(score > max) {
                            max = score;
                            maxIndex = i;
                        }
                    }
                }
            }
        }
        return max;
    }
}

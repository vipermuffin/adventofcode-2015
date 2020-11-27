//
//  Advent of Code 2015 Solutions: Day 16
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/19/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day16.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <iomanip> //setfill setw hex
#include <map>
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
namespace AocDay16 {
    
    std::map<std::string,int> TickerTape{
        {"children:",3},
        {"cats:",7},
        {"samoyeds:",2},
        {"pomeranians:", 3},
        {"akitas:", 0},
        {"vizslas:", 0},
        {"goldfish:", 5},
        {"trees:", 3},
        {"cars:", 2},
        {"perfumes:", 1}
    };

	static const std::string InputFileName = "Day16.txt";
	std::string solvea() {
        vector<map<string,int>> sueList{};
        auto input = parseFileForLines(InputFileName);
        for(const auto& line : input) {
            auto words = parseLineForWords(line);
            map<string,int> tempSue;
            for(int i = 2;i< words.size()-1;i=i+2) {
                tempSue[words[i]] = stoi(words[i+1]);
            }
            sueList.push_back(tempSue);
        }
        
        vector<int> possibleSuesIndex{};
        int index = 0;
        for(const auto& sue : sueList) {
            int count = 0;
            for(const auto& val : sue) {
                if(TickerTape[val.first] == val.second) {
                    ++count;
                }
            }
            if(count == sue.size()) {
                possibleSuesIndex.push_back(index);
            }
            ++index;
        }
        return (possibleSuesIndex.size() == 1) ? to_string(possibleSuesIndex[0]+1) : "?";
	}
    
    bool CompareKeyToTicker(const std::pair<string,int>& val2Comp);
    
	std::string solveb() {
        vector<map<string,int>> sueList{};
        auto input = parseFileForLines(InputFileName);
        for(const auto& line : input) {
            auto words = parseLineForWords(line);
            map<string,int> tempSue;
            for(int i = 2;i< words.size()-1;i=i+2) {
                tempSue[words[i]] = stoi(words[i+1]);
            }
            sueList.push_back(tempSue);
        }
        
        vector<int> possibleSuesIndex{};
        int index = 0;
        for(const auto& sue : sueList) {
            int count = 0;
            for(const auto& val : sue) {
                if(CompareKeyToTicker(val)) {
                    ++count;
                }
            }
            if(count == sue.size()) {
                possibleSuesIndex.push_back(index);
            }
            ++index;
        }
        return (possibleSuesIndex.size() == 1) ? to_string(possibleSuesIndex[0]+1) : "?";//to_string(possibleSuesIndex.size());
	}

    bool CompareKeyToTicker(const std::pair<string,int>& val2Comp) {
        if(val2Comp.first == "cats:" || val2Comp.first == "trees:") {
            return TickerTape[val2Comp.first] < val2Comp.second;
        } else if (val2Comp.first == "pomeranians:" || val2Comp.first == "goldfish:") {
            return TickerTape[val2Comp.first] > val2Comp.second;
        } else {
            return TickerTape[val2Comp.first] == val2Comp.second;
        }
    }
}

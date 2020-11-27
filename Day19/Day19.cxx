//
//  Advent of Code 2015 Solutions: Day 19
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/22/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day19.h"
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
#include <set>
//#include <sstream>
//#include <thread>
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay19 {

    using vectPairOfStr = std::vector<std::pair<std::string,std::string>>;
	static const std::string InputFileName = "Day19.txt";
    int performChemistry2(const std::vector<std::pair<std::string,std::string>>& transforms, const std::string& startStr);
    vectPairOfStr GetInput() {
        vectPairOfStr x;
        auto input = parseFileForLines(InputFileName);
        for(const auto& line : input) {
            auto words = parseLineForWords(line);
            if(words.size()>2 && words[1] == "=>") {
                x.push_back(std::make_pair(words[0], words[2]));
            }
        }
        return x;
    }
    
	std::string solvea() {
        auto t = GetInput();
        string mm = parseFileForLines(InputFileName).back();
		return to_string(performChemistry(t, mm).size());
	}

	std::string solveb() {
        auto t = GetInput();
        string mm = parseFileForLines(InputFileName).back();
        return to_string(performChemistry2(t, mm));
	}

    std::set<std::string> performChemistry(const std::vector<std::pair<std::string,std::string>>& transforms, const std::string& startStr) {
        set<string> molecules{};
        
        for(const auto& t : transforms) {
            auto itr = startStr.find(t.first);
            while(itr != string::npos) {
                string newStr{startStr};
                newStr.replace(itr, t.first.size(), t.second);
                molecules.insert(newStr);
                itr = startStr.find(t.first,itr+1);
            }
        }
        
        return molecules;
    }
    
    int performChemistry2(const std::vector<std::pair<std::string,std::string>>& transforms, const std::string& startStr) {
        set<string> molecules{};
        int minCounts = INT_MAX;
        int d = 1;
        int counts = 0;
        string s{startStr};
        while(d != 0) {
            d = 0;
            for(const auto& t : transforms) {
                auto itr = s.find(t.second);
                if(itr != string::npos) {
                    d++;
                    counts++;
                    string newStr{s};
                    newStr.replace(itr, t.second.size(), t.first);
                    molecules.insert(newStr);
                    s = newStr;
                    //itr = s.find(t.first,itr+1);
                }
            }
            if(s == "e") {
                if(counts < minCounts) {
                    minCounts = counts;
                    s = startStr;
                    d = 1;
                }
            }
        }
        
        return minCounts;
    }
}

//
//  Advent of Code 2015 Solutions: Day 8
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
#include <iostream>
//#include <fstream> //ifstream
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
//#include <queue>
//#include <regex>
//#include <set>
#include <sstream>
#include <string>
//#include <thread>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay08 {

	static const std::string InputFileName = "Day08.txt";
	std::string solvea() {
        vector<string> strs{};
        vector<string> strInMem = parseFileForLines(InputFileName);
        int sum = 0;

        string backslash{"\\"};
        string quotes{"\""};
        string random{"_"};
        
        for(const auto& line : strInMem) {
            stringstream ss{};
            for(int i = 1; i < line.size()-1;i++) {
                if(line[i] == '\\') {
                    if(line[i+1] == '"') {
                        ss << quotes;
                        i++;
                    } else if( line[i+1] == '\\') {
                        ss << backslash;
                        i++;
                    } else if (line[i+1] == 'x') {
                        ss << random;
                        i += 3;
                    } else {
                        ss << line[i];
                    }
                } else {
                    ss << line[i];
                }
            }
            strs.push_back(ss.str());
        }
        
        if(strs.size() != strInMem.size()) {
            cout << "ERROR";
        }
        
        for(int i = 0; i< strs.size();i++) {
            sum += strInMem[i].length() - strs[i].length();
        }
		return to_string(sum);
	}

	std::string solveb() {
        vector<string> strs{};
        vector<string> strInMem = parseFileForLines(InputFileName);
        int sum = 0;

        string backslash{"\\\\"};
        string quotes{"\\\""};
        
        for(const auto& line : strInMem) {
            stringstream ss{};
            ss << "\"";
            for(int i = 0; i < line.size();i++) {
                if(line[i] == '\\') {
                    ss << backslash;
                    
                } else if(line[i] == '\"'){
                    ss << quotes;
                } else {
                    ss << line[i];
                }
            }
            ss << "\"";
            strs.push_back(ss.str());
        }
        
        for(int i = 0; i< strs.size();i++) {
            sum += strs[i].length() - strInMem[i].length();
        }
		return to_string(sum);
	}

}

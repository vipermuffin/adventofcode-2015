//
//  Advent of Code 2015 Solutions: Day 10
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
//#include <iostream>
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
namespace AocDay10 {

	static const std::string InputFileName = "Day10.txt";
	std::string solvea() {
        vector<string> x = parseFileForLines(InputFileName);
        for(int i = 0; i < 40; i++) {
            x.push_back(LookAndSayTranslation(x.back()));
        }
		return to_string(x.back().length());
	}

	std::string solveb() {
        vector<string> x = parseFileForLines(InputFileName);
        for(int i = 0; i < 50; i++) {
            x.push_back(LookAndSayTranslation(x.back()));
        }
        return to_string(x.back().length());
	}

    std::string LookAndSayTranslation(const std::string& s) {
        stringstream newS{};
        auto nextChar = s.begin();
        vector<char> digits{*nextChar};
        nextChar++;
        while(nextChar != s.end()) {
            if(*nextChar != digits.back()) {
                newS << to_string(digits.size()) << digits.back();
                digits.clear();
            }
            digits.push_back(*nextChar);
            nextChar++;
        }
        newS << to_string(digits.size()) << digits.back();
        
        return newS.str();
    }
}

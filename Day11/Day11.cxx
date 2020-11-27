//
//  Advent of Code 2015 Solutions: Day 11
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day11.h"
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
//#include <sstream>
#include <string>
//#include <thread>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay11 {

	static const std::string InputFileName = "Day11.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        string inputStr = input[0];
		return findNextPassword(inputStr);
	}

	std::string solveb() {
        string inputStr = solvea();
		return findNextPassword(inputStr);
	}
    
    void incrementPassword(string& p) {
        auto rtr = p.rbegin();
        while(rtr != p.rend()) {
            *rtr += 1;
            if(*rtr == '{') {
                *rtr = 'a';
                rtr++;
            } else {
                rtr = p.rend();
            }
        }
    }
    
    bool verifyThreeIncCharRule(const std::string& s) {
        auto itr = s.begin();
        int x = 0;
        while(itr < s.end()-1) {
            x = ((*itr)+1 == (*++itr)) ? x+1 : 0;
            if(x == 2) {
                return true;
            }
        }
        return false;
    }
    
    bool verifyIllegalCharRule(const std::string& s) {
        return (s.find("i") == string::npos) &&
        (s.find("o") == string::npos) &&
        (s.find("l") == string::npos);
    }
    
    bool verifyPairsRule(const std::string& s) {
        auto itr = s.begin();
        int x = 0;
        char lastFoundPair = '_';
        while(itr < s.end()-1) {
            if(*itr == (*++itr)) {
                if(*itr != lastFoundPair) {
                    ++x;
                    lastFoundPair = *itr;
                }
            } else {
                lastFoundPair = '_';
            }
            if(x == 2) {
                return true;
            }
        }
        return false;
    }
    
    std::string findNextPassword(const std::string& s) {
        string newPass{s};
        incrementPassword(newPass);
        while(!(verifyIllegalCharRule(newPass) && verifyPairsRule(newPass) && verifyThreeIncCharRule(newPass))) {
            incrementPassword(newPass);
        }
        return newPass;
    }
}

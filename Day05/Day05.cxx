//
//  Advent of Code 2015 Solutions: Day 5
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day05.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort std::count
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
namespace AocDay05 {

	static const std::string InputFileName = "Day05.txt";
	std::string solvea() {
        vector<string> lines = parseFileForLines(InputFileName);
        int niceStrings = 0;
        for(const auto& line : lines) {
            if(isNiceString(line)) {
                niceStrings++;
            }
        }
		return to_string(niceStrings);
	}

	std::string solveb() {
        vector<string> lines = parseFileForLines(InputFileName);
        int niceStrings = 0;
        for(const auto& line : lines) {
            if(isNiceStringB(line)) {
                niceStrings++;
            }
        }
		return to_string(niceStrings);
	}

    bool isNiceString(const std::string& sut) {
        bool isNice{false};
        //Check for illegal strings ab, cd, pq or xy
        if(string::npos == sut.find("ab") &&
           string::npos == sut.find("cd") &&
           string::npos == sut.find("pq") &&
           string::npos == sut.find("xy")) {
            //count vowels
            string vowels{"aeiou"};
            int numVowels = 0;
            for(const auto& c : vowels) {
                numVowels+=std::count(sut.begin(), sut.end(), c);
            }
            if(numVowels >= 3) {
                for(int i =0; i < sut.length()-1;i++) {
                    if(sut[i] == sut[i+1]) {
                        return true;
                    }
                }
            }
        }
        return isNice;
    }
    
    bool isNiceStringB(const std::string& sut) {
        bool isNice1{false};
        bool isNice2{false};
        for(int i =0; i < sut.length()-2 && !(isNice1 && isNice2);i++) {
            if(!isNice1) {
                //Pair to compare
                string sp{sut.begin()+i,sut.begin()+i+2};
                string front{sut.begin(),sut.begin()+i};
                string back{sut.begin()+i+2,sut.end()};
                isNice1 = front.find(sp) != string::npos || back.find(sp) != string::npos;
            }
            
            if(sut[i] == sut[i+2]) {
                isNice2 = true;
            }
        }
        return isNice1 && isNice2;
    }
}

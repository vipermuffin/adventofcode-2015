//
//  Advent of Code 2015 Solutions: Day 25
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/29/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day25.h"
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
namespace AocDay25 {

	static const std::string InputFileName = "Day25.txt";
    
    
	std::string solvea() {
		return to_string(getCodeAt(2978, 3083));
	}

	std::string solveb() {
		return "---";
	}

    long calculateCode(const long prevValue, const long mult, const long mod) {
        long result = prevValue * mult;
        return result%mod;
    }
    
    long getCodeAt(const int row, const int col, const long initVal) {
        int cr = 1;
        int cc = 1;
        long result = initVal;
        
        while (!(cr == row && cc == col)) {
            result = calculateCode(result);
            if(cr == 1) {
                cr += cc;
                cc = 1;
            } else {
                ++cc;
                --cr;
            }
        }
        
        return result;
    }
}

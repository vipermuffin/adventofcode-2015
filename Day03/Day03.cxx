//
//  Advent of Code 2015 Solutions: Day 3
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/07/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <iomanip> //setfill setw hex
#include <map>
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
namespace AocDay03 {

	static const std::string InputFileName = "Day03.txt";
	std::string solvea() {
        ifstream ifs{InputFileName};
        return to_string(trackHouses(ifs));
	}

	std::string solveb() {
        ifstream ifs{InputFileName};
		return to_string(trackHousesWRobo(ifs));
	}

    int trackHouses(istream& is) {
        map<std::pair<int,int>,int> visited{{{0,0},0}};
        std::pair<int,int> curLoc{0,0};
        char c;
        while(is >> c) {
            switch(c) {
                case '^':
                    curLoc.second++;
                    break;
                case 'v':
                    curLoc.second--;
                    break;
                case '>':
                    curLoc.first++;
                    break;
                case '<':
                    curLoc.first--;
                    break;
                default:
                    break;
            }
            visited[curLoc] += 1;
        }
        return visited.size();
    }
    
    int trackHousesWRobo(istream& is) {
        map<std::pair<int,int>,int> visited{{{0,0},0}};
        std::pair<int,int> curLocS{0,0};
        std::pair<int,int> curLocR{0,0};
        bool x{false};
        char c;
        while(is >> c) {
            std::pair<int,int>& curLoc{(x) ? curLocR : curLocS};
            switch(c) {
                case '^':
                    curLoc.second++;
                    break;
                case 'v':
                    curLoc.second--;
                    break;
                case '>':
                    curLoc.first++;
                    break;
                case '<':
                    curLoc.first--;
                    break;
                default:
                    break;
            }
            visited[curLoc] += 1;
            x = !x;
        }
        return visited.size();
    }
}

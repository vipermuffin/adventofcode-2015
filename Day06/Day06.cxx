//
//  Advent of Code 2015 Solutions: Day 6
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day06.h"
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
#include <regex>
//#include <set>
//#include <sstream>
#include <string>
//#include <thread>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay06 {

	static const std::string InputFileName = "Day06.txt";
	std::string solvea() {
        vector<vector<bool>> grid(1000,vector<bool>(1000,false));
        performLightRoutine(grid);
		return to_string(numLightsOn(grid));
	}

	std::string solveb() {
        vector<vector<int>> grid(1000,vector<int>(1000,0));
        performDimmingLightRoutine(grid);
		return to_string(numLightsOn(grid));
	}

    void performLightRoutine(std::vector<std::vector<bool>>& grid) {
        auto instructions{parseFileForLines(InputFileName)};
        regex re{"(\\d+),(\\d+)"};
        for(const auto& line : instructions) {
            auto words{parseLineForWords(line)};
            LightAction la{LightAction::TurnOff};
            if(words[0] == "toggle")
                la = LightAction::Toggle;
            else if (words[1] == "on")
                la = LightAction::TurnOn;
            try {
                sregex_iterator next{line.begin(),line.end(),re};
                sregex_iterator end;
                vector<int> coordinates{};
                while(next != end) {
                    smatch match = *next;
                    coordinates.push_back(stoi(match[1]));
                    coordinates.push_back(stoi(match[2]));
                    next++;
                }
                if(coordinates.size() == 4) {
                    auto rows = grid.begin()+coordinates[1];
                    while(rows <= grid.begin()+coordinates[3]){
                        auto lights = rows->begin()+coordinates[0];
                        while(lights <= rows->begin()+coordinates[2]){
                            if(la == LightAction::TurnOn) {
                                *lights = true;
                            } else if (la == LightAction::TurnOff){
                                *lights = false;
                            } else {
                                *lights = *lights ? false : true;
                            }
                            lights++;
                        }
                        rows++;
                    }
                }
            }
            catch (regex_error& e) {
                
            }
        }
    }
    
    void performDimmingLightRoutine(std::vector<std::vector<int>>& grid) {
        auto instructions{parseFileForLines(InputFileName)};
        regex re{"(\\d+),(\\d+)"};
        for(const auto& line : instructions) {
            auto words{parseLineForWords(line)};
            LightAction la{LightAction::TurnOff};
            if(words[0] == "toggle")
                la = LightAction::Toggle;
            else if (words[1] == "on")
                la = LightAction::TurnOn;
            try {
                sregex_iterator next{line.begin(),line.end(),re};
                sregex_iterator end;
                vector<int> coordinates{};
                while(next != end) {
                    smatch match = *next;
                    coordinates.push_back(stoi(match[1]));
                    coordinates.push_back(stoi(match[2]));
                    next++;
                }
                if(coordinates.size() == 4) {
                    auto rows = grid.begin()+coordinates[1];
                    while(rows <= grid.begin()+coordinates[3]){
                        auto lights = rows->begin()+coordinates[0];
                        while(lights <= rows->begin()+coordinates[2]){
                            if(la == LightAction::TurnOn) {
                                *lights += 1;
                            } else if (la == LightAction::TurnOff){
                                *lights -= (*lights > 0) ? 1 : 0;
                            } else {
                                *lights += 2;
                            }
                            lights++;
                        }
                        rows++;
                    }
                }
            }
            catch (regex_error& e) {
                
            }
        }
    }
    
    int numLightsOn(const std::vector<std::vector<bool>>&grid) {
        int on = 0;
        for(const auto& row : grid) {
            for(const auto& light : row) {
                on += light ? 1 : 0;
            }
        }
        return on;
    }
    
    long numLightsOn(const std::vector<std::vector<int>>&grid) {
        long on = 0;
        for(const auto& row : grid) {
            for(const auto& light : row) {
                on += light;
            }
        }
        return on;
    }
}

//
//  Advent of Code 2015 Solutions: Day 18
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/21/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day18.h"
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
namespace AocDay18 {
    int numLightsOn(const std::vector<std::vector<bool>>&grid);
	static const std::string InputFileName = "Day18.txt";
    static const int GRID_SIZE = 100;
	std::string solvea() {
        //Init the grid
        vector<vector<bool>> grid(GRID_SIZE,vector<bool>(GRID_SIZE,false));
        auto input = parseFileForLines(InputFileName);
        int totalOn = -222;
        if(input.size() == GRID_SIZE) {
            for(int i = 0;i < GRID_SIZE;++i) {
                for(int j = 0;j < input[i].size();++j) {
                    if(input[i][j] == '#') {
                        grid[i][j] = true;
                    }
                }
            }
            for(int i = 0; i < GRID_SIZE;++i) {
                grid = performAnimationStep(grid);
            }
            totalOn = numLightsOn(grid);
        }
        else {
            //Something went wrong
            return InputFileName;
        }
		return to_string(totalOn);
	}

	std::string solveb() {
        //Init the grid
        vector<vector<bool>> grid(GRID_SIZE,vector<bool>(GRID_SIZE,false));
        auto input = parseFileForLines(InputFileName);
        int totalOn = -222;
        if(input.size() == GRID_SIZE) {
            for(int i = 0;i < GRID_SIZE;++i) {
                for(int j = 0;j < input[i].size();++j) {
                    if(((i==0 || i==input.size()-1)&&(j==0 || j == input.size()-1))) {
                        grid[i][j] = true;
                    }
                    else if(input[i][j] == '#') {
                        grid[i][j] = true;
                    }
                }
            }
            for(int i = 0; i < GRID_SIZE;++i) {
                grid = performAnimationStep(grid,true);
            }
            totalOn = numLightsOn(grid);
        }
        else {
            //Something went wrong
            return InputFileName;
        }
        return to_string(totalOn);
	}
    /*
     Grid
     0,0   99,0
     yx -->
     |
     |
     v
     0,99
    */
    int numLightsOn(const std::vector<std::vector<bool>>&grid,const int xPos, const int yPos) {
        int on = 0;
        vector<std::pair<int,int>> points;
        for(int x = xPos - 1; x < xPos + 2; ++x) {
            for(int y = yPos -1; y < yPos + 2;++y) {
                if((x >=0 && y >= 0) &&
                   (x < grid.size() && y < grid.size()) &&
                   !(x == xPos && y == yPos)) {
                    if(grid[y][x]) {
                        ++on;
                    }
                }
            }
        }
        return on;
    }
    
    vector<vector<bool>> performAnimationStep(const vector<vector<bool>>& grid0, bool cornersStuck) {
        vector<vector<bool>> grid1{grid0};
        for(int x = 0; x < grid0.size();++x) {
            for(int y = 0; y < grid0.size();++y) {
                auto nlo = numLightsOn(grid0,x,y);
                if(cornersStuck && ((x==0 || x==grid0.size()-1)&&(y==0 || y == grid0.size()-1))) {
                    //corner is stuck on
                    grid1[y][x] = true;
                }else if(grid0[y][x]) {
                    //Light is on
                    if(nlo != 2 && nlo != 3) {
                        grid1[y][x] = false;
                    }
                } else {
                    //Light is off
                    if(nlo == 3) {
                        grid1[y][x] = true;
                    }
                }
            }
        }
        return grid1;
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

}

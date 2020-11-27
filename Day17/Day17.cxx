//
//  Advent of Code 2015 Solutions: Day 17
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/20/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day17.h"
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
namespace AocDay17 {

    void generateCombinations(const vector<int>& arr, vector<vector<int>>& combos, int n, int r);
    // Routine to generate all combination of size r in an array of size n
    void combinationUtil(const vector<int>& arr, vector<int>& data, vector<vector<int>>& combos, int start, int end,
                         int index, int r);
	static const std::string InputFileName = "Day17.txt";
	std::string solvea() {
        auto input = parseFileForNumberPerLine(InputFileName);
		return to_string(FindCombinations(input, 150));
	}

	std::string solveb() {
        auto input = parseFileForNumberPerLine(InputFileName);
        return to_string(FindMinCombinations(input, 150));
	}
    
    int FindMinCombinations(const std::vector<int>& containers,int liters) {
        int combos = 0;
        bool done = false;
        vector<vector<int>> c{};
        for(int i = 1; i < containers.size()&& !done;++i) {
            generateCombinations(containers, c, containers.size(), i);
            for(const auto& v : c) {
                if(FitsLiquid(v, liters)) {
                    ++combos;
                    done = true;
                }
            }
            c.clear();
        }
        c.push_back(containers);
        for(const auto& v : c) {
            if(FitsLiquid(v, liters)) {
                ++combos;
            }
        }
        return combos;
    }

    int FindCombinations(const std::vector<int>& containers,int liters) {
        int combos = 0;
        vector<vector<int>> c{};
        for(int i = 1; i < containers.size();++i) {
            generateCombinations(containers, c, containers.size(), i);
        }
        c.push_back(containers);
        for(const auto& v : c) {
            if(FitsLiquid(v, liters)) {
                ++combos;
            }
        }
        return combos;
    }
    
    bool FitsLiquid(const std::vector<int>& containers, int liters) {
        for(const auto& x : containers) {
            liters -= x;
        }
        return liters == 0;
    }
    
    void generateCombinations(const vector<int>& arr, vector<vector<int>>& combos, int n, int r)
    {
        // A temporary array to store all combination one by one
        vector<int> data(r,0);
        
        // Print all combination using temprary array 'data[]'
        combinationUtil(arr, data, combos, 0, n-1, 0, r);
    }
    
    /* arr[] ---> Input Array
     data[] ---> Temporary array to store current combination
     start & end ---> Staring and Ending indexes in arr[]
     index ---> Current index in data[]
     r ---> Size of a combination to be printed */
    void combinationUtil(const vector<int>& arr, vector<int>& data, vector<vector<int>>& combos, int start, int end,
                         int index, int r)
    {
        // Current combination is ready to be printed, print it
        if (index == r)
        {
            combos.push_back(data);
            return;
        }
        
        // replace index with all possible elements. The condition
        // "end-i+1 >= r-index" makes sure that including one element
        // at index will make a combination with remaining elements
        // at remaining positions
        for (int i=start; i<=end && end-i+1 >= r-index; i++)
        {
            data[index] = arr[i];
            combinationUtil(arr, data, combos, i+1, end, index+1, r);
        }
    }
}

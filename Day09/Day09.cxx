//
//  Advent of Code 2015 Solutions: Day 9
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort
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
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay09 {

	static const std::string InputFileName = "Day09.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<string, unordered_map<string, int>> gps;
        for(const auto& line: input) {
            auto words = parseLineForWords(line);
            string c1 = words[0];
            string c2 = words[2];
            int distance = stoi(words[4]);
            gps[c1][c2] = distance;
            gps[c2][c1] = distance;
        }
        // Iterating the map and printing ordered values
//        for (auto i = gps.begin(); i != gps.end(); i++) {
//            std::cout << i->first << "=>";
//            for(const auto& z : i->second) {
//                cout << " (" << z.first << ":" << z.second << ")";
//            }
//            cout << std::endl;
//        }
        
        vector<string> cities;
        cities.reserve(gps.size());
        for(const auto& d : gps) {
            cities.push_back(d.first);
        }
        
        vector<vector<string>> trips;
        auto rSize = cities.size();
        for(int i = rSize-1;i > 0;--i) {
            rSize *= i;
        }
        trips.reserve(rSize);
        std::sort(cities.begin(),cities.end());
//        printVector(cities);
        do {
            trips.push_back(cities);
        }while(std::next_permutation(cities.begin(), cities.end()));
       
        int min = INT_MAX;
        for(const auto& trip : trips) {
            int sum = 0;
            for(auto i = trip.begin()+1;i < trip.end();++i) {
                sum += gps[*i][*(i-1)];
            }
//            cout << "Trip distance = " << sum << " : ";
//            printVector(trip);
            if(sum < min) {
                min = sum;
            }
        }
		return to_string(min);
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<string, unordered_map<string, int>> gps;
        for(const auto& line: input) {
            auto words = parseLineForWords(line);
            string c1 = words[0];
            string c2 = words[2];
            int distance = stoi(words[4]);
            gps[c1][c2] = distance;
            gps[c2][c1] = distance;
        }
        
        vector<string> cities;
        cities.reserve(gps.size());
        for(const auto& d : gps) {
            cities.push_back(d.first);
        }
        
        vector<vector<string>> trips;
        auto rSize = cities.size();
        for(int i = rSize-1;i > 0;--i) {
            rSize *= i;
        }
        trips.reserve(rSize);
        std::sort(cities.begin(),cities.end());
//        printVector(cities);
        do {
            trips.push_back(cities);
        }while(std::next_permutation(cities.begin(), cities.end()));
        
        int max = INT_MIN;
        for(const auto& trip : trips) {
            int sum = 0;
            for(auto i = trip.begin()+1;i < trip.end();++i) {
                sum += gps[*i][*(i-1)];
            }
            if(sum > max) {
                max = sum;
            }
        }
        return to_string(max);
	}

    
}

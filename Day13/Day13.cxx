//
//  Advent of Code 2015 Solutions: Day 13
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/21/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day13.h"
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
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay13 {

	static const std::string InputFileName = "Day13.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        
        //Generate happiness matrix
        unordered_map<string, unordered_map<string, int>> hpm;
        for(const auto& line: input) {
            auto words = parseLineForWords(line);
            string c1 = words[0];
            string c2{words[10].begin(),words[10].end()-1}; // need to remove '.'
            int happiness = stoi(words[3]);
            hpm[c1][c2] = (words[2] == "gain") ? happiness : -happiness;
        }
        // Iterating the map and printing ordered values
                for (auto i = hpm.begin(); i != hpm.end(); i++) {
                    std::cout << i->first << "=>";
                    for(const auto& z : i->second) {
                        cout << " (" << z.first << ":" << z.second << ")";
                    }
                    cout << std::endl;
                }
        
        //Build list of people
        vector<string> people;
        people.reserve(hpm.size());
        for(const auto& p : hpm) {
            people.push_back(p.first);
        }
        
        //Generate permutations of seating
        vector<vector<string>> plans;
        
        //Reserve some memory to speed things up a bit
        auto rSize = plans.size();
        for(int i = rSize - 1; i > 0;--i) {
            rSize *= i;
        }
        plans.reserve(rSize);
        
        //Need to sort in order to use std::next_permutation
        std::sort(people.begin(),people.end());
        do {
            plans.push_back(people);
//            printVector(people);
        } while(std::next_permutation(people.begin(), people.end()));
        
        //Calculate the best result
        int max = INT_MIN;
        for(const auto& plan : plans) {
            int sum = 0;
            sum += hpm[plan[0]][plan.back()];
            sum += hpm[plan.back()][plan[0]];
            for(auto i = plan.begin()+1;i < plan.end();++i) {
                sum += hpm[*i][*(i-1)];
                sum += hpm[*(i-1)][*i];
            }
            if(sum > max) {
                max = sum;
                cout << "Max Happiness --> " << max << " : " ;
                printVector(plan);
            }
        }
        return to_string(max);
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        
        //Generate happiness matrix
        unordered_map<string, unordered_map<string, int>> hpm;
        for(const auto& line: input) {
            auto words = parseLineForWords(line);
            string c1 = words[0];
            string c2{words[10].begin(),words[10].end()-1}; // need to remove '.'
            int happiness = stoi(words[3]);
            hpm[c1][c2] = (words[2] == "gain") ? happiness : -happiness;
        }
        
        // Iterating the map and printing ordered values
        for (auto i = hpm.begin(); i != hpm.end(); i++) {
            std::cout << i->first << "=>";
            for(const auto& z : i->second) {
                cout << " (" << z.first << ":" << z.second << ")";
            }
            cout << std::endl;
        }
        
        //Build list of people
        vector<string> people;
        people.reserve(hpm.size());
        for(const auto& p : hpm) {
            people.push_back(p.first);
        }
        people.push_back("Me");
        
        //Generate permutations of seating
        vector<vector<string>> plans;
        
        //Reserve some memory to speed things up a bit
        auto rSize = plans.size();
        for(int i = rSize - 1; i > 0;--i) {
            rSize *= i;
        }
        plans.reserve(rSize);
        
        //Need to sort in order to use std::next_permutation
        std::sort(people.begin(),people.end());
        do {
            plans.push_back(people);
            //            printVector(people);
        } while(std::next_permutation(people.begin(), people.end()));
        
        //Calculate the best result
        int max = INT_MIN;
        for(const auto& plan : plans) {
            int sum = 0;
            sum += hpm[plan[0]][plan.back()];
            sum += hpm[plan.back()][plan[0]];
            for(auto i = plan.begin()+1;i < plan.end();++i) {
                sum += hpm[*i][*(i-1)];
                sum += hpm[*(i-1)][*i];
            }
            if(sum > max) {
                max = sum;
                cout << "Max Happiness --> " << max << " : " ;
                printVector(plan);
            }
        }
        return to_string(max);
	}

}

//
//  Advent of Code 2015 Solutions: Day 24
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/28/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day24.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
#include <tuple>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay24 {

	static const std::string InputFileName = "Day24.txt";
	std::string solvea() {
        auto input = parseFileForNumberPerLine(InputFileName);
        int i{1};
        bool done{false};
        CombinationGenerator<int> cg1{input};
        vector<tuple<vector<int>,vector<int>,vector<int>>> configs;
        vector<std::pair<vector<int>,vector<int>>> g23;
        vector<vector<int>> g1_combos;
        while(i < input.size() && !done) {
            g1_combos = cg1.generateCombosChoose(i++);
            for(const auto& combo : g1_combos) {
                vector<int> x{input};
                for(const auto& w : combo) {
                    auto z = find(x.begin(),x.end(),w);
                    x.erase(z);
                }
                if(isBalanced(combo, x, 2)) {
//                    printVector(combo);
//                    printVector(x);
                    g23.clear();
                    findBalancedConfigs(g23, x, getWeight(combo));
                    if(g23.size() > 0) {
                        done = true;
                        for(const auto& v : g23) {
                            configs.push_back(make_tuple(combo,v.first,v.second));
                        }
                    }
                }
            }
        }

        long long min = LONG_LONG_MAX;
        for(const auto& c : configs) {
            auto e = getEntanglement(get<0>(c));
            if(e > 0 && e < min) {
//                cout << "Config Option: QE=" << e << endl;
//                printVector(get<0>(c));
//                printVector(get<1>(c));
//                printVector(get<2>(c));
//                cout << "----------------" << endl;
                min = e;
            }
        }
        return to_string(min);
	}

	std::string solveb() {
        auto input = parseFileForNumberPerLine(InputFileName);
        int i{1};
        bool done{false};
        CombinationGenerator<int> cg1{input};
        vector<tuple<vector<int>,vector<int>,vector<int>,vector<int>>> configs;
        vector<std::pair<vector<int>,vector<int>>> g23;
        vector<std::pair<vector<int>,vector<int>>> g34;
        vector<vector<int>> g1_combos;
        while(i < input.size() && !done) {
            g1_combos = cg1.generateCombosChoose(i++);
            for(const auto& combo : g1_combos) {
                vector<int> x{input};
                for(const auto& w : combo) {
                    auto z = find(x.begin(),x.end(),w);
                    x.erase(z);
                }
                if(isBalanced(combo, x, 3)) {
                    //                    printVector(combo);
                    //                    printVector(x);
                    g23.clear();
                    findBalancedConfigs(g23, x, getWeight(combo),2);
                    if(g23.size() > 0) {
                        for(const auto& y : g23) {
                            g34.clear();
                            findBalancedConfigs(g34, y.second, getWeight(combo));
                            if(g34.size() > 0) {
                                done = true;
                                for(const auto& v : g34) {
                                    configs.push_back(make_tuple(combo,y.first,v.first,v.second));
                                }
                            }
                        }
                    }
                }
            }
        }
        
        long long min = LONG_LONG_MAX;
        for(const auto& c : configs) {
            auto e = getEntanglement(get<0>(c));
            if(e > 0 && e < min) {
                //                cout << "Config Option: QE=" << e << endl;
                //                printVector(get<0>(c));
                //                printVector(get<1>(c));
                //                printVector(get<2>(c));
                //                cout << "----------------" << endl;
                min = e;
            }
        }
        return to_string(min);
	}

    int getWeight(const std::vector<int>& v) {
        return std::accumulate(v.begin(), v.end(), 0);
    }
    
    void findBalancedConfigs(std::vector<std::pair<std::vector<int>,std::vector<int>>>&configs,const std::vector<int>&fullList,int weight, int factor) {
        CombinationGenerator<int> cg1{fullList};
        bool done{false};
        int i{1};
        
        while(i < fullList.size() && !done) {
            auto g1_combos = cg1.generateCombosChoose(i++);
            for(const auto& combo : g1_combos) {
                if(weight == 0 || weight == getWeight(combo)) {
                    vector<int> x{fullList};
                    for(const auto& w : combo) {
                        auto z = find(x.begin(),x.end(),w);
                        x.erase(z);
                    }
                    if(isBalanced(combo, x, factor)) {
                        configs.push_back(make_pair(combo, x));
                        done = true;
                    }
                }
            }
        }
    }
    
    bool isBalanced(const std::vector<int>& g1,const std::vector<int>& g2, int factor) {
        auto x = std::accumulate(g1.begin(), g1.end(), 0);
        auto y = std::accumulate(g2.begin(), g2.end(), 0);
        return x*factor == y;
    }
    bool isBalanced(const std::vector<int>& g1,const std::vector<int>& g2,const std::vector<int>& g3) {
        
        return false;
    }
    
    long long getEntanglement(const std::vector<int>& v) {
        long long p{1};
        long long prev{1};
        for(const auto& num : v ) {
            prev = p;
            p *= num;
            if(prev > p) {
                return LONG_LONG_MAX;
            }
        }
//        return std::accumulate(v.begin(), v.end(), 1, std::multiplies<long long>());
        return p;
    }
}

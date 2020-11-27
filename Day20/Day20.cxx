//
//  Advent of Code 2015 Solutions: Day 20
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/26/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day20.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <iomanip> //setfill setw hex
//#include <map>
#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
#include <set>
//#include <sstream>
//#include <thread>
//#include <unordered_map>
//#include <unordered_set>



using namespace std;
namespace AocDay20 {
	static const std::string InputFileName = "Day20.txt";
    static const int input = 29000000;
	std::string solvea() {
		return to_string(findLowestHouseWithAtLeastXPresents(input,10,0));
	}

	std::string solveb() {
		return to_string(findLowestHouseWithAtLeastXPresents(input,11,50));
	}

    long calculatePresents(const int houseNum, const int mult, const int maxVisits) {
        long numPresents = 0;
        for(int i = 1;i <= houseNum; ++i) {
            if(
                ((maxVisits == 0)||(houseNum / i <= maxVisits)) && 
                (houseNum % i == 0)) {
                numPresents += i*mult;
            }
        }
        return numPresents;
    }
    int findLowestHouseWithAtLeastXPresents(int x, int mult, int maxVisits) {
        set<int> multiples{1};
        vector<int> primes{2,3,5,7,11,13,17,19};
        //generate list of values to calculate
        for(auto x : primes) {
            
            for(int i = 0;i < 8;++i) {
                set<int> ms{multiples};                
                for(const auto mi : ms) {
                    int m = mi*x;
                    if(m > 0) {
                        multiples.insert(m);
                    }
                }
            }
        }

        long max = 0;
        primes.clear();
        primes.reserve(multiples.size());
        for(const auto m : multiples) {
            auto y = calculatePresents(m,mult,maxVisits);
            if(y > max) {
                max = y;
                primes.push_back(m);
            }
            if(max >= x)
                break;
        }
        auto ritr = primes.rbegin();
        auto end = *ritr;
        ritr++;
        auto begin = *ritr;
        for(int i = begin+1;i<end;i=i+2) {
            if(calculatePresents(i,mult,maxVisits) > x) {
                return i;
            }
        }
        
        return primes.back();
    }
}

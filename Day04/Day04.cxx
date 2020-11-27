//
//  Advent of Code 2015 Solutions: Day 4
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "AoCUtils.h"
#include "md5.hpp"
//Common Libraries
//#include <algorithm> //std::sort
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
namespace AocDay04 {

	static const std::string InputFileName = "Day04.txt";
	std::string solvea() {
		return to_string(ProduceFiveZeroHash("iwrupvqb", 0).second);
	}

	std::string solveb() {
		return to_string(ProduceSixZeroHash("iwrupvqb", 0).second);
	}
    
    std::pair<char,int> ProduceFiveZeroHash(const std::string& id,int startIndex)
    {
        while(startIndex>=0)
        {
            string s{id + std::to_string(++startIndex)};
            MD5 hash{s};
            string hashStr{hash.hexdigest()};
            if((hashStr.length() > 5) && (hashStr.substr(0,5) == "00000"))
            {
                return std::make_pair(hashStr[5], startIndex);
            }
            else
            {
                //cout << "DEBUG: " << hashStr << ":" << hashStr.substr(0,5) << ":" << startIndex << endl;
            }
        }
        
        //Nothing found before startIndex overflowed
        return make_pair('x', 0);
    }
    
    std::pair<char,int> ProduceSixZeroHash(const std::string& id,int startIndex)
    {
        while(startIndex>=0)
        {
            string s{id + std::to_string(++startIndex)};
            MD5 hash{s};
            string hashStr{hash.hexdigest()};
            if((hashStr.length() > 6) && (hashStr.substr(0,6) == "000000"))
            {
                return std::make_pair(hashStr[6], startIndex);
            }
            else
            {
                //cout << "DEBUG: " << hashStr << ":" << hashStr.substr(0,5) << ":" << startIndex << endl;
            }
        }
        
        //Nothing found before startIndex overflowed
        return make_pair('x', 0);
    }
    
    int ProduceXZeroHash(const std::string& id,int startIndex, const int numDigits)
    {
        char *x = new char[numDigits];
        for(int i = 0; i < numDigits;i++) {
            x[i] = '0';
        }
        const string zeroString{x};
        delete[] x;
        
        while(startIndex>=0)
        {
            string s{id + std::to_string(++startIndex)};
            MD5 hash{s};
            string hashStr{hash.hexdigest()};
            if((hashStr.length() > numDigits) && (hashStr.substr(0,numDigits) == zeroString))
            {
                
                return startIndex;
            }
            else
            {
                //cout << "DEBUG: " << hashStr << ":" << hashStr.substr(0,5) << ":" << startIndex << endl;
            }
        }
        //Nothing found before startIndex overflowed
        return -1;
    }
}



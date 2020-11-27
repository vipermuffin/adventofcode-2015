//
//  Advent of Code 2015 Solutions: Day 12
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day12.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
#include <iostream>
//#include <fstream> //ifstream
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
#include <numeric> //std::accumulate
//#include <queue>
#include <regex>
//#include <set>
//#include <sstream>
#include <string>
#include <stack>
//#include <thread>
//#include <unordered_map>
//#include <unordered_set>

//#define DEBUG
using namespace std;
namespace AocDay12 {

	static const std::string InputFileName = "Day12.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<int> x{};
        for(const auto& line : input) {
            auto y = GetAllNumbersInString(line);
            x.insert(x.end(),y.begin(),y.end());
        }
        int sum = std::accumulate(x.begin(), x.end(), 0);
		return to_string(sum);
	}

	std::string solveb() {

        //Get all numbers
        //22286 is too low
        //63360 is not right
        auto input = parseFileForLines(InputFileName);
#if 0
        vector<int> x{};
        vector<int> reds{};
        for(const auto& line : input) {
            auto y = GetAllNumbersInString(line);
            x.insert(x.end(),y.begin(),y.end());
            auto z = GetAllRedObjectsInString(line);
            for(const auto& rLine : z) {
                cout << rLine << endl;
                y = GetAllNumbersInString(rLine);
                reds.insert(reds.end(),y.begin(),y.end());
            }
        }
        int sum = std::accumulate(x.begin(), x.end(), 0);
        int negative = std::accumulate(reds.begin(), reds.end(), 0);
#endif
        Item i;
        i.PopulateItems(input[0]);
        return to_string(i.getSum());
//        return "---";
	}

    std::vector<int> GetAllNumbersInString(const std::string& line){
        regex re{"(-*\\d+)"};
        vector<int> numAry{};
        try {
            sregex_iterator next{line.begin(),line.end(),re};
            sregex_iterator end;
            while(next != end) {
                smatch match = *next;
                numAry.push_back(stoi(match[1]));
                ++next;
            }
        } catch (regex_error& e) {
            cout << "ERROR: " << e.what() << endl;
        }
        return numAry;
    }
    
    std::vector<std::string> GetAllRedObjectsInString(const std::string& line){
        vector<string> strAry{};

        //Find objects defined in {}
        vector<int> parenB;
        vector<string> objects{};
        vector<vector<string>> groups{};
        for(int i = 0;i < line.length();++i) {
            if(line[i] == '{') {
                parenB.push_back(i+1);
            } else if (line[i] == '}') {
                if(parenB.size() > 0) {
                    objects.push_back(string{line.begin()+parenB.back(),line.begin()+i});
                    parenB.pop_back();
                    if(parenB.size()==0) {
                        groups.push_back(objects);
                        objects.clear();
                    }
                }
            }
        }
        
        //Find outer most object {} that contains red but not {[..red..]..}
        for(const auto& x : groups) {
            objects.clear();
            for( const auto& y : x) {
                auto firstParen = y.find("{");
                string str2Search{y.begin(),(firstParen != string::npos) ? y.begin()+firstParen : y.end()};
                auto firstBracket = str2Search.find("[");
                auto secondBracket = str2Search.find("]");
                auto firstRed = str2Search.find("red");
                if(firstRed != string::npos) {
                    if((firstRed > firstBracket) && (firstRed < secondBracket)) {
                        //Red is in array...see if maybe there is a property on the other side of the }
                        firstParen = y.find_last_of("}");
                        str2Search = string(y.begin()+firstParen,y.end());
                        firstBracket = str2Search.find("[");
                        secondBracket = str2Search.find("]");
                        firstRed = str2Search.find("red");
                        if(firstRed != string::npos) {
                            if((firstRed > firstBracket) && (firstRed < secondBracket)) {
                                //Might need to iterate more
                            } else {
                                objects.clear();
                                objects.push_back(y);
                            }
                        }
                    } else {
                        objects.clear();
                        objects.push_back(y);
                    }
                }
            }
            if(objects.size() > 0)
                strAry.push_back(objects.back());
        }

//        regex re{"(red)"};
//
//        for(const auto& x : groups) {
//            int redCnt = 0;
//            objects.clear();
//            for( const auto& y : x) {
//                try {
//                    sregex_iterator next{y.begin(),y.end(),re};
//                    sregex_iterator end;
//                    int countMatches{0};
//                    while(next != end) {
//                        ++countMatches;
//                        ++next;
//                    }
//                    if(countMatches > redCnt) {
//                        objects.clear();
//                        objects.push_back(y);
//                        redCnt = countMatches;
//                    }
//                } catch (regex_error& e) {
//                    cout << "ERROR: " << e.what() << endl;
//                }
//            }
//            if(objects.size() > 0)
//                strAry.push_back(objects.back());
//        }

        return strAry;
    }
    
    void Item::PopulateItems(const std::string &s) {
        auto itr = s.begin();
        int parenCount = 0;
        int sqBracketCount = 0;
        
        if(*itr == '[') {
            isObject = false;
            isRed = false;
        } else if (*itr == '{'){
            isObject = true;
            isRed = false;
        } else {
            sqBracketCount = -1;
            isObject = false;
            nums = GetAllNumbersInString(s);
            isRed = s.find("red") != string::npos;
            return;
        }
        auto start = itr+1;
        
        while(sqBracketCount >= 0 && parenCount >= 0 && itr != s.end()) {
            ++itr;
            switch(*itr) {
                case '[':
                    sqBracketCount++;
                    break;
                    
                case ']':
                    sqBracketCount--;
                    break;
                    
                case '{':
                    parenCount++;
                    break;
                    
                case '}':
                    parenCount--;
                    break;
                    
                case ',':
                case ':':
                    if(0 == sqBracketCount && 0 == parenCount) {
                        strs.emplace_back(start,itr);
                        start = itr+1;
                    }
                    break;
            }
        }
        
        if(itr != start) {
            strs.emplace_back(start,itr);
        }
#ifdef DEBUG
        std::cout << "----------" << this << "-----------" << std::endl;
        for(int i = 0;i<strs.size();i++) {
            std::cout << i << "->" << strs[i] << std::endl;
        }
        std::cout << "---------------------" << std::endl;
        //Create Items from each string
#endif
        for(const auto& x : strs) {
            Item i;
            i.PopulateItems(x);
            items.push_back(i);
            if(isObject && !i.isObject && i.isRed) { isRed = true;}
        }
    }
    
    int Item::getSum() const {
        if(isRed)
            return 0;
        int sum = 0;
        for(const auto& x: items) {
            sum += x.getSum();
        }
        
        return std::accumulate(nums.begin(), nums.end(), sum);
    }
}

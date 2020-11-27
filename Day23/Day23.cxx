//
//  Advent of Code 2015 Solutions: Day 23
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/28/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day23.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
#include <functional>
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
namespace AocDay23 {

	static const std::string InputFileName = "Day23.txt";
	std::string solvea() {
        //Instructions
        unordered_map<string,int> regs{};
        int index{0};
        unordered_map<string, std::function<void (string,long)>> ops{
            {"hlf",[&regs,&index](string x,int){regs[x]/=2;index++;}},
            {"tpl",[&regs,&index](string x,int){regs[x]*=3;index++;}},
            {"inc",[&regs,&index](string x,int){regs[x]+=1;index++;}},
            {"jmp",[&index](string x,int){index+=stoi(x);}},
            {"jie",[&regs,&index](string x,int y){if(regs[x] %2 == 0) {index += y;}else {index++;}}},
            {"jio",[&regs,&index](string x,int y){if(regs[x] == 1) {index += y;}else {index++;}}},
        };
        
        auto instructions = parseFileForLines(InputFileName);
        
        while(index >= 0 && index < instructions.size()) {
            auto instruction = parseLineForWords(instructions[index]);
            if(instruction.size() == 3) {
                int y = stoi(instruction[2]);
                //remove ,
                string reg{instruction[1].begin(),instruction[1].end()-1};
                ops[instruction[0]](reg,y);
            } else {
                ops[instruction[0]](instruction[1],0);
            }
        }
		return to_string(regs["b"]);
	}

	std::string solveb() {
        //Instructions
        unordered_map<string,int> regs{{"a",1}};
        int index{0};
        unordered_map<string, std::function<void (string,long)>> ops{
            {"hlf",[&regs,&index](string x,int){regs[x]/=2;index++;}},
            {"tpl",[&regs,&index](string x,int){regs[x]*=3;index++;}},
            {"inc",[&regs,&index](string x,int){regs[x]+=1;index++;}},
            {"jmp",[&index](string x,int){index+=stoi(x);}},
            {"jie",[&regs,&index](string x,int y){if(regs[x] %2 == 0) {index += y;}else {index++;}}},
            {"jio",[&regs,&index](string x,int y){if(regs[x] == 1) {index += y;}else {index++;}}},
        };
        
        auto instructions = parseFileForLines(InputFileName);
        
        while(index >= 0 && index < instructions.size()) {
            auto instruction = parseLineForWords(instructions[index]);
            if(instruction.size() == 3) {
                int y = stoi(instruction[2]);
                //remove ,
                string reg{instruction[1].begin(),instruction[1].end()-1};
                ops[instruction[0]](reg,y);
            } else {
                ops[instruction[0]](instruction[1],0);
            }
        }
        return to_string(regs["b"]);
	}

}

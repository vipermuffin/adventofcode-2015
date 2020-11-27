//
//  Advent of Code 2015 Main Runner: Day 15
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/19/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay15{
   extern std::string solvea();
   extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

	std::cout << "Day15" << "a: " << AocDay15::solvea() << std::endl;
	std::cout << "Day15" << "b: " << AocDay15::solveb() << std::endl;
	return 0;
}

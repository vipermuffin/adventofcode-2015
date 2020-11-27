//
//  Advent of Code 2015 Main Runner: Day 21
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/27/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay21{
   extern std::string solvea();
   extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

	std::cout << "Day21" << "a: " << AocDay21::solvea() << std::endl;
	std::cout << "Day21" << "b: " << AocDay21::solveb() << std::endl;
	return 0;
}

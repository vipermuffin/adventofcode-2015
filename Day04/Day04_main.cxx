//
//  Advent of Code 2015 Main Runner: Day 4
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay04{
   extern std::string solvea();
   extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

	std::cout << "Day04" << "a: " << AocDay04::solvea() << std::endl;
	std::cout << "Day04" << "b: " << AocDay04::solveb() << std::endl;
	return 0;
}

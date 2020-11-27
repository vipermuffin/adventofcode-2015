//
//  Advent of Code 2015 Tests: Day 14
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day14.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay14{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay14;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("2696", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("1084", solveb());
}

TEST(Example,Test1) {
    ReindeerFlyer r{14,10,127,"Comet"};
    r.step();
	EXPECT_EQ(14,r.distance());
}

TEST(Example,Test2) {
	ReindeerFlyer r{14,10,127,"Comet"};
    r.step(11);
	EXPECT_EQ(140,r.distance());
}

TEST(Example,Test2b) {
    ReindeerFlyer r{14,10,127,"Comet"};
    r.step(137);
    EXPECT_EQ(140,r.distance());
}

TEST(Example,Test2c) {
    ReindeerFlyer r{14,10,127,"Comet"};
    r.step(138);
    EXPECT_EQ(154,r.distance());
}

TEST(Example,Test2d) {
    ReindeerFlyer r{14,10,127,"Comet"};
    r.step(139);
    EXPECT_EQ(168,r.distance());
}

TEST(Example,Test2e) {
    ReindeerFlyer r{14,10,127,"Comet"};
    r.step(148);
    EXPECT_EQ(280,r.distance());
}

TEST(Example,Test3) {
    ReindeerFlyer r{14,10,127,"Comet"};
    r.step(1000);
	EXPECT_EQ(1120,r.distance());
}

TEST(Example,ReadReindeer1) {
    vector<string> input{
        {"Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds."},
        {"Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds."}
    };
    auto deer = ReadInReindeer(input);
    ASSERT_EQ(2,deer.size());
    deer[0].step(1000);
    EXPECT_EQ(1120,deer[0].distance());
    deer[1].step(1000);
    EXPECT_EQ(1056,deer[1].distance());
}

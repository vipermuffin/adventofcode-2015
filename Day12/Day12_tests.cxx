//
//  Advent of Code 2015 Tests: Day 12
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day12.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay12{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay12;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("156366", solvea());
}

TEST(SolvePartB, FinalSolution) {
	EXPECT_EQ("96852", solveb());
}

TEST(Example,Test1) {
    string s{"{\"a\":2,\"b\":4}"};
    auto x = GetAllNumbersInString(s);
    ASSERT_EQ(2,x.size());
	EXPECT_EQ(2,x[0]);
    EXPECT_EQ(4,x[1]);
}

TEST(Example,Test2) {
    string s{"[-2,232,222,0]"};
    auto x = GetAllNumbersInString(s);
    ASSERT_EQ(4,x.size());
    EXPECT_EQ(-2,x[0]);
    EXPECT_EQ(232,x[1]);
    EXPECT_EQ(222,x[2]);
    EXPECT_EQ(0,x[3]);
}

TEST(Example,Test3) {
    string s{"[1,{\"c\":\"red\",\"b\":2},3]"};
    auto x = GetAllRedObjectsInString(s);
    ASSERT_EQ(1,x.size());
    EXPECT_EQ("\"c\":\"red\",\"b\":2",x[0]);
}

TEST(Example,Test4) {
    string s{"[1,\"red\",5]"};
    auto x = GetAllRedObjectsInString(s);
    EXPECT_EQ(0,x.size());
}

TEST(Example,Test5) {
    string s{"[1,{\"c\":\"red\",\"b\":2},3][3,{\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5},2]"};
    auto x = GetAllRedObjectsInString(s);
    ASSERT_EQ(2,x.size());
    EXPECT_EQ("\"c\":\"red\",\"b\":2",x[0]);
    EXPECT_EQ("\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5",x[1]);
}

TEST(Example,Test6) {
    string s{"[1,{\"c\":\"red\",\"b\":2},3]{3,{\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5},2}"};
    auto x = GetAllRedObjectsInString(s);
    ASSERT_EQ(2,x.size());
    EXPECT_EQ("\"c\":\"red\",\"b\":2",x[0]);
    EXPECT_EQ("\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5",x[1]);
}

TEST(Example,Test7) {
    string s{"[1,{\"c\":\"red\",\"b\":2},3]{3,\"red\",{\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5},2}"};
    auto x = GetAllRedObjectsInString(s);
    ASSERT_EQ(2,x.size());
    EXPECT_EQ("\"c\":\"red\",\"b\":2",x[0]);
    EXPECT_EQ("3,\"red\",{\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5},2",x[1]);
}

TEST(Example,Test8) {
    string s{"[1,{\"c\":\"red\",\"b\":2},3][3,\"red\",{\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5},2]"};
    auto x = GetAllRedObjectsInString(s);
    ASSERT_EQ(2,x.size());
    EXPECT_EQ("\"c\":\"red\",\"b\":2",x[0]);
    EXPECT_EQ("\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5",x[1]);
}

TEST(Example,Test9) {
    string s{"[1,{\"c\":\"red\",\"b\":2},3,[3,\"red\",{\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5},2]]"};
    Item i;
    i.PopulateItems(s);
    auto x = i.strs.size();
    ASSERT_EQ(4,x);
    EXPECT_EQ(9,i.getSum());
}

TEST(Example,Test10) {
    string s{"[1,{\"c\":\"red\",\"b\":2},3]"};
    Item i;
    i.PopulateItems(s);
    EXPECT_EQ(4,i.getSum());
}

TEST(Example,Test11) {
    string s{"[1,\"red\",5]"};
    Item i;
    i.PopulateItems(s);
    EXPECT_EQ(6,i.getSum());
}

TEST(Example,Test12) {
    string s{"[1,2,3]"};
    Item i;
    i.PopulateItems(s);
    EXPECT_EQ(6,i.getSum());
}

TEST(Example,Test13) {
    string s{"{\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5}"};
    Item i;
    i.PopulateItems(s);
    EXPECT_EQ(0,i.getSum());
}

TEST(Example,Test14) {
    string s{"{\"a\":{\"b\":4,red},\"c\":-1}"};
    Item i;
    i.PopulateItems(s);
    EXPECT_EQ(-1,i.getSum());
}

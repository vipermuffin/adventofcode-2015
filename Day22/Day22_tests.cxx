//
//  Advent of Code 2015 Tests: Day 22
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/28/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day22.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay22{
	extern std::string solvea();
	extern std::string solveb();
}

using namespace std;
using namespace AocDay22;

TEST(SolvePartA, FinalSolution) {
	EXPECT_EQ("1269", solvea());
}

TEST(SolvePartB, FinalSolution) {
    EXPECT_EQ("1309", solveb());
}

TEST(Example,TestFighterEffectsDelayedDamage) {
    Fighter f(50,0,0);
    Effect e(5, 0, 0, 3);
    f += e;
	EXPECT_EQ(50,f.hp);
    f.ProcessEffects();
    EXPECT_EQ(45,f.hp);
    f.ProcessEffects();
    EXPECT_EQ(40,f.hp);
    f.ProcessEffects();
    EXPECT_EQ(35,f.hp);
    f.ProcessEffects();
    EXPECT_EQ(35,f.hp);
}

TEST(Example,TestFighterEffectsImmediate) {
    Fighter f(50,0,0);
    Effect e(5, 0, 0, -1);
    f += e;
    EXPECT_EQ(45,f.hp);
    f.ProcessEffects();
    EXPECT_EQ(45,f.hp);
    f.ProcessEffects();
    EXPECT_EQ(45,f.hp);
}

TEST(Example,TestFighterEffectsDelayedArmor) {
    Fighter f(50,0,0);
    Fighter b(10,10,0);
    Effect e(0, 5, 0, 2);
    f += e;
    f -= b;
    EXPECT_EQ(40,f.hp);
    f.ProcessEffects();
    f -= b;
    EXPECT_EQ(35,f.hp);
    f.ProcessEffects();
    f -= b;
    EXPECT_EQ(30,f.hp);
    f.ProcessEffects();
    f -= b;
    EXPECT_EQ(20,f.hp);
}

TEST(Example,TestFighterEffectsDelayedArmorPlusHealth) {
    Fighter f(50,0,0);
    Fighter b(10,10,0);
    Effect e(-2, 5, 0, 2);
    f += e;
    f -= b;
    EXPECT_EQ(40,f.hp);
    f.ProcessEffects();
    f -= b;
    EXPECT_EQ(37,f.hp);
    f.ProcessEffects();
    f -= b;
    EXPECT_EQ(34,f.hp);
    f.ProcessEffects();
    f -= b;
    EXPECT_EQ(24,f.hp);
}

TEST(Example,TestFighterEffectsDelayedArmorPlusHealthCombined) {
    Fighter f(50,0,0);
    Fighter b(10,10,0);
    Effect e(0, 5, 0, 2);
    f += e;
    e.armor = 0;
    e.damage = -2;
    e.duration = 3;
    f += e;
    f -= b;
    EXPECT_EQ(40,f.hp);
    f.ProcessEffects();
    f -= b;
    EXPECT_EQ(37,f.hp);
    f.ProcessEffects();
    f -= b;
    EXPECT_EQ(34,f.hp);
    f.ProcessEffects();
    f -= b;
    EXPECT_EQ(26,f.hp);
    f.ProcessEffects();
    f -= b;
    EXPECT_EQ(16,f.hp);
}

TEST(Example,WizardEffectAddingMana) {
    Wizard w(50,222);
    
	EXPECT_EQ(50,w.hp);
    EXPECT_EQ(0,w.armor);
    EXPECT_EQ(0,w.damage);
    EXPECT_EQ(222,w.mana);
    
    Effect e(0,0,22,4);
    w += e;
    w.ProcessEffects();
    EXPECT_EQ(244,w.mana);
    w.ProcessEffects();
    EXPECT_EQ(266,w.mana);
    w.ProcessEffects();
    EXPECT_EQ(288,w.mana);
    w.ProcessEffects();
    EXPECT_EQ(310,w.mana);
    w.ProcessEffects();
    EXPECT_EQ(310,w.mana);
}

TEST(Example,Test3) {
    vector<Spell> v {Spell::MagicMissle,Spell::Drain,Spell::MagicMissle,Spell::Poison,Spell::Recharge,Spell::Poison};
	EXPECT_EQ("mmdppr",generateStringFromVector(v));
}

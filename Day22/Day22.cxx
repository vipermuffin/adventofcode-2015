//
//  Advent of Code 2015 Solutions: Day 22
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/28/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day22.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
#include <set>
#include <sstream>

//#include <unordered_map>
//#include <unordered_set>
#include <cstdlib>
#define THREADED
#ifdef THREADED
#include <array>
#include <thread>
#endif

using namespace std;
namespace AocDay22 {
#ifdef THREADED
    void simulateBattleThread(Spell,int&,bool);
    void do_join(std::thread& t);
#endif
//1475 too high
	static const std::string InputFileName = "Day22.txt";
    std::string solvea() {
        int minCost = INT_MAX;
        const vector<Spell> spells{Spell::Recharge,Spell::Shield,Spell::Poison,Spell::Drain,Spell::MagicMissle};
#ifndef THREADED
        Wizard player{50,500};
        Fighter boss{58,9,0};

        for(const auto& s : spells) {
            int i = simulateBattle(player, boss, s, minCost);
            if(i < minCost) {
                minCost = i;
            }
        }
#else
        vector<thread> tV{};
        array<int,5> mins{INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
        int i = 0;
        tV.reserve(5);
        for(const auto& s : spells) {
            tV.emplace_back(simulateBattleThread,s,std::ref(mins[i]),false);
            i++;
        }
        for_each(tV.begin(),tV.end(),do_join);
        minCost = *std::min_element(mins.begin(),mins.end());
#endif
        return to_string(minCost);
    }
    //1804 too high
    //1362 too high
    //1349 too high
    std::string solveb() {
        int minCost = INT_MAX;
        const vector<Spell> spells{Spell::Recharge,Spell::Shield,Spell::Poison,Spell::Drain,Spell::MagicMissle};
#ifndef THREADED
        Wizard player{50,500};
        Fighter boss{58,9,0};
        
        for(const auto& s : spells) {
            int i = simulateBattle(player, boss, s, minCost,true);
            if(i < minCost) {
                minCost = i;
            }
        }
#else
        vector<thread> tV{};
        array<int,5> mins{INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
        int i = 0;
        tV.reserve(5);
        for(const auto& s : spells) {
            tV.emplace_back(simulateBattleThread,s,std::ref(mins[i]),true);
            i++;
        }
        for_each(tV.begin(),tV.end(),do_join);
        minCost = *std::min_element(mins.begin(),mins.end());
#endif
        return to_string(minCost);
    }
#ifdef THREADED
    void do_join(std::thread& t) {
        t.join();
    }
    void simulateBattleThread(Spell startSpell,int& min, bool partB) {
        Wizard player{50,500};
        Fighter boss{58,9,0};
        min = simulateBattle(player, boss, startSpell, INT_MAX, partB);
    }
#endif
    int simulateBattle(Wizard player, Fighter boss, Spell spell, int minFound, bool partB) {
        //Player Turn
        if(partB)
            player.hp--;
        if(player.hp <= 0) {
            return INT_MAX;
        }
        player.ProcessEffects();
        boss.ProcessEffects();
        if(boss.hp <= 0) {
            return player.cost;
        }
        if(player.hp <= 0 || !player.CanCast(spell)) {
            return INT_MAX;
        }
        auto e = player.CastSpell(spell);
        player += e.first;
        boss += e.second;

        //Boss Turn
        player.ProcessEffects();
        boss.ProcessEffects();
        if(boss.hp <= 0) {
            return player.cost;
        }
        
        player -= boss;
        if(player.hp <= 0 || player.cost > minFound) {
            return INT_MAX;
        }
        //Search next spells
        const vector<Spell> spells{Spell::Recharge,Spell::Shield,Spell::Poison,Spell::Drain,Spell::MagicMissle};
        for(const auto& s : spells) {
            int i = simulateBattle(player, boss, s, minFound,partB);
            if(i < minFound) {
                minFound = i;
            }
        }
        return minFound;
    }
#if 0
    //All my losing functions...
    bool simulateBattle(Wizard& player, Fighter& boss) {
        bool playerTurn = true;
        while(player.hp > 0 && player.mana > static_cast<int>(Spell::MagicMissle) && boss.hp) {
            if(playerTurn) {
                Spell s = getRandomSpell();
                while(!player.CanCast(s)) {
                    s = getRandomSpell();
                }
                auto e = player.CastSpell(s);
                player += e.first;
                boss += e.second;
            } else {
                player -= boss;
            }
            playerTurn = !playerTurn;
            player.ProcessEffects();
            boss.ProcessEffects();
        }
        return boss.hp <= 0;
    }
    
    bool simulateBattle(Wizard& player, Fighter& boss, const std::vector<Spell>& spells, bool partB) {
        bool playerTurn = true;
        if(partB)
            player.hp--;
        int index = 0;
        int minSpellCost = 999;
        for(int i = 0; i < spells.size(); i++) {
            if(static_cast<int>(spells[i]) < minSpellCost) {
                minSpellCost = static_cast<int>(spells[i]);
            }
        }
        while(player.hp > 0 && player.mana >= minSpellCost && boss.hp) {
            if(playerTurn) {
                int c = 0;
                Spell s = spells[index++];
                if(index == spells.size()) {
                    index = 0;
                }
                while(!player.CanCast(s)) {
                    c++;
                    s = spells[index++];
                    if(index == spells.size()) {
                        index = 0;
                    }
                    if(c > spells.size()) {
                        return false;
                    }
                }
                auto e = player.CastSpell(s);
                player += e.first;
                boss += e.second;
            } else {
                player -= boss;
            }
            playerTurn = !playerTurn;
            if(partB && playerTurn) {
                player.hp--;
                if(player.hp == 0) {
                    return false;
                }
            }
            player.ProcessEffects();
            boss.ProcessEffects();
        }
        return boss.hp <= 0;
    }
    
    Spell getRandomSpell() {
        srand(time(NULL));
        int v1 = rand() % 6;
        if(v1 == 0) {
            return Spell::MagicMissle;
        } else if (v1 == 1) {
            return Spell::Drain;
        } else if (v1 == 2) {
            return Spell::Poison;
        } else if (v1 == 3) {
            return Spell::Recharge;
        } else if (v1 == 4) {
            return Spell::Shield;
        }
        return Spell::MagicMissle;
    }
#endif
    std::string generateStringFromVector(std::vector<Spell> v) {
        stringstream ss{};
        std::sort(v.begin(),v.end());
        for(auto& s : v) {
            switch(s) {
                case Spell::Drain:
                    ss << "d";
                    break;
                case Spell::MagicMissle:
                    ss << "m";
                    break;
                case Spell::Poison:
                    ss << "p";
                    break;
                case Spell::Recharge:
                    ss << "r";
                    break;
                case Spell::Shield:
                    ss << "s";
                    break;
            }
        }
        return ss.str();
    }

    
}

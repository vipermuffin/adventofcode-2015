//
//  Advent of Code 2015 Solutions: Day 21
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/27/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day21.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay21 {

    vector<Item> weapons {
        Item{8 ,     4,       0},
        Item{10,     5,       0},
        Item{25,     6,       0},
        Item{40,     7,       0},
        Item{74,     8,       0}
    };
    
    vector<Item> armors {
        Item{ 13,     0,       1},
        Item{ 31,     0,       2},
        Item{ 53,     0,       3},
        Item{ 75,     0,       4},
        Item{102,     0,       5}
    };
    
    vector<Item> rings {
        Item{ 25,     1,       0},
        Item{ 50,     2,       0},
        Item{100,     3,       0},
        Item{ 20,     0,       1},
        Item{ 40,     0,       2},
        Item{ 80,     0,       3}
    };
    
    const Fighter Player{100,0,0};
    const Fighter Boss{109,8,2};
    
	static const std::string InputFileName = "Day21.txt";
	std::string solvea() {
        auto x = buildCombinations(Player);
        auto p = x.begin();
        while(p != x.end() && !simulateBattle(*p, Boss)) {
            ++p;
        }
        if(p != x.end()) {
            return to_string(p->cost);
        }
		return "---";
	}

	std::string solveb() {
        auto x = buildCombinations(Player);
        auto p = x.rbegin();
        while(p != x.rend() && simulateBattle(*p, Boss)) {
            ++p;
        }
        if(p != x.rend()) {
            return to_string(p->cost);
        }
        return "---";
	}

    bool simulateBattle(Fighter player, Fighter boss){
        bool playerTurn = true;
        while(player.hp > 0 && boss.hp > 0) {
            if(playerTurn) {
                boss -= player;
            } else {
                player -= boss;
            }
            playerTurn = !playerTurn;
        }
        return player.hp > 0;
    }
    
    bool FighterCompCost (const Fighter& lhs, const Fighter& rhs) {
        return lhs.cost < rhs.cost;
    }
    
    std::vector<Fighter> buildCombinations(const Fighter& naked) {
        vector<Fighter> players;
        players.reserve(5000);
        
        //One weapon required
        for(int i = 0; i<weapons.size();++i) {
            Fighter f{naked};
            f += weapons[i];
            players.push_back(f);
            //Armor is optional
            for(int j = 0; j < armors.size();++j) {
                Fighter fa{f};
                fa += armors[j];
                players.push_back(fa);
            }
        }
        
        CombinationGenerator<Item> cg{rings};
        vector<Fighter> playersWRings;
        playersWRings.reserve(1800);

        for(int i = 2;i >= 1; --i) {
            vector<vector<Item>> ringCombos = cg.generateCombosChoose(i);
            for(const auto& combos : ringCombos) {
                for(const auto& f : players) {
                    Fighter fp{f};
                    for(const auto& item : combos) {
                        fp += item;
                    }
                    playersWRings.push_back(fp);
                }
            }
        }
        
        players.insert(players.end(), playersWRings.begin(),playersWRings.end());
        sort(players.begin(),players.end(),FighterCompCost);

        return players;
    }
}

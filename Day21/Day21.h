//
//  Advent of Code 2015 Solutions: Day 21
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/27/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay21 {
//Function Definitions

    struct Item {
        Item() = default;
        Item(int c, int d, int a) {
            cost = c;
            damage = d;
            armor = a;
        }
        ~Item() = default;
        int damage;
        int armor;
        int cost;
    };
    
    class Fighter {
    public:
        Fighter(int hp, int damage, int armor) : _hp{hp},_damage{damage},_armor{armor}{resetStats();}
        Fighter(const Fighter& f) {
            this->_hp = f._hp;
            this->_damage = f._damage;
            this->_armor = f._armor;
            this->hp = f.hp;
            this->damage = f.damage;
            this->armor = f.armor;
            this->cost = f.cost;
        }
        ~Fighter() = default;
        
        void resetStats(){
            hp = _hp;
            damage = _damage;
            armor = _armor;
            cost = 0;
        }
        Fighter& operator -=(const Fighter& rhs) {
            int d = rhs.damage-this->armor;
            this->hp -= (d > 1) ? d : 1;
            return *this;
        }
        
        Fighter& operator +=(const Item& rhs) {
            damage += rhs.damage;
            armor += rhs.armor;
            cost += rhs.cost;
            return *this;
        }
        
        int hp;
        int damage;
        int armor;
        int cost;
    private:
        int _hp;
        int _damage;
        int _armor;
        
    };
    
    bool simulateBattle(Fighter player, Fighter boss);
    std::vector<Fighter> buildCombinations(const Fighter& naked);
}

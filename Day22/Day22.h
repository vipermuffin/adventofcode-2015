//
//  Advent of Code 2015 Solutions: Day 22
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on 11/28/2018.
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

namespace AocDay22 {
//Function Definitions
    struct Effect {
        Effect() = default;
        Effect(int d, int a, int m, int t) {
            damage = d;
            armor = a;
            mana = m;
            duration = t;
        }
        ~Effect() = default;
        int damage;
        int armor;
        int mana;
        int duration;
    };
    
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
            for(const auto& e : f.effects) {
                effects.push_back(e);
            }
        }
        ~Fighter() = default;
        
        virtual void resetStats(){
            hp = _hp;
            damage = _damage;
            armor = _armor;
            cost = 0;
            _armorOffset = 0;
            effects.clear();
        }
        Fighter& operator -=(const Fighter& rhs) {
            int d = rhs.damage-(this->armor+this->_armorOffset);
            this->hp -= (d > 1) ? d : 1;
            return *this;
        }
        
        Fighter& operator +=(const Item& rhs) {
            damage += rhs.damage;
            armor += rhs.armor;
            cost += rhs.cost;
            return *this;
        }
        
        virtual Fighter& operator +=(const Effect& rhs) {
            if(rhs.duration <= 0) {
                hp -= rhs.damage;
                armor += rhs.armor;
            }
            else {
                effects.push_back(rhs);
            }
            return *this;
        }
        
        virtual void ProcessEffects() {
            auto itr = effects.begin();
            _armorOffset = 0;
            while(itr != effects.end()) {
                if(itr->duration > 0) {
                    itr->duration--;
                    hp -= itr->damage;
                    _armorOffset += itr->armor;
                }
                itr++;
            }
        }
        
        int hp;
        int damage;
        int armor;
        int cost;
    protected:
        int _armorOffset;
        int _hp;
        int _damage;
        int _armor;
        std::vector<Effect> effects;
    };

    enum class Spell {MagicMissle=53,Drain=73,Shield=113,Poison=173,Recharge=229};
    
    class Wizard : public Fighter {
    public:
        Wizard(int hp, int mana) : Fighter(hp,0,0), _mana{mana} {
            resetStats();
        }
        
        Wizard(const Wizard& w) : Fighter(w) {
            this->mana = w.mana;
            this->_mana = w._mana;
            for(const auto& kvp : w._activeSpells) {
                _activeSpells[kvp.first] = kvp.second;
            }
        }
        
        virtual void resetStats(){
            Fighter::resetStats();
            mana = _mana;
            _activeSpells.clear();
        }
        
        virtual void ProcessEffects() {
            auto itr = effects.begin();
            _armorOffset = 0;
            while(itr != effects.end()) {
                if(itr->duration > 0) {
                    itr->duration--;
                    hp -= itr->damage;
                    _armorOffset += itr->armor;
                    mana += itr->mana;
                }
                itr++;
            }
            auto sItr = _activeSpells.begin();
            while(sItr != _activeSpells.end()) {
                if(sItr->second > 0) {
                    sItr->second--;
                }
                sItr++;
            }
        }
        
        bool CanCast(Spell s) {
            return mana > static_cast<int>(s) && _activeSpells[static_cast<int>(s)] == 0;
        }
        
        std::pair<Effect,Effect> CastSpell(Spell s) {
            Effect MageE(0,0,0,0);
            Effect BossE(0,0,0,0);
            
            mana -= static_cast<int>(s);
            cost += static_cast<int>(s);
            switch(s) {
                case Spell::MagicMissle:
                    BossE.duration = -1;
                    BossE.damage = 4;
//                    std::cout << "CAST: Magic Missle\n";
                    break;
                    
                case Spell::Drain:
                    BossE.damage = 2;
                    BossE.duration = -1;
                    hp += 2;
                    //MageE.damage = -2;
                    //MageE.duration = -1;
//                    std::cout << "CAST: Drain\n";
                    break;
                    
                case Spell::Shield:
                    MageE.armor = 7;
                    MageE.duration = 6;
                    _activeSpells[static_cast<int>(s)] = 6;
//                    std::cout << "CAST: Shield\n";
                    break;
                    
                case Spell::Poison:
                    BossE.damage = 3;
                    BossE.duration = 6;
                    _activeSpells[static_cast<int>(s)] = 6;
//                    std::cout << "CAST: Poison\n";
                    break;
                    
                case Spell::Recharge:
                    MageE.mana = 101;
                    MageE.duration = 5;
                    _activeSpells[static_cast<int>(s)] = 6;
//                    std::cout << "CAST: Recharge\n";
                    break;
            }
            return std::make_pair(MageE, BossE);
        }
        
        int mana;
    private:
        int _mana;
        std::unordered_map<int,int> _activeSpells;
    };
    
    bool simulateBattle(Wizard& player, Fighter& boss);
    bool simulateBattle(Wizard& player, Fighter& boss, const std::vector<Spell>& spells,bool partB=false);
    int simulateBattle(Wizard player, Fighter boss, Spell spell,int minFound, bool partB=false);
    Spell getRandomSpell();
    std::string generateStringFromVector(std::vector<Spell> v);
}

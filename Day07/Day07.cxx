//
//  Advent of Code 2015 Solutions: Day 7
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <iomanip> //setfill setw hex
#include <map>
//#include <math.h> //sqrt
//#include <queue>
//#include <regex>
//#include <set>
#include <sstream>
#include <string>
//#include <thread>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay07 {

	static const std::string InputFileName = "Day07.txt";
	std::string solvea() {
        auto definitions{parseFileForLines(InputFileName)};
        map<string,Component> dict;
        
        //Build components
        for(const auto& def : definitions) {
            LogicGateType lt = determineComponentType(def);
            auto words = parseLineForWords(def);
            Component c{lt};
            dict.emplace(make_pair(words.back(),c));
        }
        
        //Link Components
        for(const auto& def : definitions) {
            LogicGateType lt = determineComponentType(def);
            auto words = parseLineForWords(def);
            switch(lt) {
                case LogicGateType::And:
                case LogicGateType::Or:
                case LogicGateType::lShift:
                case LogicGateType::rShift:
                {
                    if(dict.count(words[0]) == 0 ) {
                        //Must be a constant
                        Component c{static_cast<uint16_t>(stoi(words[0]))};
                        dict.emplace(make_pair(words[0], c));
                    }
                    if(dict.count(words[2]) == 0 ) {
                        //Must be a constant
                        Component c{static_cast<uint16_t>(stoi(words[2]))};
                        dict.emplace(make_pair(words[2], c));
                    }
                    if(dict.count(words.back()) > 0) {
                        Component& c = dict[words.back()];
                        if(dict.count(words[0]) > 0) {
                            c.setLhs(&dict[words[0]]);
                        }
                        if(dict.count(words[2]) > 0) {
                            c.setRhs(&dict[words[2]]);
                        }
                    }
                    
                    
                }
                    break;
                case LogicGateType::Not:
                {
                    if(dict.count(words[1]) == 0 ) {
                        //Must be a constant
                        Component c{static_cast<uint16_t>(stoi(words[0]))};
                        dict.emplace(make_pair(words[0], c));
                    }

                    Component& c = dict[words.back()];
                    c.setLhs(&dict[words[1]]);
                }
                    break;
                case LogicGateType::None:
                {
                    if(dict.count(words[0]) == 0 ) {
                        //Must be a constant
                        Component c{static_cast<uint16_t>(stoi(words[0]))};
                        dict.emplace(make_pair(words[0], c));
                    }
                    
                    Component& c = dict[words.back()];
                    c.setLhs(&dict[words[0]]);
                }
                    break;
            }
        }

		return to_string(dict["a"].value());
	}

	std::string solveb() {
        auto definitions{parseFileForLines(InputFileName)};
        map<string,Component> dict;
        auto it = definitions.begin();
        while(it < definitions.end()) {
            auto words = parseLineForWords(*it);
            if(words.back() == "b") {
                *it = solvea() + " -> b";
            }
            it++;
        }
        //Build components
        for(const auto& def : definitions) {
            LogicGateType lt = determineComponentType(def);
            auto words = parseLineForWords(def);
            Component c{lt};
            dict.emplace(make_pair(words.back(),c));
        }
        
        //Link Components
        for(const auto& def : definitions) {
            LogicGateType lt = determineComponentType(def);
            auto words = parseLineForWords(def);
            switch(lt) {
                case LogicGateType::And:
                case LogicGateType::Or:
                case LogicGateType::lShift:
                case LogicGateType::rShift:
                {
                    if(dict.count(words[0]) == 0 ) {
                        //Must be a constant
                        Component c{static_cast<uint16_t>(stoi(words[0]))};
                        dict.emplace(make_pair(words[0], c));
                    }
                    if(dict.count(words[2]) == 0 ) {
                        //Must be a constant
                        Component c{static_cast<uint16_t>(stoi(words[2]))};
                        dict.emplace(make_pair(words[2], c));
                    }
                    if(dict.count(words.back()) > 0) {
                        Component& c = dict[words.back()];
                        if(dict.count(words[0]) > 0) {
                            c.setLhs(&dict[words[0]]);
                        }
                        if(dict.count(words[2]) > 0) {
                            c.setRhs(&dict[words[2]]);
                        }
                    }
                    
                    
                }
                    break;
                case LogicGateType::Not:
                {
                    if(dict.count(words[1]) == 0 ) {
                        //Must be a constant
                        Component c{static_cast<uint16_t>(stoi(words[0]))};
                        dict.emplace(make_pair(words[0], c));
                    }
                    
                    Component& c = dict[words.back()];
                    c.setLhs(&dict[words[1]]);
                }
                    break;
                case LogicGateType::None:
                {
                    if(dict.count(words[0]) == 0 ) {
                        //Must be a constant
                        Component c{static_cast<uint16_t>(stoi(words[0]))};
                        dict.emplace(make_pair(words[0], c));
                    }
                    
                    Component& c = dict[words.back()];
                    c.setLhs(&dict[words[0]]);
                }
                    break;
            }
        }
		return to_string(dict["a"].value());
	}

    Component::Component() :
    _val{0},
    _type(LogicGateType::None),
    _lhs(nullptr),
    _rhs(nullptr),
    _p(nullptr),
    _cached(false){}
    
    Component::Component(uint16_t val) :
    _val{val},
    _type(LogicGateType::None),
    _lhs(nullptr),
    _rhs(nullptr),
    _p(nullptr),
    _cached(false){}
    
    Component::Component(LogicGateType type) :
    _val{0},
    _type(type),
    _lhs(nullptr),
    _rhs(nullptr),
    _p(nullptr),
    _cached(false){}
    
    Component::Component(LogicGateType type,Component* lhs,Component* rhs) :
    _val{0},
    _type(type),
    _lhs(lhs),
    _rhs(rhs),
    _p(nullptr),
    _cached(false){
        if(lhs != nullptr) {
            lhs->setParent(this);
        }
        if(rhs != nullptr) {
            rhs->setParent(this);
        }
    }
    
    Component::~Component() {
        _lhs = nullptr;
        _rhs = nullptr;
        _p = nullptr;
    }
    
    uint16_t Component::value() {
        if(_cached) {
            return _val;
        }
        uint16_t lhs = (_lhs != nullptr) ? _lhs->value() : _val;
        uint16_t rhs = (_rhs != nullptr) ? _rhs->value() : 0;
        uint16_t result;
        switch(_type) {
            case LogicGateType::None:
                result = lhs;
                break;
            case LogicGateType::And:
                result = lhs & rhs;
                break;
            case LogicGateType::Or:
                result = lhs | rhs;
                break;
            case LogicGateType::lShift:
                result = lhs << rhs;
                break;
            case LogicGateType::rShift:
                result = lhs >> rhs;
                break;
            case LogicGateType::Not:
                result = ~lhs;
                break;
        }
        _val = result;
        _cached = true;
        return result;
    }
    
    LogicGateType determineComponentType(const std::string& def) {
        auto words{parseLineForWords(def)};
        if(words.size() == 3) {
            return LogicGateType::None;
        } else if(def.find("AND") != string::npos) {
            return LogicGateType::And;
        } else if(def.find("OR") != string::npos) {
            return LogicGateType::Or;
        } else if(def.find("LSHIFT") != string::npos) {
            return LogicGateType::lShift;
        } else if(def.find("RSHIFT") != string::npos) {
            return LogicGateType::rShift;
        } else if(def.find("NOT") != string::npos) {
            return LogicGateType::Not;
        }
        return LogicGateType::None;
    }
}

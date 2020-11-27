//
//  Advent of Code 2015 Solutions: Day 7
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay07 {
//Function Definitions   
    enum class LogicGateType {And,Or,Not,lShift,rShift,None};
    
    class Component {
    public:
        Component(); // Needed for use in map
        Component(uint16_t);
        Component(LogicGateType);
        Component(LogicGateType,Component* lhs,Component* rhs);
        ~Component();
        void setLhs(Component* lhs) {_lhs = lhs;lhs->setParent(this);_cached=false;if(_p != nullptr) {_p->invalidateCache();}}
        void setRhs(Component* rhs) {_rhs = rhs;rhs->setParent(this);_cached=false;if(_p != nullptr) {_p->invalidateCache();}}
        void setParent(Component* p) {_p = p;_cached=false;}
        void invalidateCache() {_cached=false;}
        virtual uint16_t value();
        
    private:
        uint16_t _val;
        LogicGateType _type;
        Component* _lhs;
        Component* _rhs;
        Component* _p;
        bool _cached;
    };
    
    LogicGateType determineComponentType(const std::string&);
}

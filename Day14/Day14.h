//
//  Advent of Code 2015 Solutions: Day 14
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

#define GENERIC_TRAVLER

namespace AocDay14 {
//Function Definitions
#ifndef GENERIC_TRAVLER
    class ReindeerFlyer {
    public:
        ReindeerFlyer(const int, const int, const int, const std::string&);
        ReindeerFlyer() = delete;
        ~ReindeerFlyer(){}
        void setSpeedInKps(const int);
        void setName(const std::string&);
        void setRestTimeInS(const int);
        void setFlyTimeInS(const int);
        void step();
        void step(int);
        void reset();
        int distance() const;
        std::string name() const;
        
    private:
        int _speedInKps;
        int _flyTimeInS;
        int _restTimeInS;
        int _totalDistanceTraveledInKm;
        int _currentTimeStepInS;
        int _flyTimerInS;
        int _restTimerInS;
        std::string _name;
    };
#else
    #include "LinearTraveler.h"
    class ReindeerFlyer : public AocUtils::LinearTraveler<int> {
    public:
        ReindeerFlyer(const int, const int, const int, const std::string&);
        ReindeerFlyer() = delete;
        ~ReindeerFlyer(){}
        int distance() const;
    };
#endif
    std::vector<ReindeerFlyer> ReadInReindeer(const std::vector<std::string>& input);
}

//
//  Advent of Code 2015 Solutions: Day 14
//
//  https://adventofcode.com/2015
//
//  Created by vipermuffin on .
//  Copyright © 2018 vipermuffin. All rights reserved.
//

#include "Day14.h"
#include "AoCUtils.h"
//Common Libraries
//#include <algorithm> //std::sort
//#include <chrono>
#include <iostream>
//#include <fstream> //ifstream
//#include <iomanip> //setfill setw hex
#include <map>
//#include <math.h> //sqrt
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
#include <string>
//#include <thread>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay14 {

	static const std::string InputFileName = "Day14.txt";
	std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto deer = ReadInReindeer(input);
        int max = 0;
        for(auto& d : deer) {
            d.step(2503);
//            cout << d.name() << ":" << d.distance() << endl;
            if(d.distance() > max) {
                max = d.distance();
            }
        }
		return to_string(max);
	}

	std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto deer = ReadInReindeer(input);
        map<string,int> score{};
        for(const auto& d : deer) {
            score[d.name()] = 0;
        }
        vector<string> leader;
        int max = 0;
        for(int i = 0; i < 2503;++i) {
            max = 0;
            leader.clear();
            for(auto& d : deer) {
                d.step();
                if(d.distance() > max) {
                    max = d.distance();
                    leader.clear();
                    leader.push_back(d.name());
                } else if (d.distance() == max) {
                    leader.push_back(d.name());
                }
            }
            for(const auto& n : leader) {
                score[n]++;
            }
        }
        
        max = 0;
        for(const auto & d : score) {
            if(d.second > max) {
                max = d.second;
            }
        }

		return to_string(max);
	}
    
#ifndef GENERIC_TRAVLER
    ReindeerFlyer::ReindeerFlyer(const int speed, const int flyTime, const int restTime, const std::string& name) :
    _speedInKps(speed),
    _flyTimeInS(flyTime),
    _restTimeInS(restTime),
    _totalDistanceTraveledInKm(0),
    _currentTimeStepInS(0),
    _flyTimerInS(0),
    _restTimerInS(0),
    _name(name)
    {}

    void ReindeerFlyer::setSpeedInKps(const int speed) {
        _speedInKps = speed;
    }
    
    void ReindeerFlyer::setName(const std::string & name) {
        _name = name;
    }
    
    void ReindeerFlyer::setRestTimeInS(const int rest) {
        _restTimeInS = rest;
    }
    
    void ReindeerFlyer::setFlyTimeInS(const int fly) {
        _flyTimeInS = fly;
    }
    
    void ReindeerFlyer::step() {
        if(_flyTimerInS++ < _flyTimeInS) {
//            ++_flyTimerInS;
            _totalDistanceTraveledInKm += _speedInKps;
        } else if(_restTimerInS++ < _restTimeInS) {
        } else {
            _restTimerInS = 0;
            _flyTimerInS = 1;
            _totalDistanceTraveledInKm += _speedInKps;
        }
        ++_currentTimeStepInS;
    }
    
    void ReindeerFlyer::step(int numOfSeconds) {
        for(int i = 0; i < numOfSeconds; ++i) {
            this->step();
        }
    }
    
    int ReindeerFlyer::distance() const {
        return _totalDistanceTraveledInKm;
    }
    
    std::string ReindeerFlyer::name() const {
        return _name;
    }
    
    void ReindeerFlyer::reset() {
        _totalDistanceTraveledInKm = 0;
        _currentTimeStepInS = 0;
        _flyTimerInS = 0;
        _restTimerInS = 0;
    }
#else
    ReindeerFlyer::ReindeerFlyer(const int speed, const int flyTime, const int restTime, const std::string& name) : LinearTraveler<int>(name,1,0,speed,0,flyTime,restTime)
    {
        
    }
    int ReindeerFlyer::distance() const {
        return position();
    }
#endif
    std::vector<ReindeerFlyer> ReadInReindeer(const std::vector<std::string>& input) {
        vector<ReindeerFlyer> deer{};
        for(const auto& line : input) {
            auto l = parseLineForWords(line);
            if(l.size() != 15) {
                cout << "ERROR: Parsing " << line << endl;
            } else {
                deer.push_back(ReindeerFlyer{stoi(l[3]),stoi(l[6]),stoi(l[13]),l[0]});
            }
        }
        return deer;
    }
}

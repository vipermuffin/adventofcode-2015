
//#include Day02.h
//#include "AoCUtils.hpp"
#include <string>
#include <regex>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;
namespace AocDay02 {
	static const std::string InputFileName = "Day02.txt";
	std::string solvea() {
        ifstream inputFile{InputFileName};
        regex re{"(\\d+)x(\\d+)x(\\d+)"};
        string line;
        long area = 0;
        while(std::getline(inputFile,line)) {
            try {
                sregex_iterator next{line.begin(),line.end(),re};
                sregex_iterator end;
                
                while(next != end) {
                    smatch match = *next;
                    int l = stoi(match[1]);
                    int w = stoi(match[2]);
                    int h = stoi(match[3]);
                    vector<int> sides{l*w,w*h,h*l};
                    area += 2*sides[0]+2*sides[1]+2*sides[2]+*std::min_element(sides.begin(), sides.end());
                    next++;
                }
            }
            catch (regex_error& e) {
               return e.what();
            }
        }
        return std::to_string(area);
	}

	std::string solveb() {
        ifstream inputFile{InputFileName};
        regex re{"(\\d+)x(\\d+)x(\\d+)"};
        string line;
        long length = 0;
        while(std::getline(inputFile,line)) {
            try {
                sregex_iterator next{line.begin(),line.end(),re};
                sregex_iterator end;
                
                while(next != end) {
                    smatch match = *next;
                    vector<int> sides{};
                    sides.push_back(stoi(match[1]));
                    sides.push_back(stoi(match[2]));
                    sides.push_back(stoi(match[3]));
                    std::sort(sides.begin(), sides.end());
                    
                    length += 2*sides[0]+2*sides[1];
                    length += std::accumulate(sides.begin(),sides.end(), 1, std::multiplies<int>());
                    next++;
                }
            }
            catch (regex_error& e) {
                return e.what();
            }
        }
        return std::to_string(length);
	}

}

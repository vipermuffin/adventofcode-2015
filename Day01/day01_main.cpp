
#include <iostream>
#include <fstream>
#include <vector>

static const std::string FILE_NAME = "2015_input_01.txt";

std::string solvea();
std::string solveb();

using namespace std;

int main(int argc, char *argv[]) {

	cout << "Day 1a: " << solvea() << std::endl;
	cout << "Day 1b: " << solveb() << std::endl;
	return 0;
}

string solvea() {
	int count = 0;
	
	ifstream file{FILE_NAME};
	char c;
	while(file >> c) {
		switch(c) {
			case '(':
				count++;
				break;
			case ')':
				count--;
				break;
			default:
				break;	
		}
	}
	return std::to_string(count);
}

string solveb() {
	int count = 0;
	int position = 1;
	
	ifstream file{FILE_NAME};
	char c;
	while(file >> c) {
		switch(c) {
			case '(':
				count++;
				break;
			case ')':
				count--;
				break;
			default:
				break;	
		}
		if(count < 0) {
			return std::to_string(position);
		}
		position++;
	}
	return string();
}

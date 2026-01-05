#pragma once
/*
Problem 22
Using P22.txt, a 46K text file containing over five-thousand first names, begin by sorting it
into alphabetical order. Then working out the alphabetical value for each name, multiply this 
value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth
3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 x 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> fileread(); 

long long Problem() {
    std::vector<std::string> names = fileread();
    
    long long sum = 0;
    long long nameValue;
    for (int i = 0; i < names.size(); i++) {
        nameValue = 0;
        for (char c : names[i]) {
            nameValue += c - 'A' + 1;
        }
        nameValue *= (i + 1);
        sum += nameValue;
    }

	return sum;
}

std::vector<std::string> fileread() {
    std::ifstream file("input/P22.txt");
    std::vector<std::string> names;

    if (!file) {
        std::cerr << "Failed to open file\n";
        return names;
    }

    std::string line;
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;

        while (std::getline(ss, name, ',')) {
            // Remove quotes
            if (!name.empty() && name.front() == '"') name.erase(0, 1);
            if (!name.empty() && name.back() == '"') name.pop_back();
            names.push_back(name);
        }
    }

    std::sort(names.begin(), names.end());
    return names;
}

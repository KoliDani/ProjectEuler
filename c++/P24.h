#pragma once
/*
Problem 24
A permutation is an ordered arrangement of objects.
For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations
are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations
of 0, 1 and 2 are:
012   021   102   120   201   210
What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

#include <vector>;
#include <algorithm>

int Problem() {
    std::vector<char> characters = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    std::sort(characters.begin(), characters.end());

    int limit = 1000000;
    int counter = 0;
    do {
        counter++;
        if (counter == limit) {
            for (char c : characters)
                std::cout << c;
            std::cout << '\n';
        }
    } while (std::next_permutation(characters.begin(), characters.end()));
	
	return 0;
}
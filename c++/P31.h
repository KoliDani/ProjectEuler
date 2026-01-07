#pragma once
/*
Problem 31
In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/

#include <vector>;

long long Problem() {
	int max = 200;
	std::vector<int> coins = { 1,2,5,10,20,50,100,200 };
	std::vector<long long> combinations(++max, 0);
	combinations[0] = 1;

	for (int c : coins) {
		for (int i = c; i < max; i++) {
			combinations[i] += combinations[i - c];
		}
	}

	return combinations[--max];
}
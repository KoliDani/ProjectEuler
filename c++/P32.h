#pragma once
/*
Problem 32
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once;
for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 x 186 = 7254, containing multiplicand, multiplier,
and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 
1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

std::vector<long long> getAllPandigital(int n);
void addPandigal(long long n, std::unordered_set<long long>& usedProducts);
long long separate(const std::vector<int>& digits, int s, int e);
std::vector<int> num2vector(long long n);

long long Problem() {
	long long sum = 0;
	std::vector<long long> possibilities = getAllPandigital(9);
	std::unordered_set<long long> usedProducts;

	for (int i = 0; i < possibilities.size(); i++) {
		addPandigal(possibilities[i], usedProducts);
	}

	for (long long p : usedProducts) {
		sum += p;
	}

	return sum;
}

std::vector<long long> getAllPandigital(int nrDigits) {
	std::vector<long long> nums;
	std::vector<int> digits(nrDigits, 0);
	for (int i = 0; i < nrDigits; i++) {
		digits[i] = i + 1;
	}

	long long n;
	do {
		n = 0;
		for (int x : digits) {
			n = n * 10 + x;
		}
		nums.push_back(n);
	} while (std::next_permutation(digits.begin(), digits.end()));

	return nums;
}

void addPandigal(long long n, std::unordered_set<long long>& usedProducts) {

	/*
		e.g.: num = {9,8,7,6,5,4,3,2,1}

		num[0] * num[1] = num[2...8]			// 1 - 1 - 7	-> don't need to check: 9 x 8 = 81 

		num[0...1] * num[2] = num[3...8]		// 2 - 1 - 6	-> don't need to check: 98 x 7 = 686
		num[0] * num[1...2] = num[3...8]		// 1 - 2 - 6	-> don't need to check: 9 x 87 = 783

		num[0...2] * num[3] = num[4...8]		// 3 - 1 - 5	-> don't need to check: 987 x 6 = 5922
		num[0] * num[1...3] = num[4...8]		// 1 - 3 - 5	-> don't need to check: 9 x 876 = 7884

		num[0...3] * num[4] = num[5...8]		// 4 - 1 - 4	-> NEEDED to be checked
		num[0] * num[1...4] = num[5...8]		// 1 - 4 - 4	-> NEEDED to be checked

		num[0...2] * num[3...4] = num[5...8]	// 3 - 2 - 4	-> 987 x 65 = 64155 NEEDED to be checked
		num[0...1] * num[2...4] = num[5...8]	// 2 - 3 - 4	-> 98 x 765 = 74970 NEEDED to be checked
	*/
	
	std::vector<int> digits = num2vector(n);
	long long a = separate(digits, 0, 3);
	long long b = separate(digits, 4, 4);
	long long c = separate(digits, 5, 8);

	if (a * b == c) {
		usedProducts.insert(c);
		return;
	}

	a = separate(digits, 0, 0);
	b = separate(digits, 1, 4);
	c = separate(digits, 5, 8);

	if (a * b == c) {
		usedProducts.insert(c);
		return;
	}

	a = separate(digits, 0, 2);
	b = separate(digits, 3, 4);
	c = separate(digits, 5, 8);

	if (a * b == c) {
		usedProducts.insert(c);
		return;
	}

	a = separate(digits, 0, 1);
	b = separate(digits, 2, 4);
	c = separate(digits, 5, 8);

	if (a * b == c) {
		usedProducts.insert(c);
		return;
	}
}

long long separate(const std::vector<int>& digits, int s, int e) {
	long long num = 0;
	for (int i = s; i <= e; i++) {
		num = num * 10 + digits[i];
	}
	return num;
}

std::vector<int> num2vector(long long n) {
	std::vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	return digits;
}
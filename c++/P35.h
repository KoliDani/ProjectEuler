#pragma once
/*
Problem 35
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 1,3,5,7,11,13,17,31,37,71,73,79 and 97.

How many circular primes are there below one million?
*/

#include <vector>;
#include <algorithm>;

bool isPrime(long long n);
std::vector<int> num2vector(long long n);
long long vector2num(const std::vector<int>& n);
bool isCircularPrime(long long n);

long long Problem() {
	long long limit = 1000000;
	long long counter = 0;

	for (long long i = 2; i < limit; i++) {
		if (isCircularPrime(i)) {
			counter++;
		}
	}

	return counter;
}

bool isPrime(long long n) {
	if (n < 2) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (long long i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}

std::vector<int> num2vector(long long n) {
	std::vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	std::reverse(digits.begin(), digits.end());
	return digits;
}

long long vector2num(const std::vector<int>& n) {
	long long result = 0;
	for (int i = 0; i < n.size(); i++) {
		result = result * 10 + n[i];
	}
	return result;
}

bool isCircularPrime(long long n) {
	if (!isPrime(n)) {
		return false;
	}

	std::vector<int> digits = num2vector(n);
	for (int i = 0; i < digits.size(); i++) {
		std::rotate(digits.begin(), digits.begin() + 1, digits.end());
		if (!isPrime(vector2num(digits))) {
			return false;
		}
	} 

	return true;
}
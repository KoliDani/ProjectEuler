#pragma once
/*
Problem 37
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits
from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#include <vector>;

bool isPrime(long long n);
std::vector<int> num2vector(long long n);
long long vector2num(const std::vector<int> n, bool direction, int shift);
bool isTruncatablePrime(long long n);

long long Problem() {
	long long sum = 0;
	int counter = 11;
	long long n = 9;

	while (counter > 0) {
		if (isTruncatablePrime(n)) {
			sum += n;
			counter--;
		}
		n += 2;
	}

	return sum;
}

bool isTruncatablePrime(long long n) {
	if (!isPrime(n)) {
		return false;
	}

	std::vector<int> digits = num2vector(n);
	for (int d : digits) {
		if (d == 0) {
			return false;
		}
	}

	long long t;
	for (int i = 1; i < digits.size(); i++) {
		t = vector2num(digits, false, i);
		if (!isPrime(t)) {
			return false;
		}

		t = vector2num(digits, true, i);
		if (!isPrime(t)) {
			return false;
		}
	}

	return true;
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

long long vector2num(std::vector<int> n, bool direction, int shift) {
	long long result = 0;

	if (direction) {
		std::reverse(n.begin(), n.end());
	}
	for (int i = shift; i < n.size(); i++) {
		result = result * 10 + n[i];
	}
	if (direction) {
		std::vector<int> tmp = num2vector(result);
		std::reverse(tmp.begin(), tmp.end());
		result = vector2num(tmp, false, 0);
	}


	return result;
}
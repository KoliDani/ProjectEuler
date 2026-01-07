#pragma once
/*
Problem 30
Surprisingly there are only three numbers that can be written as
the sum of fourth powers of their digits:
1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.
The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#include <vector>;
#include <cmath>;

std::vector<int> num2vector(long long n);
bool canBeWritten(long long n);

int factor = 5;

long long Problem() {
	long long limit = 999999;
	long long sum = 0;
	for (long long i = 2; i < limit; i++) {
		if (canBeWritten(i)) {
			sum += i;
		}
	}
	
	return sum;
}

std::vector<int> num2vector(long long n) {
	std::vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	return digits;
}

bool canBeWritten(long long n) {
	std::vector<int> digits = num2vector(n);
	long long sum = 0;

	for (int p : digits) {
		sum += std::pow(p, factor);
	}
	
	return n == sum;
}
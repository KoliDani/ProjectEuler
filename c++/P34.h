#pragma once
/*
Problem 34
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.
*/

#include <vector>;

long long factor(int n);
std::vector<int> num2vector(long long n);
bool isEqToDigitFactSum(long long n);

long long Problem() {
	long long limit = 99999;
	long long sum = 0;
	for (long long i = 10; i < limit; i++) {
		if (isEqToDigitFactSum(i)) {
			sum += i;
		}
	}

	return sum;
}

long long factor(int n) {
	long long result = 1;
	for (int i = 2; i <= n; ++i) {
		result *= i;
	}
	return result;
}

std::vector<int> num2vector(long long n) {
	std::vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	return digits;
}

bool isEqToDigitFactSum(long long n) {
	std::vector<int> digits = num2vector(n);
	long long sum = 0;
	for (int i = 0; i < digits.size(); i++) {
		if (sum > n) {
			return false;
		}
		sum += factor(digits[i]);
	}
	return sum == n;
}
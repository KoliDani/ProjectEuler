#pragma once
/*
Problem 36
The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

#include <vector>;

bool isPalindrome(const std::vector<int>& digits);
std::vector<int> toBinary(long long n);
std::vector<int> num2vector(long long n);

long long Problem() {
	long long limit = 1000000;
	long long sum = 0;

	for (long long i = 1; i < limit; i++) {
		if (isPalindrome(num2vector(i)) && isPalindrome(toBinary(i))) {
			sum += i;
		}
	}
	
	return sum;
}

bool isPalindrome(const std::vector<int>& digits) {
	if (digits.size() == 1) {
		return true;
	}

	int j;
	for (int i = 0; i <= digits.size() / 2; i++) {
		j = digits.size() - i - 1;

		if (digits[i] != digits[j]) {
			return false;
		}
	}
	return true;
}

std::vector<int> num2vector(long long n) {
	std::vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	return digits;
}

std::vector<int> toBinary(long long n) {
	std::vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 2);
		n /= 2;
	}
	std::reverse(digits.begin(), digits.end());
	return digits;
}
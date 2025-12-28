#pragma once
/*
Problem 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <vector>;

bool isPalindrome(long long n);
std::vector<int> num2vector(long long n);
bool checkProduct(long long n);

long long Problem() {

	long long limitUpper = (long long) (999 * 999);
	long long limitLower = (long long) (100 * 100);

	for (long long n = limitUpper; n >= limitLower; n--) {
		if (!isPalindrome(n)) {
			continue;
		}

		// Check if product of two 3 digit number
		if (checkProduct(n)) {
			return n;
		}
	}
	
	return 0;
}

bool checkProduct(long long n) {
	long long check;
	for (int i = 999; i >= 100; i--) {
		check = n / i;
		if (check < 100 || check > 999) {
			break;
		}
		if (n % i == 0 && check >= 100) {
			return true;
		}
	}
	return false;
}

bool isPalindrome(long long n) {
	std::vector<int> digits = num2vector(n);

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
	reverse(digits.begin(), digits.end());
	return digits;
}
#pragma once
/*
Problem 20
n! means n x (n - 1) x ... x 3 x 2 x 1.
For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800, and 
the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!.
*/

#include <vector>;
std::vector<int> num2vector(int n);

int Problem() {

	std::vector<int> number(1000, 0);
	std::vector<int> digits;
	int lastIndex = 1;
	
	number[0] = 1;
	for (int i = 100; i > 0; i--) {
		for (int j = 0; j < lastIndex; j++) {
			number[j] *= i;
		}

		for (int j = 0; j < lastIndex; j++) {
			if (number[j] >= 10) {
				digits = num2vector(number[j]);

				number[j] = digits[0];
				for (int k = 1; k < digits.size(); k++) {
					number[j + k] += digits[k];
				}

				lastIndex = std::max(lastIndex, int (j + digits.size()));
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < number.size(); i++) {
		sum += number[i];
	}

	return sum;
}

std::vector<int> num2vector(int n) {
	std::vector<int> digits;
	while (n > 0) {
		digits.push_back(n % 10);
		n /= 10;
	}
	return digits;
}
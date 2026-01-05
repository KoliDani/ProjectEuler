#pragma once
/*
Problem 16
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?
*/

#include <vector>;

std::vector<int> num2vector(int n);

int Problem() {
	std::vector<int> number(500, 0);
	std::vector<int> digits;
	int lastIndex = 1;
	int limit = 1000;

	number[0] = 1; // 2^0
	for (int i = 1; i <= limit; i++) {
		for (int j = 0; j < lastIndex; j++) {
			number[j] *= 2;
		}

		for (int j = 0; j < lastIndex; j++) {
			if (number[j] >= 10) {
				digits = num2vector(number[j]);

				number[j] = digits[0];
				for (int k = 1; k < digits.size(); k++) {
					number[j + k] += digits[k];
				}

				lastIndex = std::max(lastIndex, j + 2);
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
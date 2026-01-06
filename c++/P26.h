#pragma once
/*
Problem 26
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions
with denominators 2 to 10 are given:

1/2 = 0.5
1/3 = 0.(3)
1/4 = 0.25
1/5 = 0.2
1/6 = 0.1(6)
1/7 = 0.(142857)
1/8 = 0.125
1/9 = 0.(1)
1/10 = 0.1

Where 0.1(6) means 1.666666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has
a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its
decimal fraction part.
*/

#include <unordered_map>;

int nrRecurringDigits(int n);
int Problem() {
	int limit = 1000;

	int solution;
	int maxNrDigit = 0;
	int tmp;
	for (int i = 1; i < limit; i++) {
		tmp = nrRecurringDigits(i);
		if (tmp > maxNrDigit) {
			solution = i;
			maxNrDigit = tmp;
		}
	}
	
	return solution;
}

int nrRecurringDigits(int n) {
	std::unordered_map<int, int> seenRemainder;

	int index = 0;
	int remainder = 1;
	while (remainder != 0) {
		if (seenRemainder.count(remainder)) {
			int pos = seenRemainder[remainder];
			return index - pos;
		}

		seenRemainder[remainder] = index++;
		remainder = remainder % n * 10;
	}

	return 0;
}
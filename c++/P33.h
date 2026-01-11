#pragma once
/*
Problem 33
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that
49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

#include <vector>;

constexpr double EPS = 2E-14;
void simplify(int& a, int& b);
int gcd(int a, int b);

long long Problem() {

	/*
	1 -> 1x / y1 || x1 / y1 || x1 / 1y || 1x / 1y == x/y ...
	x / y < 1 -> x < y
	*/

	std::vector<std::vector<int>> possibilities;
	std::vector<std::vector<int>> solu;
	std::vector<int> digits(2,0);
	for (int i = 1; i < 9; i++) {
		for (int j = i + 1; j < 10; j++) {
			digits.clear();
			digits.push_back(i);
			digits.push_back(j);
			possibilities.push_back(digits);
		}
	}

	double frac, test;
	int a1, b1, a2, b2;
	for (int i = 0; i < possibilities.size(); i++) {
		a1 = possibilities[i][0];
		b1 = possibilities[i][1];

		frac = (double) a1/ (double) b1;
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {

				a2 = j + a1 * 10;
				b2 = b1 + k * 10;

				test = (double) a2 / (double) b2;
				if (std::abs(test - frac) <= EPS) {
					if (a1 == b1 || j == k) {
						solu.push_back(possibilities[i]);
					}
				}
			}
		}
	}

	int numer = 1;
	int denom = 1;

	for (int i = 0; i < solu.size(); i++) {
		numer *= solu[i][0];
		denom *= solu[i][1];
	}

	simplify(numer, denom);
	return denom;
}

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void simplify(int& a, int& b) {
	int g = gcd(a, b);
	a /= g;
	b /= g;
}
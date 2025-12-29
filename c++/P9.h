#pragma once
/*
Problem 9
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

long long Problem() {
	int sum = 1000;

	// Since a < b < c
	long long limit = (long long) sum * 2/5;

	long long a = 1, b = a + 1, c = sum - (a+b);
	long long sqrSum, sqrC;
	while (a < limit) {

		// Precheck if a could reach the expected limit
		c = sum - (a + limit);
		if (limit * limit + a * a < c * c) {
			a++;
			continue;
		}

		while (b < limit) {
			c = sum - (a + b);
			sqrSum = a * a + b * b;
			sqrC = c * c;

			// Overshoot of the Pythagorean
			if (sqrSum > sqrC) {
				break;
			}

			if (sqrSum == sqrC) {
				return a * b * c;
			}

			b++;
		}
		a++;
		b = a + 1;
	}

	return 0;
}
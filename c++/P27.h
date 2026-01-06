#pragma once
/*
Problem 27
Euler discovered the remarkable quadratic formula:
n^2 + n + 41
It turns out that the formula will produce 40 primes for the consecutive integer values 
0 <= n <= 39. However, when n=40, 40^2 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when
n = 41, 41^2 + 41 + 41 is clearly divisible by 41.

The incredible formula n^2 - 79n + 1601 was discovered, which produces 80 primes for the
consecutive values 0 <= n <= 79. The product of the coefficients, -79 and 1601, is -126479.

Considering quadratics of the form:
n^2 + an + b, where abs(a) < 1000 and abs(b) <= 1000
where abs(n) is the modulus/absolute value of n
e.g. abs(11) = 11 and abs(-4) = 4
Find the product of the coefficients, a and b, for the quadratic expression that produces 
the maximum number of primes for consecutive values of n, starting with n = 0.
*/

long long equation(int a, int b, int n);
bool isPrime(long long n);

long long Problem() {
	int aMin = -999;
	int aMax = 999;

	int bMin = -1000;
	int bMax = 1000;

	int n;
	int counter;
	int max = 0;
	long long solution;
	for (int a = aMin; a < aMax; a++) {
		for (int b = bMin; b < bMax; b++) {
			n = 0;
			counter = 0;
			while (isPrime(equation(a, b, n))) {
				n++;
				counter++;
			}

			if (counter > max) {
				max = counter;
				solution = (long long) a * (long long) b;
			}
		}
	}

	return solution;
}

long long equation(int a, int b, int n) {
	return (long long) n * (long long)n + (long long) a * (long long) n + (long long) b;
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
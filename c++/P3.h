#pragma once
/*
Problem 3
The prime factors of 13195 are 5,7,13 and 29.
What is the largest prime factor of the number 600851475143?
*/

bool isPrime(long long n);

double Problem() {
	long long number = 600851475143;
	long long n;

	for (long long div = 1; div < number; div++) {
		if (number % div != 0) {
			continue;
		}
		else {
			n = number / div;
			if (isPrime(n)) {
				return n;
			}
		}
	}

	return 0; 
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
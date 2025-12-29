#pragma once
/*
Problem 10
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

bool isPrime(long long n);

long long Problem() {

	long limit = 2000000;
	long k = 5;
	long long sum = 2 + 3;
	while (k < 2000000) {
		if (isPrime(k)) {
			sum += k;
		}
		k += 2;
	}

	return sum;
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
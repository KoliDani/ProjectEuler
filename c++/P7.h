#pragma once
/*
Problem 7
By listing the first six prime numbers: 2,3,5,7,11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
*/

bool isPrime(long long n);

long Problem() {
	int index = 10001;
	int counter = 2;

	long n = 5;
	long prime;
	while (counter < index) {
		if (isPrime(n)) {
			prime = n;
			counter++;
			n++;
		} else {
			n++;
		}
	}
	
	return prime;
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
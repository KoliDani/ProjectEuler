#pragma once
/*
Problem 5
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <vector>;

bool isPrime(int n);
std::vector<int> getPrimes(int n);
std::vector<int> getPrimeFactors(int n);

int limit = 20;

long long Problem() {

	int div = limit;
	std::vector<int> primes = getPrimes(div);
	std::vector<int> primeFactors(div);

	for (int i = div; i > 1; i--) {
		std::vector<int> tmp = getPrimeFactors(i);

		for (int j = 0; j < tmp.size(); j++) {
			primeFactors[j] = primeFactors[j] < tmp[j] ? tmp[j] : primeFactors[j];
		}
	}

	long long n = 1;
	for (int i = 0; i < primeFactors.size(); i++) {
		n *= std::pow(i, primeFactors[i]);
	}
	return n;
}

std::vector<int> getPrimes(int n) {
	std::vector<int> primes;

	primes.push_back(2);
	primes.push_back(3);

	for (int k = 5; k < n+1; k++) {
		if (isPrime(k)) {
			primes.push_back(k);
		}
	}
	return primes;
}

bool isPrime(int n) {
	if (n < 2) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}

std::vector<int> getPrimeFactors(int n) {
	std::vector<int> primeFactors(limit);
	std::vector<int> primes = getPrimes(n);

	if (primes.size() == 0) {
		return primeFactors;
	}

	int divIndex = 0;
	while (n != 1 && divIndex < primes.size()) {
		if (n % primes[divIndex] == 0) {
			primeFactors[primes[divIndex]]++;
			n /= primes[divIndex];
		} else {
			divIndex++;
		}
	}

	return primeFactors;	
}
#pragma once
/*
Problem 6
The sum of the squares of the first ten natural numbers is,
1^2 + 2^2 + ... + 10^2 = 385. 
The square of the sum of the first ten natural numbers is,
(1 + 2 + 3 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is   .
3025 - 385 = 2640
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

long long sumOfSquares(int n);
long long sumOf(int n);

long long Problem() {

	int limit = 100;
	
	long long sOfSquares = sumOfSquares(limit);
	long long sOfNumbers = sumOf(limit);
	sOfNumbers *= sOfNumbers;

	return sOfNumbers - sOfSquares;
}

long long sumOfSquares(int n) {
	long long sum = 0;
	double square;
	for (int i = 1; i < n+1; i++) {
		square = i * i;
		sum += square;
	}
	return sum;
}

long long sumOf(int n) {
	long long sum = 0;
	for (int i = 1; i < n + 1; i++) {
		sum += i;
	}
	return sum;
}
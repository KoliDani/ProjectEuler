#pragma once
/*
Problem 23
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that
28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant
if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written
as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers
greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot
be reduced any further by analysis even though it is known that the greatest number that cannot be expressed
as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <vector>;
#include <algorithm>

bool isAbundant(int n) {
    long long sum = 0;
    for (long long i = 1; i <= (n / 2); ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum > n;
}

std::vector<int> collectAbundants(int limit) {
    std::vector<int> abundants;
    for (int i = 12; i < limit; i++) {
        if (isAbundant(i)) {
            abundants.push_back(i);
        }
    }
    return abundants;
}

bool isSumOfAbundants(int n, const std::vector<int>& abundants) {
    auto it = std::lower_bound(abundants.begin(), abundants.end(), n);
    while (it != abundants.begin()) {
        --it;

        if (std::binary_search(abundants.begin(), abundants.end(), (n - *it))) {
            return true;
        }
    }

    return false;
}

long long Problem() {
	int limit = 28123;
    long long sum = 0;

    std::vector<int> abundants = collectAbundants(limit);
    for (int i = 0; i < limit; i++) {
        if (!isSumOfAbundants(i, abundants)) {
            sum += i;
        }
    }

	return sum;
}
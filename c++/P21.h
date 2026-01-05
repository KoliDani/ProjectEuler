#pragma once
/*
Problem 21
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of
a and b are called amicable numbers.

For example, the proper divisors of 220 are 1,2,4,5,10,11,20,22,44,55 and 110; therefore d(220) = 284.
The proper divisors of 284 are 1,2,4,71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#include <vector>;

int limit = 10000;

long long getSumOfDivisors(long long n) {
    long long sum = 0;
    for (long long i = 1; i <= (n/2); ++i) {
        if (n % i == 0) {
            sum += i;
        }

    }
    return sum;
}

bool isAmicable(long long a) {
    long long b = getSumOfDivisors(a);
    if (b > limit || a == b) {
        return false;
    }

    long long a2 = getSumOfDivisors(b);
    return a == a2;
}

long long Problem() {
    long long sum = 0;
    for (long long i = 3; i < limit; i++) {
        if (isAmicable(i)) {
            sum += i;
        }
    }

    return sum;
}

#pragma once
/*
Problem 28
Starting with the number  and moving to the right in a clockwise direction a 5 by 5 spiral
is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

long long Problem() {
	long long sum = 0;
	long long grid = 1001;
	int skip = 1;
	int skipCount = 0;
	int increaseSkip = 4;

	for (long long i = 1; i <= grid * grid; i++) {
		if (skipCount == 0) {
			sum += i;

			if (increaseSkip == 0) {
				increaseSkip = 4;
				skip += 2;
			}

			skipCount = skip+1;
			increaseSkip--;
		}
		
		skipCount--;
	}

	return sum;
}
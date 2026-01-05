#pragma once
/*
Problem 25
The Fibonacci sequence is defined by the recurrence relation:
	F_n = F_n-1 + F_n-2, where F_1 = 1 and  F_2 = 1.
Hence the first  terms will be:

F_1 = 1
F_2 = 1
F_3 = 2
F_4 = 3
F_5 = 5
F_6 = 8
F_7 = 13
F_8 = 21
F_9 = 34
F_10 = 55
F_11 = 89
F_12 = 144

The 12th term, F_12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#include <vector>;

void add(std::vector<int>& prev,
	std::vector<int>& curr, 
	std::vector<int>& next);

int Problem() {
	int len = 1000;
	std::vector<int> prev(len, 0);
	std::vector<int> curr(len, 0);
	std::vector<int> next(len, 0);

	prev[len - 1] = 1;
	curr[len - 1] = 1;

	int counter = 2;
	while (next[0] == 0) {
		add(prev, curr, next);
		counter++;
	}

	return counter;
}

void add(std::vector<int>& prev,
	std::vector<int>& curr,
	std::vector<int>& next) {

	int carry = 0;
	int len = prev.size();

	for (int i = len - 1; i >= 0; i--) {
		int sum = prev[i] + curr[i] + carry;
		next[i] = sum % 10;
		carry = sum / 10;
	}

	prev = curr;
	curr = next;
}


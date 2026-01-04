#pragma once
/*
Problem 15
Starting in the top left corner of a 2x2 grid, and only being able to move to
the right and down, there are exactly 6 routes to the bottom right corner.

	__		_		_				
	  |		 |_		 |		|__		|_		|
	  |		   |	 |_		   |	  |_	|__

How many such routes are there through a 20x20 grid?
*/

#include <vector>;

long long Problem() {
	int gridSize = 20;

	++gridSize;
	std::vector<std::vector<long long>> arr(gridSize, std::vector<long long>(gridSize,1));

	for (int row = 0; row < gridSize; row++) {
		for (int col = 0; col < gridSize; col++) {
			if (row == 0 || col == 0) {
				arr[row][col] = 1;
				continue;
			}

			arr[row][col] = arr[row - 1][col] + arr[row][col - 1];
		}
	}

	--gridSize;
	return arr[gridSize][gridSize];
}


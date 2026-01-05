#pragma once
/*
Problem 18
By starting at the top of the triangle below and moving to adjacent numbers on the row below,
the maximum total from top to bottom is 23.
		3
	   7 4
	  2 4 6
	 8 5 9 3
Maximum total: 3 - 7 - 4 -9
That is, 3 + 7 + 4 + 9 = 23.
Find the maximum total from top to bottom of the triangle below:
              75
             95 64
            17 47 82
           18 35 87 10
          20 04 82 47 65
         19 01 23 75 03 34
        88 02 77 73 07 63 67
       99 65 04 28 06 16 70 92
      41 41 26 56 83 40 80 70 33
     41 48 72 33 47 32 37 16 94 29
    53 71 44 65 25 43 91 52 97 51 14
   70 11 33 28 77 73 17 78 39 68 17 57
  91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>

/*
Create a tree, where we store the sum of the sums
                                                   3 - head: sum 3
                      7 - left child: sum 10               |        4 - right child: sum 7
2 - left child: sum 12       |     4 - right child: sum 14 | 4 - left child: sum 11      |   6 - right child: sum 13
8 - l: s 20 |  5 - r: s 17   |   5 - l: s 19 | 9 - r: s 23 | 5 - l: s 16 | 9 - r: s 20   |   9 - l: s 22 | 3 - r: s 16
*/
class Node
{
public:
    Node* right;
    Node* left;
    int value;
    long long sum = 0;

    explicit Node(int n)
        : left(nullptr), right(nullptr), value(n), sum(n) {}

    void addLeft(Node* child) {
        left = child;
        child->sum = std::max(child->sum, sum + child->value);
    }

    void addRight(Node* child) {
        right = child;
        child->sum = std::max(child->sum, sum + child->value);
    }

    ~Node() = default;
};

long long constructTree(Node* root, const std::vector<std::vector<int>>& triangle) {
    long long max = 0;

    std::vector<Node*> prevLevel = {root};
    for (size_t row = 1; row < triangle.size(); row++) {
        std::vector<Node*> currentLevel;

        for (size_t i = 0; i < triangle[row].size(); i++) {
            Node* node = new Node(triangle[row][i]);
            currentLevel.push_back(node);

            if (i < prevLevel.size()) {
                prevLevel[i]->addLeft(node);
            }

            if (i > 0) {
                prevLevel[i - 1]->addRight(node);
            }

            max = std::max(max, node->sum);
        }
        prevLevel = currentLevel;
    }

    return max;
}

std::vector<std::vector<int>> fileread();

int Problem() {
    std::vector<std::vector<int>> triangle = fileread();

    Node* root = new Node(triangle[0][0]);
    return constructTree(root,triangle);
}

std::vector<std::vector<int>> fileread() {
    // std::ifstream file("input/P18.txt");
    std::ifstream file("input/P67.txt");
    
    std::vector<std::vector<int>> data;
    std::string line;

    if (!file) {
        std::cerr << "Failed to open file\n";
        return data;
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<int> row;
        int value;

        while (iss >> value) {
            row.push_back(value);
        }

        data.push_back(row);
    }

    return data;
}
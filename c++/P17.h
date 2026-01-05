#pragma once
/*
Problem 17
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are
3 + 3 +5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words,
how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains
23 letters and 115 (one hundred and fifteen) contains 20 letters. 
The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <vector>;

int ones(int n);
int tens(int n);
int hundreds(int n);
int getNrLetter(int n);
std::vector<int> num2vector(int n);

int Problem() {
    int sum = 0;

    for (int i = 1; i < 1000; i++) {
        sum += getNrLetter(i);
    }

    sum += 11; // The one thousand
	return sum;
}

int getNrLetter(int n) {
    if (n < 10) {
        return ones(n);
    }
    if (n < 20) {
        return tens(n);
    }
    
    // Separate the number to hundreds, tens and ones
    std::vector<int> digits = num2vector(n);

    int add = 0;
    if (digits[1] == 0) {
        // This means, that x0x "x hundred and x"
        if (digits[0] != 0) {
            add = 3;
        }
        return ones(digits[0]) + hundreds(digits[2]) + add;
    }

    int recreated = 0;
    if (digits[1] == 1) {
        add = 3;
        // Recreate the tens
        recreated = 10 * digits[1] + digits[0];
        return hundreds(digits[2]) + getNrLetter(recreated) + add;
    }

    if (digits.size() == 2) {
        return tens(digits[1]) + ones(digits[0]);
    }

    
    if (digits.size() == 3) {
        if (digits[1] != 0 || digits[0] != 0) {
            add = 3;
        }
        return hundreds(digits[2]) + tens(digits[1]) + ones(digits[0]) + add;
    }
}


std::vector<int> num2vector(int n) {
    std::vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

int ones(int n) {
    switch (n) {
        case 1:
            return 3; // one
        case 2:
            return 3; // two
        case 3:
            return 5; // three
        case 4:
            return 4; // four
        case 5:
            return 4; // five
        case 6:
            return 3; // six
        case 7:
            return 5; // seven
        case 8:
            return 5; // eight
        case 9:
            return 4; // nine
        default:
            return 0;
    }
}

int tens(int n) {
    switch (n) {
    case 10:
        return 3; // ten
    case 11:
        return 6; // eleven
    case 12:
        return 6; // twelve
    case 13:
        return 8; // thirteen
    case 14:        
        return 8; // fourteen
    case 15: 
        return 7; // fifteen
    case 16:
        return 7; // sixteen
    case 17:
        return 9; // seventeen
    case 18:
        return 8; // eighteen
    case 19:
        return 8; // nineteen
    case 2:
        return 6; // twenty
    case 3:
        return 6; // thirty
    case 4:
        return 5; // forty
    case 5:
        return 5; // fifty
    case 6:
        return 5; // sixty
    case 7:
        return 7; // seventy
    case 8:
        return 6; // eighty
    case 9:
        return 6; // ninety
    default:
        return 0; 
    }
}

int hundreds(int n) {
    return ones(n) + 7; // hundred
}
#pragma once
/*
Problem 19
You are given the following information, but you may prefer to do some research for yourself.

*1 Jan 1900 was a Monday.
*Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
*A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/


bool isLeapYear(int n) {
	if (n % 4 != 0) {
		return false;
	}

	if (n % 100 == 0 && n % 400 != 0) {
		return false;
	}

	return true;
}

int nrSundayOn1stOfTheMonth(int year, int& day) {
	int sum = 0;

	for (int month = 1; month <= 12; month++) {
		if (month == 2) {
			// February
			if (isLeapYear(year)) {
				// nrDays = 29;
				day += 29;
			}
			else {
				// nrDays = 28;
				day += 28;
			}

			day %= 7;
			if (day == 0) {
				sum++;
			}

			continue;
		}

		if (month == 1 || month == 3 || month == 5 ||
			month == 7 || month == 8 || month == 10 ||
			month == 12) {
			// nrDays = 31;
			day += 31;
		}

		if (month == 4 || month == 6 || month == 9 || month == 11) {
			// nrDays = 30;
			day += 30;
		}

		day %= 7;
		if (day == 0) {
			sum++;
		}
	}

	return sum;
}

int Problem() {
	int year = 1900, day = 1;
	nrSundayOn1stOfTheMonth(year++, day);

	int limit = 2001;
	int sundays = 0;
	while (year < limit) {
		sundays += nrSundayOn1stOfTheMonth(year++, day);
	}

	return sundays;
}
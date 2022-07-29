#pragma once
#include <vector>
#include <iostream>
#include "Day.h"

class Date
{
public:

	int GetYear();

	int GetMontNumber();

	std::string GetMonthName();

	int GetDaysQuantity();

	int GetBeginningDayNumber();

	Day& GetDayByIndex(const int& index);

	int GetPrevMonthDaysQuantity();

	void SetYear(const int& year);

	void SetMonthNum(const int& monthNum);

	Date(const int& year, const int& month);
	Date();
	~Date();

	int GetWeekDay(int year, int month, int day);

private:
	int year = 0;
	int monthNum = 0;
	std::string monthName = "";
	std::vector<Day> days;
	int daysQuantity = 0;
	int beginningWeekDay = 0;

	void SetMonthNameByNumber();
	bool IsLeapYear();
	int GetDaysQuantity(const int& month, const int& year);
};

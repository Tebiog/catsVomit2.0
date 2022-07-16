#pragma once
#include "wx/wx.h"
#include <vector>
#include <iostream>



class Day
{
public:

	//========GetMeth========
	int GetDayNumber();

	bool IsCurrentDay();

	wxPanel* GetPanel();

	void SetWeekDayName(const int& dayNum);

	//=======Construct=======
	Day(const int& dNumber, const int& dayIndex,const bool& isCurrent);

	~Day();

	void InitVisual(wxWindow* parent);

protected:
	int dNumber = 0;
	std::string dName = "";
	bool isCurrDay = false;
	wxPanel* dayPanel = nullptr;
	//TaskList/Vector

	//========SetMeth========
	void SetDayNumber(const int& num);

	void SetCurrentDay(const bool& isCurr);
};


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

void InitCalendar(const int& month, const int& year, wxWindow* parent);
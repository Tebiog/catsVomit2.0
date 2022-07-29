#include "Date.h"

//========GetMeth========
int Date::GetYear()
{
	return year;
}

int Date::GetMontNumber()
{
	return monthNum;
}

std::string Date::GetMonthName()
{
	return monthName;
}

int Date::GetDaysQuantity()
{
	return daysQuantity;
}

int Date::GetBeginningDayNumber()
{
	return beginningWeekDay;
}

Day& Date::GetDayByIndex(const int& index)
{
	return days.at(index);
}

int Date::GetPrevMonthDaysQuantity()
{
	if (monthNum != 0 && year != 0)
	{
		if (monthNum == 1)
		{
			return GetDaysQuantity(12, year);
		}
		else
		{
			return GetDaysQuantity(monthNum - 1, year);
		}
	}
	else
	{
	}
}

//========SetMeth========
void Date::SetYear(const int& year)
{
	if (year > 1918 && year < 3001)
	{
		this->year = year;
	}
	else
	{
		//throw excep
	}
}

void Date::SetMonthNum(const int& monthNum)
{
	if (monthNum > 0 && monthNum < 13)
	{
		this->monthNum = monthNum;
	}
	else
	{
		//throw excep
	}
}

//=======Construct=======
Date::Date(const int& year, const int& month)
{
	SetYear(year);
	SetMonthNum(month);
	SetMonthNameByNumber();
	daysQuantity = GetDaysQuantity(month, year);
	beginningWeekDay = GetWeekDay(year, month, 1);

	for (int i = 1; i <= daysQuantity; i++)
	{
		//If/Elese is only for test. 
		if (i == 4)
		{
			days.push_back(Day(i, GetWeekDay(this->year, this->monthNum, i), true));
		}
		else
		{
			days.push_back(Day(i, GetWeekDay(this->year, this->monthNum, i), false));//remake
		}

		//days.push_back(Day(i, GetWeekDay(this->year, this->monthNum, i), checkIfCurrent));
	}
}

Date::Date()
{

}

Date::~Date()
{
	//delete days;
}


void Date::SetMonthNameByNumber()
{
	switch (this->monthNum)
	{
	case 1: {this->monthNum = monthNum; monthName = "January"; }
		  break;
	case 2: {this->monthNum = monthNum; monthName = "February"; }
		  break;
	case 3: {this->monthNum = monthNum; monthName = "March"; }
		  break;
	case 4: {this->monthNum = monthNum; monthName = "April"; }
		  break;
	case 5: {this->monthNum = monthNum; monthName = "May"; }
		  break;
	case 6: {this->monthNum = monthNum; monthName = "June"; }
		  break;
	case 7: {this->monthNum = monthNum; monthName = "July"; }
		  break;
	case 8: {this->monthNum = monthNum; monthName = "August"; }
		  break;
	case 9: {this->monthNum = monthNum; monthName = "September"; }
		  break;
	case 10: {this->monthNum = monthNum; monthName = "October"; }
		   break;
	case 11: {this->monthNum = monthNum; monthName = "November"; }
		   break;
	case 12: {this->monthNum = monthNum; monthName = "December"; }
		   break;
	default: {/*throw excep*/}
		   break;
	}
}

bool Date::IsLeapYear()
{
	if ((this->year % 400) == 0) return true;

	if ((this->year % 100) == 0) return false;

	if ((this->year % 4) == 0) return true;

	return false;
}

int Date::GetDaysQuantity(const int& month, const int& year)
{
	if (month > 0 && month < 13)
	{
		if (month == 2)
		{
			if (IsLeapYear())
			{
				return 29;
			}
			else
			{
				return 28;
			}
		}
		else
		{
			if (month % 2 == 0 && month != 8)//Do not need verific. if October
			{
				return 30;
			}
			else
			{
				return 31;
			}
		}
	}
	else
	{
		//Thow exception
		return -1;
	}
}

int Date::GetWeekDay(int year, int month, int day)//int year, int month, int day
{
	int weekdays[] = { 0, 1, 2, 3, 5, 6,
					  0, 1, 3, 4, 5, 6,
						 1, 2, 3, 4, 6,
					  0, 1, 2, 4, 5, 6,
					  0, 2, 3, 4, 5 };

	int shift_not_leap[] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
	int shift_leap[] = { 0, 3, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6 };

	bool is_leap = IsLeapYear();

	year -= 1;
	year %= 400;

	int century = year / 100;

	year %= 100;

	int index = (year + (4 * century)) % 28;
	int weekday = weekdays[index];

	weekday += is_leap ? shift_leap[this->monthNum - 1]
		: shift_not_leap[monthNum - 1];
	weekday += (day - 1);
	weekday %= 7;

	return weekday;
}
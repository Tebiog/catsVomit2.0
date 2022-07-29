#pragma once
#include <iostream>

class Day
{
public:

	//========GetMeth========
	int GetDayNumber();

	bool IsCurrentDay();

	//wxPanel* GetPanel();

	void SetWeekDayName(const int& dayNum);

	//=======Construct=======
	Day(const int& dNumber, const int& dayIndex, const bool& isCurrent);

	~Day();

	//void InitVisual(wxWindow* parent);

protected:
	int dNumber = 0;
	std::string dName = "";
	bool isCurrDay = false;
	//wxPanel* dayPanel = nullptr;
	//TaskList/Vector

	//========SetMeth========
	void SetDayNumber(const int& num);

	void SetCurrentDay(const bool& isCurr);
};
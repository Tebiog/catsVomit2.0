#include "Day.h"

//========GetMeth========
int Day::GetDayNumber()
{
	return dNumber;
}

bool Day::IsCurrentDay()
{
	return isCurrDay;
}

//wxPanel* Day::GetPanel()
//{
//	return dayPanel;
//}

void Day::SetWeekDayName(const int& dayNum)
{
	switch (dayNum)
	{
	case 0: {dName = "Monday"; }
		  break;
	case 1: {dName = "Tuesday"; }
		  break;
	case 2: {dName = "Wedsday"; }
		  break;
	case 3: {dName = "Thursday"; }
		  break;
	case 4: {dName = "Friday"; }
		  break;
	case 5: {dName = "Saturday"; }
		  break;
	case 6: {dName = "Sunday"; }
		  break;
	default: {/*throw except*/}
		   break;
	}
}

//=======Construct=======
Day::Day(const int& dNumber, const int& dayIndex, const bool& isCurrent)
{
	SetDayNumber(dNumber);
	SetWeekDayName(dayIndex);
	SetCurrentDay(isCurrent);
}

Day::~Day()
{
}

//Other
//void Day::InitVisual(wxWindow* parent)
//{
//	wxColour backGroundColour;
//	wxColour foreGroundColour;
//	if (isCurrDay == false)
//	{
//		backGroundColour = wxColour(48, 104, 68);
//		foreGroundColour = parent->GetBackgroundColour();
//	}
//	else
//	{
//		backGroundColour = wxColour(62, 185, 106);
//		foreGroundColour = wxColor(30, 69, 62);
//	}
//
//	dayPanel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(74, 37));//wxSize(74, 37)//(parent->GetSize() / 10)//id = dNum
//	dayPanel->SetBackgroundColour(backGroundColour);
//	wxStaticText* dayNum = new wxStaticText(dayPanel, wxID_ANY, std::to_string(dNumber), wxDefaultPosition, wxDefaultSize);
//	dayNum->SetForegroundColour(foreGroundColour);
//	wxStaticText* dayName = new wxStaticText(dayPanel, wxID_ANY, dName, wxDefaultPosition, wxDefaultSize);
//	dayName->SetForegroundColour(foreGroundColour);
//}

//========SetMeth========
void Day::SetDayNumber(const int& num)
{
	dNumber = num;
}

void Day::SetCurrentDay(const bool& isCurr)
{
	isCurrDay = isCurr;
}
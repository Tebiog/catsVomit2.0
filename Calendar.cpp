#include "Calendar.h"

void InitCalendar(const int& month, const int& year, wxWindow* parent)
{
	/*int daysQuan; = GetDaysQuantity(month, year);
	wxGridSizer* daysSizer = new wxGridSizer(daysQuan / 7 + 1, 7, wxSize(3, 3));

	for (int i = 1; i <= GetDaysQuantity(3, year); i++)
	{
		new Day(i, parent);
		if (i > 1 && i < 8)
		{
			daysSizer->Add(parent->GetWindowChild(i), 1, wxEXPAND | wxTOP, 3);
		}
		else if (i == 1)
		{
			daysSizer->Add(parent->GetWindowChild(i), 1, wxEXPAND | wxTOP | wxLEFT, 3);
		}
		else if (i == 8 || i == 15 || i == 22 || i == 29)
		{
			daysSizer->Add(parent->GetWindowChild(i), 1, wxEXPAND | wxLEFT, 3);
		}
		else
		{
			daysSizer->Add(parent->GetWindowChild(i), 1, wxEXPAND);
		}
	}
	parent->SetSizerAndFit(daysSizer);*/


	Date* date = new Date(year, month);
	wxGridSizer* daysSizer = new wxGridSizer(date->GetDaysQuantity() / 7 + 1, 7, wxSize(3, 3));
	wxPanel* nPanel;
	//InitiCurrDaysOfTheMonth
	for (int i = 0; i < date->GetDaysQuantity(); i++)
	{
		date->GetDayByIndex(i).InitVisual(parent);
		daysSizer->Add(date->GetDayByIndex(i).GetPanel(), 1, wxEXPAND);
	}
	parent->SetSizerAndFit(daysSizer);

}

Calendar::Calendar(wxWindow* parentWindow, int id = wxID_ANY, wxPoint posit = wxDefaultPosition, wxSize size=wxDefaultSize) : wxPanel(parentWindow, id, posit, size)
{
	//Date currDate = Date(2024, 2);
}

Calendar::~Calendar()
{}
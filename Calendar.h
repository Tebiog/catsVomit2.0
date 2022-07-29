#pragma once
#include "wx/wx.h"
#include "Date.h"
#include "dPanel.h"
#include <vector>

class Calendar : public wxPanel
{
public:

	//void InitCalendar(const int& month, const int& year, wxWindow* parent);

	Calendar(wxWindow* parentWindow, int id = wxID_ANY, wxPoint posit = wxDefaultPosition, wxSize size = wxDefaultSize);
	~Calendar();

private:
	std::vector<dPanel> panels;
};

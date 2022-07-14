#include "cMain.h"
//#include <wx/listctrl.h>
#include <wx/srchctrl.h>

namespace utilityTools
{

	class ScrolledWidgetsPane : public wxScrolledWindow
	{
	public:
		ScrolledWidgetsPane(wxWindow* parent, wxWindowID id) : wxScrolledWindow(parent, id)
		{
			// the sizer will take care of determining the needed scroll size
			// (if you don't use sizers you will need to manually set the viewport size)
			wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

			// add a series of widgets
			/*for (int w = 1; w <= 120; w++)
			{
				wxButton* b = new wxButton(this, wxID_ANY, wxString::Format(wxT("Button %i"), w));
				sizer->Add(b, 0, wxALL, 3);
			}*/

			this->SetSizer(sizer);

			// this part makes the scrollbars show up
			this->FitInside(); // ask the sizer about the needed size
			this->SetScrollRate(5, 5);
			
		}

	};

	class Day
	{
	public:

		int GetDate()
		{
			return date;
		}

		void SetDate(int date)
		{
			this->date = date;
		}

		bool GetIfCurrDay()
		{
			return currDay;
		}

		void SetDate(bool ifCurrDay)
		{
			currDay = ifCurrDay;
		}

		Day(int date, wxWindow* parent)
		{
			wxPanel* dayPanel = new wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(74, 37));
			SetDate(date);
			//checkIfCurrDay
		}
	private:
		int date = 0;
		bool currDay = false;
		//TasksList
	};

	int GetDaysQuantity(const int& month,const int& year)//FillWithDays(int month, int year, wxObject* parent)
	{
		if (month > 0 && month < 13)
		{
			if (month == 2)
			{
				if (year % 4 == 0)
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

	void FillWithDays(const int& month, const int& year, wxObject* parent)
	{
	}
}

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Planner")//Параметры базового/родительского окна - окно родитель; id онка(wxID_ANY - любой id); заголовок окна.
{
	//=====================Window_Settings=====================
	this->SetMinSize(wxSize(740, 440));
	//this->SetMaxSize(wxSize(740, 440));
	this->SetBackgroundColour(wxColour(48, 104, 68));//24, 44, 37
	//=========================================================


	//>>===================Calendar_Container====================
	wxPanel* listPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(740, 440));


	//=====================Title_Container=====================
	wxPanel* datesTitlePanel = new wxPanel(listPanel, wxID_ANY, wxDefaultPosition, wxSize(740, 40));
	datesTitlePanel->SetBackgroundColour(wxColour(24, 44, 37));

	wxPanel* monthAndYearSwitcher = new wxPanel(datesTitlePanel, wxID_ANY, wxDefaultPosition, wxDefaultSize);

	wxStaticText* monthAndYear = new wxStaticText(monthAndYearSwitcher, wxID_ANY, "July, 2022", wxDefaultPosition);
	monthAndYear->SetForegroundColour(wxColour(69, 91, 85));
	monthAndYear->SetFont(wxFont(17, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString, wxFONTENCODING_DEFAULT));
	//monthAndYear->SetBackgroundColour(wxColour("orange"));

	wxButton* nextMonth = new wxButton(monthAndYearSwitcher, wxID_ANY, ">", wxDefaultPosition, wxSize(20, 20), wxBORDER_NONE);
	nextMonth->SetFont(wxFont(17, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString, wxFONTENCODING_DEFAULT));
	nextMonth->SetForegroundColour(wxColour(48, 104, 68));
	nextMonth->SetBackgroundColour(wxColour(24, 44, 37));

	wxButton* prevMonth = new wxButton(monthAndYearSwitcher, wxID_ANY, "<", wxDefaultPosition, wxSize(20, 20), wxBORDER_NONE);
	prevMonth->SetFont(wxFont(17, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString, wxFONTENCODING_DEFAULT));
	prevMonth->SetForegroundColour(wxColour(48, 104, 68));
	prevMonth->SetBackgroundColour(wxColour(24, 44, 37));

	wxBoxSizer* switcherSizer = new wxBoxSizer(wxHORIZONTAL);
	switcherSizer->Add(prevMonth, 0, wxEXPAND | wxTOP, 5);
	switcherSizer->Add(monthAndYear, 1, wxEXPAND | wxTOP, 5);
	switcherSizer->Add(nextMonth, 0, wxEXPAND | wxTOP, 5);
	monthAndYearSwitcher->SetSizerAndFit(switcherSizer);
	//=========================================================


	//====================All_Dates_Container==================
	//wxPanel* datesPanel = new wxPanel(listPanel, wxID_ANY, wxDefaultPosition, wxSize(740, 370));
	//datesPanel->SetBackgroundColour(wxColour(24, 44, 37));

	utilityTools::ScrolledWidgetsPane* datesPanel = new utilityTools::ScrolledWidgetsPane(listPanel, wxID_ANY);
	datesPanel->SetBackgroundColour(wxColour(24, 44, 37));

	//FillMethodWithDays();

	//=========================================================
	 
	 
	//>>=========================================================


	//>>===================Controls_Container===================
	wxPanel* controlsPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(740, 30));//140, 440
	controlsPanel->SetBackgroundColour(wxColor(30, 69, 62));//"orange"

	wxButton* view = new wxButton(controlsPanel, wxID_ANY, "VIEW", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
	view->SetFont(wxFont(10, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString, wxFONTENCODING_DEFAULT));
	view->SetForegroundColour(wxColour(controlsPanel->GetBackgroundColour()));
	view->SetBackgroundColour(wxColour(62, 185, 106));//"orange"//62, 185, 106


	wxStaticText* tsksQuan = new wxStaticText(controlsPanel, wxID_ANY, "Task(s): ", wxDefaultPosition, wxDefaultSize);
	tsksQuan->SetForegroundColour(wxColour(48, 104, 68));
	tsksQuan->SetFont(wxFont(13, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString, wxFONTENCODING_DEFAULT));
	//tsksQuan->Show(false);


	wxSearchCtrl* searchTasks = new wxSearchCtrl(controlsPanel, wxID_ANY);
	searchTasks->SetBackgroundColour(controlsPanel->GetBackgroundColour());
	searchTasks->SetForegroundColour(wxColour(24, 44, 37));
	searchTasks->SetFont(wxFont(10, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString, wxFONTENCODING_DEFAULT));
	searchTasks->SetWindowStyle(wxBORDER_NONE);

	wxBoxSizer* contorlsSizer = new wxBoxSizer(wxHORIZONTAL);
	contorlsSizer->Add(searchTasks, 0, wxEXPAND);
	contorlsSizer->Add(tsksQuan, 1, wxEXPAND);
	contorlsSizer->Add(view, 0, wxEXPAND);
	controlsPanel->SetSizerAndFit(contorlsSizer);
	//>>=========================================================


	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	mainSizer->Add(listPanel, 1, wxEXPAND);
	mainSizer->Add(controlsPanel, 0, wxEXPAND);
	this->SetSizerAndFit(mainSizer);

	controlsPanel->SetSize(wxSize(0, 0));

	wxBoxSizer* listSizer = new wxBoxSizer(wxVERTICAL);
	listSizer->Add(datesTitlePanel, 0, wxEXPAND);
	listSizer->Add(datesPanel, 1, wxEXPAND | wxTOP, 1);
	listPanel->SetSizerAndFit(listSizer);

}

cMain::~cMain()
{
}
#include "cMain.h"
#include <wx/srchctrl.h>
#include "Calendar.h"

	/*class Day
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

		wxPanel* GetPanel()
		{
			return dayPanel;
		}


		Day(int date, wxWindow* parent)
		{
			dayPanel = new wxPanel(parent, date, wxDefaultPosition, wxSize(74, 37));//wxSize(74, 37)//(parent->GetSize() / 10)
			dayPanel->SetBackgroundColour(wxColour(48, 104, 68));
			wxStaticText* dayNum = new wxStaticText(dayPanel, wxID_ANY, std::to_string(date), wxDefaultPosition, wxDefaultSize);
			dayNum->SetForegroundColour(parent->GetBackgroundColour());
			SetDate(date);

			//checkIfCurrDay
		}

		~Day()
		{}
	private:
		int date = 0;
		//std::string tDate = "";
		//TasksList
		bool currDay = false;
		wxPanel* dayPanel = nullptr;
	};*/

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
	wxPanel* datesPanel = new wxPanel(listPanel, wxID_ANY, wxDefaultPosition, wxSize(740, 370));
	datesPanel->SetBackgroundColour(wxColour(24, 44, 37));


	InitCalendar(2, 2024, datesPanel);
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
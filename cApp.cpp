#include "cApp.h"

wxIMPLEMENT_APP(cApp);//Макрос для создания точки входа в программу(win main - аналог "main" в WX).


cApp::cApp()
{
}

cApp::~cApp()
{
}

bool cApp::OnInit()//Инициализация/старт mainFram'a.
{
	_mFrame = new cMain();
	_mFrame->Show();

	return true;
}
